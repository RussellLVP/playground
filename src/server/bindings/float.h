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

// Generated on 2014-09-27 at 03:03:47.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace bindings {

float _float(int value);

float floatstr(char* string);

float floatmul(float oper1, float oper2);

float floatdiv(float dividend, float divisor);

float floatadd(float oper1, float oper2);

float floatsub(float oper1, float oper2);

float floatfract(float value);

int floatround(float value, int method);

int floatcmp(float oper1, float oper2);

float floatsqroot(float value);

float floatpower(float value, float exponent);

float floatlog(float value, float base);

float floatsin(float value, int mode);

float floatcos(float value, int mode);

float floattan(float value, int mode);

float floatabs(float value);

}  // namespace bindings

#endif  // SERVER_BINDINGS_FLOAT_H_
