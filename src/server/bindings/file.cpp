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

int fopen(std::string& name, filemode  mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fopen", "si", &name, static_cast<int>( mode));
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

bool fremove(std::string& name) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fremove", "s", &name);
  return * (bool*) &result;
}

int fwrite(int  handle, std::string& string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fwrite", "is",  handle, &string);
}

int fread(int  handle, std::string& string, int size, bool  pack) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fread", "isii",  handle, &string, size, static_cast<int>( pack));
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

int fblockwrite(int  handle, std::string& buffer, int size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fblockwrite", "isi",  handle, &buffer, size);
}

int fblockread(int  handle, std::string& buffer, int size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fblockread", "isi",  handle, &buffer, size);
}

int fseek(int  handle, int position, seek_whence  whence) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fseek", "iii",  handle, position, static_cast<int>( whence));
}

int flength(int  handle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("flength", "i",  handle);
}

int fexist(std::string& pattern) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("fexist", "s", &pattern);
}

bool fmatch(std::string& name, std::string& pattern, int index, int size) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("fmatch", "ssii", &name, &pattern, index, size);
  return * (bool*) &result;
}

}  // namespace samp
