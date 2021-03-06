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

#ifndef BASE_MACROS_H_
#define BASE_MACROS_H_

// Disallows both the copy constructor and the assignment operator.
#define DISALLOW_COPY_AND_ASSIGN(Type) \
 private: \
  Type(const Type&) = delete; \
  void operator=(const Type&) = delete;

#if defined(WINDOWS)
#define THREAD_LOCAL __declspec(thread)
#else
#define THREAD_LOCAL thread_local
#endif

#endif  // BASE_MACROS_H_