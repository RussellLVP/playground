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

#include <stdio.h>

#include "base/logging.h"
#include "playground/playground.h"
#include "server/sdk/plugincommon.h"
#include "server/server_interface.h"

// Global ServerInterface and Playground instances. The lifetime of these objects is controlled by
// the exported module functions, which will be called by the SA-MP server.
ServerInterface* g_server_interface = nullptr;
Playground* g_playground = nullptr;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
  return SUPPORTS_VERSION |
         SUPPORTS_AMX_NATIVES |
         SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** data) {
  CHECK(!g_server_interface && !g_playground);

  g_server_interface = ServerInterface::Create(data);
  g_playground = new Playground(g_server_interface);

  return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
  CHECK(g_playground && g_server_interface);

  delete g_playground;
  g_playground = nullptr;

  delete g_server_interface;
  g_server_interface = nullptr;
}

#include "server/bindings/samp.h"
PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
  CHECK(g_server_interface);

  g_server_interface->DidLoadScript(amx);

  LOG(INFO) << "Gravity: " << samp::GetGravity();
  samp::SetGravity(0.1);
  LOG(INFO) << "Gravity: " << samp::GetGravity();

  return 0;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
  CHECK(g_server_interface);

  g_server_interface->DidUnloadScript(amx);
  return 0;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
  CHECK(g_playground);

  g_playground->ProcessTick();
}
