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

#ifndef SERVER_NATIVE_FUNCTION_MANAGER_H_
#define SERVER_NATIVE_FUNCTION_MANAGER_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "server/native_function.h"
#include "server/sdk/amx.h"

// The native function manager has two primary responsibilities: it manages the native functions
// provided by the Las Venturas Playground plugin, and it curates the list of natives we expect
// to be available from the SA-MP server and the addresses we know their implementation to be at.
class NativeFunctionManager {
 public:
  NativeFunctionManager();
  ~NativeFunctionManager();

  // Provides a native called |name| to each of the AMX files which will be loaded in the server.
  // This method must be called before any AMX file has been registered.
  void ProvideNativeFunction(const std::string& name, const NativeFunction& implementation);

  // Invokes a function called |name| having |signature| as its signature.
  int Invoke(const char* name, const char* format, ...);

  // Must be called when a new AMX is introduced to the server. All provided native functions will
  // be registered. If there are unresolved external natives, they will be ran against the new AMX
  // in an attempt to find their implementation address.
  void DidLoadScript(AMX* amx);

 private:
  std::vector<AMX_NATIVE_INFO> provided_natives_;
  bool has_provided_natives_;
};

#endif  // SERVER_NATIVE_FUNCTION_MANAGER_H_
