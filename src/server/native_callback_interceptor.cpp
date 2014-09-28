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

#include "server/native_callback_interceptor.h"

#include "base/logging.h"
#include "base/version.h"
#include "server/native_arguments.h"
#include "server/sdk/plugincommon.h"

using namespace std::placeholders;

namespace {

typedef int AMXAPI (*amx_FindPublic_t)(AMX *amx, const char *funcname, int *index);
typedef int AMXAPI (*amx_Exec_t)(AMX *amx, cell *retval, int index);

}  // namespace

NativeCallbackInterceptor::NativeCallbackInterceptor(void* amx_exports) {
  amx_FindPublic_t amx_FindPublic = static_cast<amx_FindPublic_t*>(amx_exports)[PLUGIN_AMX_EXPORT_Exec];
  amx_Exec_t amx_Exec = static_cast<amx_Exec_t*>(amx_exports)[15];

  // TODO(Russell): Install the amx_FindPublic and amx_Exec hooks.
}

NativeCallbackInterceptor::~NativeCallbackInterceptor() {
  // TODO(Russell): Uninstall the amx_FindPublic and amx_Exec hooks.
}

void NativeCallbackInterceptor::RegisterNatives(ServerInterface* server_interface) {
  server_interface->ProvideNativeFunction("RegisterGamemodeAMX",
      std::bind(&NativeCallbackInterceptor::RegisterGamemodeAMX, this, _1));
}

int NativeCallbackInterceptor::RegisterGamemodeAMX(NativeArguments& arguments) {
  primary_script_ = arguments.amx();

  int public_function_count = 0;
  amx_NumPublics(primary_script_, &public_function_count);

  public_functions_.clear();
  public_functions_.reserve(public_function_count);
  public_functions_by_name_.clear();
  public_functions_by_name_.reserve(public_function_count);

  char public_name[sNAMEMAX + 1];
  for (int index = 0; index < public_function_count; ++index) {
    amx_GetPublic(primary_script_, index, public_name);

    std::string name(public_name);

    public_functions_[index] = name;
    public_functions_by_name_[name] = index;
  }

  LOG(INFO) << "Registered the gamemode with " PRODUCT_NAME " (" << public_function_count << " publics).";
  return public_function_count;
}
