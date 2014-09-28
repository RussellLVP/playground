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

#ifndef SERVER_BINDINGS_STRING_H_
#define SERVER_BINDINGS_STRING_H_

#include <string>

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int strlen(std::string& string);
int strpack(std::string& dest, std::string& source, int maxlength);
int strunpack(std::string& dest, std::string& source, int maxlength);
int strcat(std::string& dest, std::string& source, int maxlength);
int strmid(std::string& dest, std::string& source, int start, int end, int maxlength);
bool strins(std::string& string, std::string& substr, int pos, int maxlength);
bool strdel(std::string& string, int start, int end);
int strcmp(std::string& string1, std::string& string2, bool ignorecase, int length);
int strfind(std::string& string, std::string& sub, bool ignorecase, int pos);
int strval(std::string& string);
int valstr(std::string& dest, int value, bool pack);
bool ispacked(std::string& string);
int uudecode(std::string& dest, std::string& source, int maxlength);
int uuencode(std::string& dest, std::string& source, int numbytes, int maxlength);
int memcpy(std::string& dest, std::string& source, int index, int numbytes, int maxlength);

}  // namespace samp

#endif  // SERVER_BINDINGS_STRING_H_
