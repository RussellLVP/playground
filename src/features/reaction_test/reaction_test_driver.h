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

#ifndef FEATURES_REACTION_TEST_REACTION_TEST_DRIVER_H_
#define FEATURES_REACTION_TEST_REACTION_TEST_DRIVER_H_

#include <string>

// A reaction test driver defines the underlying logic of a test. Each driver gets complete freedom
// in defining the format of the questions and answers.
class ReactionTestDriver {
 public:
  virtual ~ReactionTestDriver() {}

  // Creates a new reaction test. The question will be returned as a string.
  virtual std::string CreateQuestion() = 0;

  // Returns whether the |answer| is the correct answer to the running test.
  virtual bool IsCorrect(const std::string& answer) const = 0;
};

#endif  // FEATURES_REACTION_TEST_REACTION_TEST_DRIVER_H_
