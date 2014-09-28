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

#include "server/bindings/file.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int fopen(char* name, filemode  mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fopen", "ci", name, static_cast<int>( mode));
  return * (int*) &result;
}

bool fclose(int  handle) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fclose", "i",  handle);
  return * (bool*) &result;
}

int ftemp() {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("ftemp", "");
  return * (int*) &result;
}

bool fremove(char* name) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fremove", "c", name);
  return * (bool*) &result;
}

int fwrite(int  handle, char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fwrite", "ic",  handle, string);
}

int fread(int  handle, char* string, int size, bool  pack) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fread", "icii",  handle, string, size, static_cast<int>( pack));
}

bool fputchar(int  handle, int value, bool  utf8) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fputchar", "iii",  handle, value, static_cast<int>( utf8));
  return * (bool*) &result;
}

int fgetchar(int  handle, int value, bool  utf8) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fgetchar", "iii",  handle, value, static_cast<int>( utf8));
}

int fblockwrite(int  handle, char* buffer, int size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fblockwrite", "ici",  handle, buffer, size);
}

int fblockread(int  handle, char* buffer, int size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fblockread", "ici",  handle, buffer, size);
}

int fseek(int  handle, int position, seek_whence  whence) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fseek", "iii",  handle, position, static_cast<int>( whence));
}

int flength(int  handle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("flength", "i",  handle);
}

int fexist(char* pattern) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fexist", "c", pattern);
}

bool fmatch(char* name, char* pattern, int index, int size) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fmatch", "ccii", name, pattern, index, size);
  return * (bool*) &result;
}

}  // namespace samp
