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

#include "features/reaction_test/reaction_test.h"

#include "features/reaction_test/reaction_test_question.h"
#include "playground/services/service_test.h"

class ReactionTestServiceTest : public ServiceTest<ReactionTest> {};

TEST_F(ReactionTestServiceTest, AlwaysPasses) {
  
  EXPECT_TRUE(true);
}

TEST_F(ReactionTestServiceTest, PrizeMoneyComplexityDistribution) {
  const int kIterations = 500;

  ReactionTestQuestion question;
  uint64_t easy_total = 0,
           normal_total = 0,
           hard_total = 0;

  question.complexity = ReactionTestQuestion::EasyQuestion;
  for (int i = 0; i < kIterations; ++i)
    easy_total += service().GetPrizeMoneyForQuestion(question);

  easy_total /= kIterations;

  question.complexity = ReactionTestQuestion::NormalQuestion;
  for (int i = 0; i < kIterations; ++i)
    normal_total += service().GetPrizeMoneyForQuestion(question);

  normal_total /= kIterations;

  question.complexity = ReactionTestQuestion::HardQuestion;
  for (int i = 0; i < kIterations; ++i)
    hard_total += service().GetPrizeMoneyForQuestion(question);

  hard_total /= kIterations;

  EXPECT_GT(easy_total, 0);
  EXPECT_GT(normal_total, 0);
  EXPECT_GT(hard_total, 0);

  EXPECT_LT(easy_total, normal_total);
  EXPECT_LT(normal_total, hard_total);
}
