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

#include <algorithm>
#include <string>

#include "features/reaction_test/drivers/calculation_driver.h"
#include "features/reaction_test/drivers/random_string_driver.h"
#include "features/reaction_test/reaction_test_question.h"
#include "playground/communication/chat_event_listener.h"
#include "playground/communication/chat_manager.h"
#include "playground/entities/player.h"
#include "playground/entities/player_manager.h"
#include "playground/services/service_test.h"

class ReactionTestServiceTest : public ServiceTest<ReactionTest>,
                                public ChatEventListener {
 public:
  virtual ~ReactionTestServiceTest() {}

  const std::string& last_message() const { return last_message_; }

  // ServiceTest overrides.
  virtual void SetUp() override {
    ServiceTest<ReactionTest>::SetUp();

    playground()->chat_manager().AttachEventListener(this);
    last_message_.clear();
  }

  // ChatEventListener implementation.
  virtual void OnDistributeMessageToAll(const std::string& message) {
    last_message_ = message;
  }

 private:
  std::string last_message_;
};

TEST_F(ReactionTestServiceTest, NewReactionTestConditions) {
  ASSERT_TRUE(last_message().empty());

  // No reaction test should be started if there are no players in-game.
  service().Start();
  EXPECT_TRUE(last_message().empty());

  ConnectPlayer("CJ");
  service().Start();
  EXPECT_FALSE(last_message().empty());
}

TEST_F(ReactionTestServiceTest, CalculationDriverTest) {
  CalculationDriver* driver = new CalculationDriver();
  service().OverrideDriverForTesting(driver);

  int player_id = ConnectPlayer("CJ");

  Player* player = playground()->player_manager().Get(player_id);
  ASSERT_TRUE(player != nullptr);

  int money = player->GetMoney();

  service().Start();
  EXPECT_FALSE(last_message().empty());
  service().OnPlayerText(player, driver->answer(), false);
  EXPECT_GT(player->GetMoney(), money);
}

TEST_F(ReactionTestServiceTest, RandomStringDriverTest) {
  RandomStringDriver* driver = new RandomStringDriver();
  service().OverrideDriverForTesting(driver);

  int player_id = ConnectPlayer("CJ");

  Player* player = playground()->player_manager().Get(player_id);
  ASSERT_TRUE(player != nullptr);

  int money = player->GetMoney();

  service().Start();
  EXPECT_FALSE(last_message().empty());
  service().OnPlayerText(player, driver->answer(), false);
  EXPECT_GT(player->GetMoney(), money);

  money = player->GetMoney();
  service().Start();
  
  std::string answer = driver->answer();
  std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
  ASSERT_NE(answer, driver->answer());

  service().OnPlayerText(player, answer, false);
  EXPECT_GT(player->GetMoney(), money);
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
