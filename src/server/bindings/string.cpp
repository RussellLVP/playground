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

#include "server/bindings/string.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int strlen(char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strlen", "c", string);
}

int strpack(char* dest, char* source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strpack", "cci", dest, source, maxlength);
}

int strunpack(char* dest, char* source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strunpack", "cci", dest, source, maxlength);
}

int strcat(char* dest, char* source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strcat", "cci", dest, source, maxlength);
}

int strmid(char* dest, char* source, int start, int end, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strmid", "cciii", dest, source, start, end, maxlength);
}

bool strins(char* string, char* substr, int pos, int maxlength) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("strins", "ccii", string, substr, pos, maxlength);
  return * (bool*) &result;
}

bool strdel(char* string, int start, int end) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("strdel", "cii", string, start, end);
  return * (bool*) &result;
}

int strcmp(char* string1, char* string2, bool ignorecase, int length) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strcmp", "ccii", string1, string2, static_cast<int>(ignorecase), length);
}

int strfind(char* string, char* sub, bool ignorecase, int pos) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strfind", "ccii", string, sub, static_cast<int>(ignorecase), pos);
}

int strval(char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strval", "c", string);
}

int valstr(char* dest, int value, bool pack) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("valstr", "cii", dest, value, static_cast<int>(pack));
}

bool ispacked(char* string) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("ispacked", "c", string);
  return * (bool*) &result;
}

int uudecode(char* dest, char* source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("uudecode", "cci", dest, source, maxlength);
}

int uuencode(char* dest, char* source, int numbytes, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("uuencode", "ccii", dest, source, numbytes, maxlength);
}

int memcpy(char* dest, char* source, int index, int numbytes, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("memcpy", "cciii", dest, source, index, numbytes, maxlength);
}

}  // namespace samp
