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

#ifndef SERVER_BINDINGS_FLOAT_H_
#define SERVER_BINDINGS_FLOAT_H_

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

enum floatround_method {
  floatround_round,
  floatround_floor,
  floatround_ceil,
  floatround_tozero,
  floatround_unbiased,
};

enum anglemode {
  radian,
  degrees,
  grades,
};

float _float(int value);
float floatstr(char* string);
float floatmul(float oper1, float oper2);
float floatdiv(float dividend, float divisor);
float floatadd(float oper1, float oper2);
float floatsub(float oper1, float oper2);
float floatfract(float value);
int floatround(float value, floatround_method method);
int floatcmp(float oper1, float oper2);
float floatsqroot(float value);
float floatpower(float value, float exponent);
float floatlog(float value, float base);
float floatsin(float value, anglemode mode);
float floatcos(float value, anglemode mode);
float floattan(float value, anglemode mode);
float floatabs(float value);

}  // namespace samp

#endif  // SERVER_BINDINGS_FLOAT_H_
