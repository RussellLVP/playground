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

#include <string>

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

enum filemode {
  io_read,
  io_write,
  io_readwrite,
  io_append,
};

enum seek_whence {
  seek_start,
  seek_current,
  seek_end,
};

int fopen(std::string& name, filemode  mode);
bool fclose(int  handle);
int ftemp();
bool fremove(std::string& name);
int fwrite(int  handle, std::string& string);
int fread(int  handle, std::string& string, int size, bool  pack);
bool fputchar(int  handle, int value, bool  utf8);
int fgetchar(int  handle, int value, bool  utf8);
int fblockwrite(int  handle, std::string& buffer, int size);
int fblockread(int  handle, std::string& buffer, int size);
int fseek(int  handle, int position, seek_whence  whence);
int flength(int  handle);
int fexist(std::string& pattern);
bool fmatch(std::string& name, std::string& pattern, int index, int size);

}  // namespace samp

#endif  // SERVER_BINDINGS_FILE_H_
