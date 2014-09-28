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

#ifndef SERVER_NATIVE_CALLBACK_INTERCEPTOR_
#define SERVER_NATIVE_CALLBACK_INTERCEPTOR_

#include <unordered_map>

#include "server/sdk/amx.h"
#include "server/server_interface.h"

class NativeArguments;

// The native callback interceptor will hook into the amx_FindPublic and amx_Exec calls, and monitor
// for each public function being invoked on the primary AMX call. We then dispatch those calls in
// the plugin directly, meaning we don't have to pipe through every callback call through Pawn.
class NativeCallbackInterceptor {
 public:
  explicit NativeCallbackInterceptor(void* amx_exports);
  ~NativeCallbackInterceptor();

  // Registers the RegisterGamemodeAMX native with the ServerInterface. This cannot be done as part
  // of the constructor as it's sketchy to rely on ServerInterfaceImpl's initialization order.
  void RegisterNatives(ServerInterface* server_interface);

 private:
  // native RegisterGamemodeAMX();
  // Registers the callee's script as being the gamemode, causing all events fired on it to be
  // intercepted and dispatched in the C++ plugin before sending it back to Pawn. A map will
  // be filled with the names of all public functions exposed in this script.
  int RegisterGamemodeAMX(NativeArguments& arguments);

  AMX* primary_script_;

  std::unordered_map<int, std::string> public_functions_;
  std::unordered_map<std::string, int> public_functions_by_name_;
};

#endif  // SERVER_NATIVE_CALLBACK_INTERCEPTOR_
