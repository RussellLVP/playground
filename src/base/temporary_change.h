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

#ifndef BASE_TEMPORARY_CHANGE_H_
#define BASE_TEMPORARY_CHANGE_H_

template <typename Type>
class TemporaryChange {
 public:
  TemporaryChange(Type* address, Type value)
      : address_(address) {
     original_value_ = *address;
     *address = value;
   }

  ~TemporaryChange() {
    *address_ = original_value_;
  }

 private:
  Type original_value_;
  Type* address_;
};

#endif  // BASE_TEMPORARY_CHANGE_H_
