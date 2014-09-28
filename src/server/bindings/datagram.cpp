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

#include "server/bindings/datagram.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int sendstring(std::string& message, std::string& destination) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("sendstring", "ss", &message, &destination);
}

int sendpacket(std::string& packet, int size, std::string& destination) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("sendpacket", "sis", &packet, size, &destination);
}

int listenport(int port) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("listenport", "i", port);
}

}  // namespace samp
