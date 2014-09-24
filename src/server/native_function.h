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

#ifndef SERVER_NATIVE_FUNCTION_H_
#define SERVER_NATIVE_FUNCTION_H_

#include <functional>

// Signature which a native function information has to conform to. The |arguments| parameter will
// contain an array of signed intergers of size |argument_count|, the values of which may be
// passed through one of the NativeFunction helpers to get the real value.
typedef std::function<int(int, int)> NativeFunction;

#endif  // SERVER_NATIVE_FUNCTION_H_
