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

#ifndef SERVER_BINDINGS_TIME_H_
#define SERVER_BINDINGS_TIME_H_

// Generated on 2014-09-27 at 03:34:10 GMT Summer Time.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int gettime(int* hour, int* minute, int* second);
int getdate(int* year, int* month, int* day);
int tickcount(int* granularity);

}  // namespace samp

#endif  // SERVER_BINDINGS_TIME_H_
