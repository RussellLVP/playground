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

#include "base/json/json_object.h"

#include <algorithm>
#include <limits>

#include "base/json/json.h"
#include "base/logging.h"

using namespace Json;

namespace {

// Returns a pointer to the entry in |object| identified by |key|, when said entry is convertible
// to type |type|. Furthermore, it is valid for |object| to be a nullptr.
const Value* GetValueOfType(const Value* object, const std::string& key, ValueType type) {
  if (!object || !object->isObject())
    return nullptr;

  const Value& value = (*object)[key];
  if (value.isNull() || !value.isConvertibleTo(type))
    return nullptr;

  return &value;
}

template <typename Type, typename LargeType>
Type ClampTo(LargeType value) {
  LOG(INFO) << "Clamping: " << value;
  if (value >= std::numeric_limits<Type>::max()) {
    LOG(INFO) << "Clamping to MAX.";
    return std::numeric_limits<Type>::max();
  }

  if (value <= std::numeric_limits<Type>::min()) {
    LOG(INFO) << "Clamping to MIN.";
    return std::numeric_limits<Type>::min();
  }

  return static_cast<Type>(value);
}

}  // namespace

JsonObject::JsonObject(const Json::Value* object)
    : object_(object) {}

bool JsonObject::IsValid() const {
  return object_ && object_->isObject();
}

bool JsonObject::Contains(const std::string& key) const {
  return IsValid() && object_->isMember(key);
}

int32_t JsonObject::GetInteger(const std::string& key, int32_t default_value) const {
  if (const Value* value = GetValueOfType(object_, key, intValue))
    return ClampTo<int32_t>(value->asLargestInt());

  return default_value;
}

uint32_t JsonObject::GetUnsignedInteger(const std::string& key, uint32_t default_value) const {
  if (const Value* value = GetValueOfType(object_, key, uintValue))
    return ClampTo<uint32_t>(value->asLargestUInt());

  return default_value;
}

int64_t JsonObject::GetInteger64(const std::string& key, int64_t default_value) const {
  if (const Value* value = GetValueOfType(object_, key, intValue))
    return ClampTo<int64_t>(value->asLargestInt());

  return default_value;
}

uint64_t JsonObject::GetUnsignedInteger64(const std::string& key, uint64_t default_value) const {
  if (const Value* value = GetValueOfType(object_, key, uintValue))
    return ClampTo<uint64_t>(value->asLargestUInt());

  return default_value;
}

JsonObject JsonObject::GetObject(const std::string& key) const {
  return JsonObject(GetValueOfType(object_, key, objectValue));
}
