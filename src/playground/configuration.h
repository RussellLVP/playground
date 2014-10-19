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

#include <memory>

// Provides read-only access to the data contained in a JSON structure, either passed in as a string
// or loaded through a file. Values can be read in any format.
class Configuration {
 public:
  // Creates a new Configuration instance fed with |data| as the JSON structure.
  static std::unique_ptr<Configuration> FromString(const char* data);

  // Creates a new Configuration instance fed by the contents of |filename|.
  static std::unique_ptr<Configuration> FromFile(const char* filename);

  ~Configuration();

 private:
  explicit Configuration(const char* data);
};

#endif  // PLAYGROUND_CONFIGURATION_H_
