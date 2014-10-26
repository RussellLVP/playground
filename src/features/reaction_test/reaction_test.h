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

#ifndef FEATURES_REACTION_TEST_REACTION_TEST_H_ 
#define FEATURES_REACTION_TEST_REACTION_TEST_H_

#include <memory>
#include <string>
#include <vector>

#include "gtest/gtest_prod.h"
#include "playground/communication/chat_event_listener.h"
#include "playground/services/service.h"
#include "playground/services/timers/timer.h"

class ReactionTestDriver;
struct ReactionTestQuestion;

// The reaction test feature sends an occasional puzzle to the connected players, a valid answer to
// which will make them some money. The puzzle can be of repetitive nature ("copy this string") or
// of mathematical nature ("calculate (60 - 15) * 2").
class ReactionTest : public Service,
                     public ChatEventListener {
  DECLARE_SERVICE(ReactionTest);

 public:
  // Starts a new reaction test by inviting all players to answer to a puzzle. The test will not be
  // started if there are no players in-game.
  void Start();

  // ChatEventListener implementation.
  virtual bool OnPlayerText(Player* player, const std::string& message, bool cancelled) override;

 protected:
  explicit ReactionTest(Playground* playground);
  virtual ~ReactionTest();

 private:
  // Returns a number of seconds before the next reaction test should start. This is a random amount
  // of time between 2 and 5 minutes, preventing players from knowing when the next test starts.
  TimeSpan GetNextReactionTestDelay() const;

  // Returns the offered prize money for the player solving |question|. The money will be influenced
  // by the complexity of the question, as well by a certain amount of randomness.
  int GetPrizeMoneyForQuestion(const ReactionTestQuestion& question) const;

  // Enables tests to override the available drivers for testing. All currently registered drivers
  // will be removed, and |driver| will be inserted as the only one. Ownership is passed.
  void OverrideDriverForTesting(ReactionTestDriver* driver);

  // Vector of drivers which can produce questions and answers for the reaction tests.
  std::vector<std::unique_ptr<ReactionTestDriver>> drivers_;

  // Id of the driver which is handling the current test, if any. -1 means that no test is active.
  int current_driver_id_;

  // Time at which the current reaction test started.
  Time start_time_;

  // Amount of prize money offered for the player solving the current reaction test.
  int prize_money_;

  // Timer which will trigger creation of the next reaction test.
  Timer timer_;

  FRIEND_TEST(ReactionTestServiceTest, CalculationDriverTest);
  FRIEND_TEST(ReactionTestServiceTest, RandomStringDriverTest);
  FRIEND_TEST(ReactionTestServiceTest, PrizeMoneyComplexityDistribution);
};

#endif  // FEATURES_REACTION_TEST_REACTION_TEST_H_
