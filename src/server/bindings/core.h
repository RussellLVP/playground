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

#include <string>

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int heapspace();
int funcidx(std::string& name);
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
int getproperty(int id, std::string& name, int value, std::string& string);
int setproperty(int id, std::string& name, int value, std::string& string);
int deleteproperty(int id, std::string& name, int value);
int existproperty(int id, std::string& name, int value);

}  // namespace samp

#endif  // SERVER_BINDINGS_CORE_H_
