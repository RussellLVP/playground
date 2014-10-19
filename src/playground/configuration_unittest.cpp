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

#include "base/logging.h"
#include "gtest/gtest.h"

using namespace logging;

namespace {

// The Configuration class will output warnings when JSON data cannot be read, or properties are
// being read in wrong data types which cannot be automatically converted. To avoid spamming the
// console when running unit tests, we surpress these messages here.
class ConfigurationTest : public testing::Test {
 public:
  virtual void SetUp() override {
    previous_log_level_ = LogMessage::GetMinimumLogSeverity();
    LogMessage::SetMinimumLogSeverity(LOG_FATAL);
  }

  virtual void TearDown() override {
    LogMessage::SetMinimumLogSeverity(previous_log_level_);
  }

 private:
  int previous_log_level_;
};

}  // namespace

TEST_F(ConfigurationTest, InvalidConstructors) {
  EXPECT_EQ(nullptr, Configuration::FromString(nullptr));
  EXPECT_EQ(nullptr, Configuration::FromString(""));
  EXPECT_EQ(nullptr, Configuration::FromString("LVP"));
  EXPECT_EQ(nullptr, Configuration::FromFile(nullptr));
  EXPECT_EQ(nullptr, Configuration::FromFile(""));
  EXPECT_EQ(nullptr, Configuration::FromFile("RANDOM_NON_EXISTENT_FILE"));
}
