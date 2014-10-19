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

#include "playground/configuration.h"

#include <fstream>
#include <sstream>

#include "base/logging.h"

// static
std::unique_ptr<Configuration> Configuration::FromString(const char* data) {
  if (!data || !strlen(data))
    return nullptr;

  std::stringstream stream;
  stream << data;

  return std::unique_ptr<Configuration>(new Configuration(stream));
}

// static
std::unique_ptr<Configuration> Configuration::FromFile(const char* filename) {
  if (!filename || !strlen(filename))
    return nullptr;

  std::ifstream stream(filename);
  if (!stream.is_open())
    return nullptr;

  return std::unique_ptr<Configuration>(new Configuration(stream));
}

Configuration::Configuration(std::istream& stream) {
  Json::Reader reader;
  if (!reader.parse(stream, configuration_))
    LOG(WARNING) << "Unable to parse JSON data: " << reader.getFormattedErrorMessages();
}

Configuration::~Configuration() {}

bool Configuration::IsValid() const {
  return configuration_.isObject();
}
