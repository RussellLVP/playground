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

#ifndef FEATURES_REACTION_TEST_REACTION_TEST_QUESTION_H_
#define FEATURES_REACTION_TEST_REACTION_TEST_QUESTION_H_

#include <string>

// Contains information about the created reaction test question needed to present it to in-game
// players and calculate an appropriate amount of prize money for it.
struct ReactionTestQuestion {
  ReactionTestQuestion()
      : complexity(NormalQuestion) {}

  // The action the player has to do with the question, e.g. "solve" or "repeat".
  std::string action;

  // The question which has to be answered by the player, e.g. "(2+5)*5" or "SKDJFSDF";
  std::string question;

  // The different complexity levels of questions created by the reaction test. A more complicated
  // question will take players more time to solve, and will thus increase their reward.
  enum QuestionComplexity {
    EasyQuestion,
    NormalQuestion,
    HardQuestion
  };

  // The complexity level of this question.
  QuestionComplexity complexity;
};

#endif  // FEATURES_REACTION_TEST_REACTION_TEST_QUESTION_H_
