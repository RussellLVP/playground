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

#ifndef SERVER_NATIVE_ARGUMENTS_H_
#define SERVER_NATIVE_ARGUMENTS_H_

#include <string>

typedef struct tagAMX AMX;
typedef int cell;

// Dealing with Pawn arguments can be a pain and may require complicated manual work. In order to
// make this more convenient, access to them has been wrapped in this utility class.
class NativeArguments {
 public:
  NativeArguments(AMX* amx, cell* parameters)
      : amx_(amx), parameters_(parameters) {}

  // Returns the number of arguments passed to this function.
  unsigned int GetArgumentCount() const;

  // Returns argument |index| as an integer. All integers in Pawn are signed.
  int GetIntegerArgument(unsigned int index) const;

  // Returns argument |index| as a 4-byte IEEE 754 floating point value.
  float GetFloatArgument(unsigned int index) const;

  // Returns argument |index| as a string. A copy will be performed on the data.
  std::string GetStringArgument(unsigned int index) const;

 private:
  AMX* amx_;
  cell* parameters_;
};

#endif  // SERVER_NATIVE_ARGUMENTS_H_
