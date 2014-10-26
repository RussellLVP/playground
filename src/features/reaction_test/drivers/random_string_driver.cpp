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

#include "features/reaction_test/drivers/random_string_driver.h"

#include <algorithm>

#include "base/random.h"

namespace {

// Valid characters to be used in reaction tests. Some characters have been omitted because they
// look very similar to other characters, which may lead to confused players.
const char kValidCharacters[] = "ABCDEFGHJKLMNPQRSTUVWXYZ123456789";

}  // namespace

RandomStringDriver::RandomStringDriver() {}

RandomStringDriver::~RandomStringDriver() {}

ReactionTestQuestion RandomStringDriver::CreateQuestion() {
  answer_.clear();

  ReactionTestQuestion question;
  question.complexity = ReactionTestQuestion::EasyQuestion;
  question.action = "repeat";

  int question_length = 6;

  // There's a 25% chance that we'll create a normal-difficulty question, which has ten characters.
  // All other questions will be of easy difficulty and exist of six characters.
  if (Random::Next(0, 4) == 0) {
    question.complexity = ReactionTestQuestion::NormalQuestion;
    question_length = 10;
  }

  // Generate the string which should be repeated by the player.
  for (int i = 0; i < question_length; ++i)
    answer_.insert(answer_.end(), 1, kValidCharacters[Random::Next(0, sizeof(kValidCharacters) - 1)]);

  return question;
}

bool RandomStringDriver::IsCorrect(const std::string& answer) const {
  std::string uppercase = answer;
  std::transform(uppercase.begin(), uppercase.end(), uppercase.begin(), toupper);

  return uppercase == answer_;
}
