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

#ifndef SERVER_BINDINGS_HTTP_H_
#define SERVER_BINDINGS_HTTP_H_

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

const int HTTP_GET = 1;
const int HTTP_POST = 2;
const int HTTP_HEAD = 3;
const int HTTP_ERROR_BAD_HOST = 1;
const int HTTP_ERROR_NO_SOCKET = 2;
const int HTTP_ERROR_CANT_CONNECT = 3;
const int HTTP_ERROR_CANT_WRITE = 4;
const int HTTP_ERROR_CONTENT_TOO_BIG = 5;
const int HTTP_ERROR_MALFORMED_RESPONSE = 6;

int HTTP(int index, int type, char* url, char* data, char* callback);

}  // namespace samp

#endif  // SERVER_BINDINGS_HTTP_H_
