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

#include "server/bindings/core.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int heapspace() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("heapspace", "");
}

int funcidx(char* name) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("funcidx", "c", name);
}

int numargs() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("numargs", "");
}

int getarg(int arg, int index) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("getarg", "ii", arg, index);
}

int setarg(int arg, int index, int value) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("setarg", "iii", arg, index, value);
}

int tolower(int c) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("tolower", "i", c);
}

int toupper(int c) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("toupper", "i", c);
}

int swapchars(int c) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("swapchars", "i", c);
}

int random(int max) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("random", "i", max);
}

int min(int value1, int value2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("min", "ii", value1, value2);
}

int max(int value1, int value2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("max", "ii", value1, value2);
}

int clamp(int value, int min, int max) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("clamp", "iii", value, min, max);
}

int getproperty(int id, char* name, int value, char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("getproperty", "icic", id, name, value, string);
}

int setproperty(int id, char* name, int value, char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("setproperty", "icic", id, name, value, string);
}

int deleteproperty(int id, char* name, int value) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("deleteproperty", "ici", id, name, value);
}

int existproperty(int id, char* name, int value) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("existproperty", "ici", id, name, value);
}

}  // namespace samp
