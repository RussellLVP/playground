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

#ifndef SERVER_BINDINGS_CORE_H_
#define SERVER_BINDINGS_CORE_H_

// Generated on 2014-09-27 at 03:13:47 GMT Summer Time.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int heapspace();

int funcidx(char* name);

int numargs();

int getarg(int arg, int index);

int setarg(int arg, int index, int value);

int tolower(int c);

int toupper(int c);

int swapchars(int c);

int random(int max);

int min(int value1, int value2);

int max(int value1, int value2);

int clamp(int value, int min, int max);

int getproperty(int id, char* name, int value, char* string);

int setproperty(int id, char* name, int value, char* string);

int deleteproperty(int id, char* name, int value);

int existproperty(int id, char* name, int value);

}  // namespace samp

#endif  // SERVER_BINDINGS_CORE_H_
