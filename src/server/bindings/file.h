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

#ifndef SERVER_BINDINGS_FILE_H_
#define SERVER_BINDINGS_FILE_H_

// Generated on 2014-09-27 at 03:13:47 GMT Summer Time.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int fopen(char* name, int  mode);

bool fclose(int  handle);

int ftemp();

bool fremove(char* name);

int fwrite(int  handle, char* string);

int fread(int  handle, char* string, int size, bool  pack);

bool fputchar(int  handle, int value, bool  utf8);

int fgetchar(int  handle, int value, bool  utf8);

int fblockwrite(int  handle, char* buffer, int size);

int fblockread(int  handle, char* buffer, int size);

int fseek(int  handle, int position, int  whence);

int flength(int  handle);

int fexist(char* pattern);

bool fmatch(char* name, char* pattern, int index, int size);

}  // namespace samp

#endif  // SERVER_BINDINGS_FILE_H_
