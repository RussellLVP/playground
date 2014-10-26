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

#include "features/reaction_test/drivers/calculation_driver.h"

#include <sstream>

#include "base/random.h"

CalculationDriver::CalculationDriver() {}

CalculationDriver::~CalculationDriver() {}

ReactionTestQuestion CalculationDriver::CreateQuestion() {
  answer_.clear();

  ReactionTestQuestion question;
  question.action = "solve";

  std::stringstream stream;

  // The calculation reaction test comes in three levels, easy, normal and hard. Each of these will
  // generate a different kind of calculation to solve, which are as follows.
  //
  // EASY (30%):   |X [+-] Y [+-] Z|, where X and Z will be in the range of [-10, 30], and Y in the
  //                                  range of [1, 99].
  // NORMAL (50%): |(X [+-] Y) * Z|, where X and Y will be in the range of [-20, 50], and Z will be
  //                                 in the range of [2, 5].
  // HARD (20%):   |X * Y [+-] Z|, where each of X, Y, Z will be in the range of [15, 99].

  int complexity_index = Random::Next(0, 9);
  if (complexity_index < 3) {
    question.complexity = ReactionTestQuestion::EasyQuestion;
    int x = Random::Next(-10, 30),
        y = Random::Next(  1, 99),
        z = Random::Next(-10, 30);

    char first_operand = Random::Next(0, 1) == 1 ? '+' : '-',
         second_operand = Random::Next(0, 1) == 1 ? '+' : '-';

    stream << x << " " << first_operand << " " << y << " " << second_operand << " " << z;

    int interim = first_operand == '+' ? x + y : x - y;
    answer_ = std::to_string(second_operand == '+' ? interim + z : interim - z);

  } else if (complexity_index < 8) {
    question.complexity = ReactionTestQuestion::NormalQuestion;
    int x = Random::Next(-20, 50),
        y = Random::Next(-20, 50),
        z = Random::Next(2, 5);

    char operand = Random::Next(0, 1) == 1 ? '+' : '-';

    stream << "(" << x << " " << operand << " " << y << ") * " << z;
    answer_ = std::to_string((operand == '+' ? x + y : x - y) * z);

  } else {
    question.complexity = ReactionTestQuestion::HardQuestion;
    int x = Random::Next(15, 99),
        y = Random::Next(15, 99),
        z = Random::Next(15, 99);

    char operand = Random::Next(0, 1) == 1 ? '+' : '-';

    stream << x << " * " << y << " " << operand << " " << z;
    answer_ = std::to_string(operand == '+' ? x * y + z : x * y - z);
  }

  question.question = stream.str();
  return question;
}

bool CalculationDriver::IsCorrect(const std::string& answer) const {
  return answer_ == answer;
}
