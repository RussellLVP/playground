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

#ifndef FEATURES_REACTION_TEST_DRIVERS_CALCULATION_DRIVER_H_
#define FEATURES_REACTION_TEST_DRIVERS_CALCULATION_DRIVER_H_

#include "features/reaction_test/reaction_test_driver.h"

// Reaction test driver which presents a calculation of medium difficulty to the user. The given
// answer must exactly match the integer resulting from the calculation.
class CalculationDriver : public ReactionTestDriver {
 public:
  CalculationDriver();
  virtual ~CalculationDriver();

  // ReactionTestDriver implementation.
  virtual std::string CreateQuestion() override;
  virtual bool IsCorrect(const std::string& answer) const override;

 private:
};

#endif  // FEATURES_REACTION_TEST_DRIVERS_CALCULATION_DRIVER_H_
