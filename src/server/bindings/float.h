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

// Generated on 2014-09-28.
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

double _float(int value);
double floatstr(char* string);
double floatmul(double oper1, double oper2);
double floatdiv(double dividend, double divisor);
double floatadd(double oper1, double oper2);
double floatsub(double oper1, double oper2);
double floatfract(double value);
int floatround(double value, floatround_method method);
int floatcmp(double oper1, double oper2);
double floatsqroot(double value);
double floatpower(double value, double exponent);
double floatlog(double value, double base);
double floatsin(double value, anglemode mode);
double floatcos(double value, anglemode mode);
double floattan(double value, anglemode mode);
double floatabs(double value);

}  // namespace samp

#endif  // SERVER_BINDINGS_FLOAT_H_
