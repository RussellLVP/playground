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

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int strlen(std::string& string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strlen", "s", &string);
}

int strpack(std::string& dest, std::string& source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strpack", "ssi", &dest, &source, maxlength);
}

int strunpack(std::string& dest, std::string& source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strunpack", "ssi", &dest, &source, maxlength);
}

int strcat(std::string& dest, std::string& source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strcat", "ssi", &dest, &source, maxlength);
}

int strmid(std::string& dest, std::string& source, int start, int end, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strmid", "ssiii", &dest, &source, start, end, maxlength);
}

bool strins(std::string& string, std::string& substr, int pos, int maxlength) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("strins", "ssii", &string, &substr, pos, maxlength);
  return * (bool*) &result;
}

bool strdel(std::string& string, int start, int end) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("strdel", "sii", &string, start, end);
  return * (bool*) &result;
}

int strcmp(std::string& string1, std::string& string2, bool ignorecase, int length) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strcmp", "ssii", &string1, &string2, static_cast<int>(ignorecase), length);
}

int strfind(std::string& string, std::string& sub, bool ignorecase, int pos) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strfind", "ssii", &string, &sub, static_cast<int>(ignorecase), pos);
}

int strval(std::string& string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("strval", "s", &string);
}

int valstr(std::string& dest, int value, bool pack) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("valstr", "sii", &dest, value, static_cast<int>(pack));
}

bool ispacked(std::string& string) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("ispacked", "s", &string);
  return * (bool*) &result;
}

int uudecode(std::string& dest, std::string& source, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("uudecode", "ssi", &dest, &source, maxlength);
}

int uuencode(std::string& dest, std::string& source, int numbytes, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("uuencode", "ssii", &dest, &source, numbytes, maxlength);
}

int memcpy(std::string& dest, std::string& source, int index, int numbytes, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("memcpy", "ssiii", &dest, &source, index, numbytes, maxlength);
}

}  // namespace samp
