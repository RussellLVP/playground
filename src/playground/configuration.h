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

#ifndef PLAYGROUND_CONFIGURATION_H_
#define PLAYGROUND_CONFIGURATION_H_

#include <iosfwd>
#include <memory>

#include "base/json/json.h"
#include "base/json/json_object.h"
#include "base/macros.h"
#include "gtest/gtest_prod.h"

// Provides read-only access to the data contained in a JSON structure, either passed in as a string
// or loaded through a file. Values can be read in any format.
class Configuration : public JsonObject {
 public:
  // Creates a new Configuration instance fed with |data| as the JSON structure.
  static std::unique_ptr<Configuration> FromString(const char* data);

  // Creates a new Configuration instance fed by the contents of |filename|.
  static std::unique_ptr<Configuration> FromFile(const char* filename);

  ~Configuration();

  // Returns whether this Configuration instance contains any data.
  bool IsValid() const;

 private:
  explicit Configuration(std::istream& stream);

  // Returns the entry in |configuration_| identified by |name|. The value may be a Json::null value
  // in case it has not been defined in the configuration file. The Get() function is not exposed to
  // consumers, because we won't use C++ exceptions anywhere in this plugin, but provides for an
  // interface that allows us to conveniently test the underlying JSON implementation.
  const Json::Value& Get(const std::string& name) const;

  // Contains the JSON root node of the configuration tree.
  Json::Value configuration_;

  bool valid_;

  FRIEND_TEST(ConfigurationTest, ReadRawValues);
  DISALLOW_COPY_AND_ASSIGN(Configuration);
};

#endif  // PLAYGROUND_CONFIGURATION_H_
