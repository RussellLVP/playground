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

#ifndef BASE_JSON_JSON_OBJECT_H_
#define BASE_JSON_JSON_OBJECT_H_

#include <stdint.h>
#include <string>

namespace Json { class Value; }

// The JsonObject class provides an interface using which a consumer can communicate with JSON data.
// Each method made available as part of this object has well defined behavior and is guaranteed to
// not throw C++ exceptions.
class JsonObject {
 public:
  // Returns if this JsonObject refers to a valid object. This may not be the case if it was created
  // using a nullptr as the hosting object.
  bool IsValid() const;

  // Returns if this object contains |key|, referring to a value of any type.
  bool Contains(const std::string& key) const;

  // Returns the value of |key| when it exists in this object and can be converted to a 32-bit
  // signed integer. Otherwise, it will return the value specified in |default_value|. Values
  // returned by this method will always be clamped to the range [-2147483648, 2147483647].
  int32_t GetInteger(const std::string& key, int32_t default_value = 0) const;

  // Returns the value of |key| when it exists in this object and can be converted to a 64-bit
  // signed integer. Otherwise, it will return the value specified in |default_value|. Values
  // returned by this method will always be clamped to the range [0, 4294967295].
  int64_t GetInteger64(const std::string& key, int64_t default_value = 0) const;

  // Returns the value of |key| when it exists in this object and can be converted to a 32-bit
  // unsigned integer. Otherwise, it will return the value specified in |default_value|. Values
  // returned by this method will always be clamped to the range [-(2^63), 2^63-1].
  uint32_t GetUnsignedInteger(const std::string& key, uint32_t default_value = 0) const;

  // Returns the value of |key| when it exists in this object and can be converted to a 64-bit
  // unsigned integer. Otherwise, it will return the value specified in |default_value|. Values
  // returned by this method will always be clamped to the range [0, 2^64-1].
  uint64_t GetUnsignedInteger64(const std::string& key, uint64_t default_value = 0) const;
  
  // Returns a new JsonObject instance which wraps the values of |key| when it exists in this
  // object, and is an object indeed. 
  JsonObject GetObject(const std::string& key) const;

 protected:
  explicit JsonObject(const Json::Value* object);

 private:
  const Json::Value* object_;
};

#endif  // BASE_JSON_JSON_OBJECT_H_
