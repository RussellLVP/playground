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

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

double _float(int value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("_float", "i", value);
  return static_cast<double>(amx_ctof(result));
}

double floatstr(std::string& string) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatstr", "s", &string);
  return static_cast<double>(amx_ctof(result));
}

double floatmul(double oper1, double oper2) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatmul", "ff", oper1, oper2);
  return static_cast<double>(amx_ctof(result));
}

double floatdiv(double dividend, double divisor) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatdiv", "ff", dividend, divisor);
  return static_cast<double>(amx_ctof(result));
}

double floatadd(double oper1, double oper2) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatadd", "ff", oper1, oper2);
  return static_cast<double>(amx_ctof(result));
}

double floatsub(double oper1, double oper2) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatsub", "ff", oper1, oper2);
  return static_cast<double>(amx_ctof(result));
}

double floatfract(double value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatfract", "f", value);
  return static_cast<double>(amx_ctof(result));
}

int floatround(double value, floatround_method method) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("floatround", "fi", value, static_cast<int>(method));
}

int floatcmp(double oper1, double oper2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("floatcmp", "ff", oper1, oper2);
}

double floatsqroot(double value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatsqroot", "f", value);
  return static_cast<double>(amx_ctof(result));
}

double floatpower(double value, double exponent) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatpower", "ff", value, exponent);
  return static_cast<double>(amx_ctof(result));
}

double floatlog(double value, double base) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatlog", "ff", value, base);
  return static_cast<double>(amx_ctof(result));
}

double floatsin(double value, anglemode mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatsin", "fi", value, static_cast<int>(mode));
  return static_cast<double>(amx_ctof(result));
}

double floatcos(double value, anglemode mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatcos", "fi", value, static_cast<int>(mode));
  return static_cast<double>(amx_ctof(result));
}

double floattan(double value, anglemode mode) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floattan", "fi", value, static_cast<int>(mode));
  return static_cast<double>(amx_ctof(result));
}

double floatabs(double value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("floatabs", "f", value);
  return static_cast<double>(amx_ctof(result));
}

}  // namespace samp
