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

// Generated on 2014-09-27 at 03:03:47.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace bindings {

int strlen(char* string);

int strpack(char* dest, char* source, int maxlength);

int strunpack(char* dest, char* source, int maxlength);

int strcat(char* dest, char* source, int maxlength);

int strmid(char* dest, char* source, int start, int end, int maxlength);

bool  strins(char* string, char* substr, int pos, int maxlength);

bool  strdel(char* string, int start, int end);

int strcmp(char* string1, char* string2, bool ignorecase, int length);

int strfind(char* string, char* sub, bool ignorecase, int pos);

int strval(char* string);

int valstr(char* dest, int value, bool pack);

bool  ispacked(char* string);

int uudecode(char* dest, char* source, int maxlength);

int uuencode(char* dest, char* source, int numbytes, int maxlength);

int memcpy(char* dest, char* source, int index, int numbytes, int maxlength);

}  // namespace bindings

#endif  // SERVER_BINDINGS_STRING_H_
