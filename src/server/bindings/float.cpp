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

#include "server/bindings/float.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

float _float(int value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("_float", "i", value);
  return * (float*) &result;
}

float floatstr(char* string) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatstr", "c", string);
  return * (float*) &result;
}

float floatmul(float oper1, float oper2) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatmul", "ff", oper1, oper2);
  return * (float*) &result;
}

float floatdiv(float dividend, float divisor) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatdiv", "ff", dividend, divisor);
  return * (float*) &result;
}

float floatadd(float oper1, float oper2) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatadd", "ff", oper1, oper2);
  return * (float*) &result;
}

float floatsub(float oper1, float oper2) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatsub", "ff", oper1, oper2);
  return * (float*) &result;
}

float floatfract(float value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatfract", "f", value);
  return * (float*) &result;
}

int floatround(float value, floatround_method method) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("floatround", "fi", value, static_cast<int>(method));
}

int floatcmp(float oper1, float oper2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("floatcmp", "ff", oper1, oper2);
}

float floatsqroot(float value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatsqroot", "f", value);
  return * (float*) &result;
}

float floatpower(float value, float exponent) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatpower", "ff", value, exponent);
  return * (float*) &result;
}

float floatlog(float value, float base) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatlog", "ff", value, base);
  return * (float*) &result;
}

float floatsin(float value, anglemode mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatsin", "fi", value, static_cast<int>(mode));
  return * (float*) &result;
}

float floatcos(float value, anglemode mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatcos", "fi", value, static_cast<int>(mode));
  return * (float*) &result;
}

float floattan(float value, anglemode mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floattan", "fi", value, static_cast<int>(mode));
  return * (float*) &result;
}

float floatabs(float value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatabs", "f", value);
  return * (float*) &result;
}

}  // namespace samp
