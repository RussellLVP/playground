/**
 * Copyright (c) 2006-2014 Las Venturas Playground
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "server/native_function_manager.h"

#include <algorithm>
#include <stdarg.h>

#include "base/logging.h"
#include "server/native_arguments.h"
#include "server/sdk/amx.h"

namespace {

// The MSVC 2013 compiler fails to recognize that the compiler-generated code for the
// NativeTrampoline::BinarySelectInvoke method is not infinitely recursive, so ignore the warning.
#if defined(WINDOWS)
#pragma warning(push)
#pragma warning(disable: 4717)
#endif

// This is a massive hack for creating a trampoline between the C-style implementation signature
// required for AMX natives, and the C++11 style bound functions that will be provided by this
// plugin. While it works reliably, it requires that space for each of the callbacks is pre-
// allocated within the resulting binary.
class NativeTrampoline {
 public:
  // The absolute maximum number of trampoline functions which can be created during run-time. Any
  // function >|Size| will cause the plugin to abort.
  static const unsigned Size = 32;

  // Creates and returns a new trampoline function for |implementation|.
  static AMX_NATIVE Create(const NativeFunction& implementation) {
    CHECK(next_index_ < Size) << "No more trampoline slots are available.";

    callback_list_[next_index_] = implementation;
    return BinarySelectInvoke<0, Size - 1>(next_index_++);
  }

 private:
  // Invokes the std::function stored in |callback_list_| for index |Index|. The magic here is done
  // by a combination of the binary search in NativeTrampoline::BinarySearch, which will select the
  // appropriate Call function (the compiler will generate |Size| of them), and the anonymous
  // typename triggered by std::enable_if on the equation.
  template <size_t Index, typename = typename std::enable_if<(Index < Size)>::type>
  static cell Invoke(AMX* amx, cell* parameters) {
    DCHECK((parameters[0] % sizeof(cell)) == 0) << "Invalid parameter count in Pawn call.";

    return callback_list_[Index](NativeArguments(amx, parameters));
  }

  // Finds the appropriate Invoke<Index> function to refer to by finding |index| within the range
  // of the callback list using a binary search. This is a one-time cost of complexity O(log n) for
  // n = |Size| at the time of creating the trampoline.
  template<unsigned Min, unsigned Max>
  static AMX_NATIVE BinarySelectInvoke(const unsigned index) {
    if (Min == Max)
      return Invoke<Max>;

    unsigned const Middle = (Min + Max) / 2;
    return index <= Middle ? BinarySelectInvoke<Min, Middle>(index)
                           : BinarySelectInvoke<Middle + 1, Max>(index);
  }

  static NativeFunction callback_list_[Size];
  static unsigned next_index_;
};

// Static memory for the state of the created trampolines. We store an additional integer to avoid
// a walk over the |callback_list_| and checking for each entry's validity.
NativeFunction NativeTrampoline::callback_list_[NativeTrampoline::Size] = {};
unsigned NativeTrampoline::next_index_ = 0;

#if defined(WINDOWS)
#pragma warning(pop)
#endif

// Returns whether the native represented by |native| is named |name|. Used as a predicate.
bool AmxNativeNameEquals(const std::string& name, const AMX_NATIVE_INFO& native) {
  return name == native.name;
}

}  // namespace

// -------------------------------------------------------------------------------------------------

// Entry point for accessing native functions through the bindings. The pointer will be set in the
// constructor of NativeFunctionManager, and will be reset in the destructor.
NativeFunctionManager* g_native_function_manager = nullptr;

NativeFunctionManager::NativeFunctionManager()
    : has_provided_natives_(false) {
  CHECK(!g_native_function_manager) << "The native function manager has already been initialized.";
  g_native_function_manager = this;
}

NativeFunctionManager::~NativeFunctionManager() {
  g_native_function_manager = nullptr;
}

// -------------------------------------------------------------------------------------------------

void NativeFunctionManager::ProvideNativeFunction(const std::string& name, const NativeFunction& implementation) {
  CHECK(!has_provided_natives_) << "Native functions must be provided before any Pawn script gets loaded.";
  bool already_registered = std::find_if(provided_natives_.begin(),
                                         provided_natives_.end(),
                                         std::bind(AmxNativeNameEquals, name, std::placeholders::_1)) == provided_natives_.end();

  CHECK(!already_registered) << "Native functions may only be provided once (" << name << ").";
  
  char* native_name = (char*) calloc(sNAMEMAX + 1, 1);
  strncpy(native_name, name.c_str(), sNAMEMAX);

  AMX_NATIVE_INFO native;
  native.name = native_name;
  native.func = NativeTrampoline::Create(implementation);

  provided_natives_.push_back(native);
}

// -------------------------------------------------------------------------------------------------

int NativeFunctionManager::Invoke(const char* name, const char* format, ...) {
  AMX_NATIVE native = GetNative(name);
  if (!native) {
    LOG(ERROR) << "Unable to invoke " << name << ": function has not been registered.";
    return 0;
  }

  unsigned int parameter_count = strlen(format);

  parameters_.resize(parameter_count + 1);
  parameters_[0] = parameter_count * sizeof(cell);

  va_list arguments;
  va_start(arguments, format);

  for (unsigned int index = 0; index < parameter_count; ++index) {
    switch (format[index]) {
    case 'i': // integer
      parameters_[index + 1] = va_arg(arguments, cell);
      break;
    case 'I': // integer reference
    case 'f': // float
      {
        float value = static_cast<float>(va_arg(arguments, double));
        parameters_[index + 1] = amx_ftoc(value);
      }
      break;
    case 'F': // float reference
    case 'a': // vector<cell>
    default:
      CHECK(false) << "Unrecognized parameter type '" << format[index] << "' while invoking " << name << ".";
      break;
    }
  }

  LOG(INFO) << "Calling " << name << " with format (" << format << ").";
  int return_value = native(&mock_amx_, parameters_.data());
  LOG(INFO) << "Return value: " << return_value;

  va_end(arguments);
  return return_value;
}

// -------------------------------------------------------------------------------------------------

void NativeFunctionManager::DidLoadScript(AMX* amx) {
  if (provided_natives_.size())
    amx_Register(amx, provided_natives_.data(), -1);

  has_provided_natives_ = true;

  char native_name[sNAMEMAX + 1];

  int native_count;
  amx_NumNatives(amx, &native_count);

  AMX_HEADER* header = reinterpret_cast<AMX_HEADER*>(amx->base);
  for (int index = 0; index < native_count; ++index) {
    AMX_FUNCSTUB* function =
        reinterpret_cast<AMX_FUNCSTUB*>(amx->base + header->natives + index * header->defsize);

    amx_GetNative(amx, index, native_name);
    if (GetNative(function->name) != nullptr)
      continue;

    char* name = (char*) calloc(sNAMEMAX + 1, 1);
    strncpy(name, native_name, sNAMEMAX);

    AMX_NATIVE_INFO native;
    native.name = name;
    native.func = reinterpret_cast<AMX_NATIVE>(function->address);

    registered_natives_.push_back(native);
  }
}

// -------------------------------------------------------------------------------------------------

AMX_NATIVE NativeFunctionManager::GetNative(const char* name) const {
  // TODO(Russell): This can be optimized to perform a binary search instead.
  auto& iterator = std::find_if(registered_natives_.begin(),
                                registered_natives_.end(),
                                [name](const AMX_NATIVE_INFO& native) {
                                  return !strcmp(native.name, name);
                                });

  if (iterator == registered_natives_.end())
    return nullptr;

  return iterator->func;
}
