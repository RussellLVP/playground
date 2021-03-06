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

#include "server/bindings/time.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int gettime(int* hour, int* minute, int* second) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("gettime", "III", hour, minute, second);
}

int getdate(int* year, int* month, int* day) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("getdate", "III", year, month, day);
}

int tickcount(int* granularity) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("tickcount", "I", granularity);
}

}  // namespace samp
