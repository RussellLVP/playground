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

// A string containing valid configuration in a variety of data formats.
const char kValidConfigurationString[] = R"json(
  {
    // This is a comment. In JSON. Fantastic.
    "string": "Hello, world",
    "number": 1234,
    "double": 12.5,
    "array": [0, 1, 2],
    "void": null
  })json";

}  // namespace

TEST_F(ConfigurationTest, InvalidConstructors) {
  EXPECT_EQ(nullptr, Configuration::FromString(nullptr));
  EXPECT_EQ(nullptr, Configuration::FromString(""));
  EXPECT_EQ(nullptr, Configuration::FromFile(nullptr));
  EXPECT_EQ(nullptr, Configuration::FromFile(""));
  EXPECT_EQ(nullptr, Configuration::FromFile("RANDOM_NON_EXISTENT_FILE"));
}

TEST_F(ConfigurationTest, InvalidData) {
  EXPECT_EQ(nullptr, Configuration::FromString("LVP"));
  EXPECT_EQ(nullptr, Configuration::FromString("[0, 1, 2]"));
  EXPECT_EQ(nullptr, Configuration::FromString("null"));
  EXPECT_EQ(nullptr, Configuration::FromString("0"));
  EXPECT_EQ(nullptr, Configuration::FromString("\"text\""));
}

TEST_F(ConfigurationTest, ReadRawValues) {
  auto configuration = Configuration::FromString(kValidConfigurationString);
  ASSERT_TRUE(configuration->IsValid());

  EXPECT_EQ("Hello, world", configuration->Get("string").asString());
  EXPECT_THROW(configuration->Get("string").asInt(), std::runtime_error);
  EXPECT_THROW(configuration->Get("string").asDouble(), std::runtime_error);
  EXPECT_THROW(configuration->Get("string").asBool(), std::runtime_error);
  EXPECT_EQ(0, configuration->Get("string").size());

  EXPECT_EQ("1234", configuration->Get("number").asString());
  EXPECT_EQ(1234, configuration->Get("number").asInt());
  EXPECT_DOUBLE_EQ(1234, configuration->Get("number").asDouble());
  EXPECT_TRUE(configuration->Get("number").asBool());
  EXPECT_EQ(0, configuration->Get("number").size());

  EXPECT_EQ("12.5", configuration->Get("double").asString());
  EXPECT_EQ(12, configuration->Get("double").asInt());
  EXPECT_DOUBLE_EQ(12.5, configuration->Get("double").asDouble());
  EXPECT_TRUE(configuration->Get("double").asBool());
  EXPECT_EQ(0, configuration->Get("double").size());

  EXPECT_THROW(configuration->Get("array").asString(), std::runtime_error);
  EXPECT_THROW(configuration->Get("array").asInt(), std::runtime_error);
  EXPECT_THROW(configuration->Get("array").asDouble(), std::runtime_error);
  EXPECT_THROW(configuration->Get("array").asBool(), std::runtime_error);
  EXPECT_EQ(3, configuration->Get("array").size());

  EXPECT_EQ("", configuration->Get("void").asString());
  EXPECT_EQ(0, configuration->Get("void").asInt());
  EXPECT_DOUBLE_EQ(0, configuration->Get("void").asDouble());
  EXPECT_FALSE(configuration->Get("void").asBool());
  EXPECT_EQ(0, configuration->Get("void").size());
}
