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

#include "server/native_arguments.h"

#include "base/logging.h"
#include "server/sdk/amx.h"

unsigned int NativeArguments::GetArgumentCount() const {
  return parameters_[0] / 4;
}

int NativeArguments::GetIntegerArgument(unsigned int index) const {
  CHECK(GetArgumentCount() > index);
  return parameters_[1 + index];
}

float NativeArguments::GetFloatArgument(unsigned int index) const {
  CHECK(GetArgumentCount() > index);
  return * (float*) &parameters_[1 + index];
}

std::string NativeArguments::GetStringArgument(unsigned int index) const {
  CHECK(GetArgumentCount() > index);
  std::string string;

  cell* string_address;
  amx_GetAddr(amx_, parameters_[1 + index], &string_address);

  int string_length;
  amx_StrLen(string_address, &string_length);

  for (int i = 0; i < string_length; ++i)
    string.insert(string.end(), static_cast<char>(string_address[i]));

  return string;
}