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

#include "base/logging.h"
#include "base/random.h"
#include "features/reaction_test/drivers/calculation_driver.h"
#include "features/reaction_test/drivers/random_string_driver.h"
#include "features/reaction_test/reaction_test_question.h"
#include "playground/communication/chat_manager.h"
#include "playground/communication/message_builder.h"
#include "playground/entities/player.h"
#include "playground/entities/player_manager.h"
#include "playground/playground.h"
#include "playground/services/service_manager.h"
#include "playground/theme.h"

DEFINE_SERVICE(ReactionTest);

namespace {

// Id representing an invalid reaction test driver.
const int kInvalidDriverId = -1;

}  // namespace

ReactionTest::ReactionTest(Playground* playground)
    : Service(playground),
      current_driver_id_(kInvalidDriverId),
      prize_money_(0),
      timer_(std::bind(&ReactionTest::Start, this)) {
  drivers_.push_back(std::make_unique<CalculationDriver>());
  drivers_.push_back(std::make_unique<RandomStringDriver>());

  chat_manager().AttachEventListener(this);

  int start_delay = configuration().GetInteger("start_delay", 30);
  timer_.Start(TimeSpan::FromSeconds(start_delay), false);
}

ReactionTest::~ReactionTest() {}

// -------------------------------------------------------------------------------------------------

void ReactionTest::Start() {
  DCHECK(drivers_.size()) << "There are no reaction test drivers available.";
  if (!drivers_.size())
    return;

  // Don't start a new reaction tests if there are no players in-game.
  if (!player_manager().size())
    return;

  current_driver_id_ = Random::Next(0, drivers_.size() - 1);
  start_time_ = Time::Now();

  ReactionTestQuestion question = drivers_[current_driver_id_]->CreateQuestion();
  prize_money_ = GetPrizeMoneyForQuestion(question);

  // The first person to {action} {question} wins ${amount}.
  MessageBuilder message("The first player to ", theme::kReactionTestColor);
  message.Append(question.action)
         .Append(" ")
         .Append(question.question, theme::kReactionTestHighlightColor)
         .Append(" wins ")
         .AppendMoney(prize_money_, theme::kReactionTestHighlightColor)
         .Append(".");

  chat_manager().DistributeMessage(message);

  // Schedule the next reaction test in case no one provides a valid answer.
  timer_.Start(GetNextReactionTestDelay(), false);
}

// -------------------------------------------------------------------------------------------------

bool ReactionTest::OnPlayerText(Player* player, const std::string& message, bool cancelled) {
  if (cancelled)
    return false;  // ignore messages which are blocked by other systems.

  if (current_driver_id_ == kInvalidDriverId)
    return true;  // don't check this message if there isn't an active reaction test right now.

  if (!drivers_[current_driver_id_]->IsCorrect(message))
    return true;  // the message does not contain the correct answer.
 
  double duration = static_cast<double>((Time::Now() - start_time_).InMilliseconds()) / 1000.0;
  
  // {player} has won the reaction test in {time} seconds. Congratulations!
  MessageBuilder congratulation(theme::kReactionTestColor);
  congratulation.Append(player->name(), theme::kReactionTestHighlightColor)
                .Append(" has won the reaction test in ")
                .Append(duration, theme::kReactionTestHighlightColor)
                .Append(" seconds. Congratulations!");

  chat_manager().DistributeMessage(congratulation);

  player->GiveMoney(prize_money_);

  current_driver_id_ = kInvalidDriverId;
  return true;
}

// -------------------------------------------------------------------------------------------------

TimeSpan ReactionTest::GetNextReactionTestDelay() const {
  int minimum_delay = configuration().GetInteger("minimum_delay", 120);
  int maximum_delay = configuration().GetInteger("maximum_delay", 300);

  return TimeSpan::FromSeconds(Random::Next(minimum_delay, maximum_delay));
}

int ReactionTest::GetPrizeMoneyForQuestion(const ReactionTestQuestion& question) const {
  int minimum_prize = configuration().GetInteger("minimum_prize", 7500);
  int maximum_prize = configuration().GetInteger("maximum_prize", 15000);
  double multiplier = 1.0;

  switch (question.complexity) {
  case ReactionTestQuestion::EasyQuestion:
    multiplier = configuration().GetDouble("multiplier_easy", 0.75);
    break;
  case ReactionTestQuestion::NormalQuestion:
    multiplier = configuration().GetDouble("multiplier_normal", 1.0);
    break;
  case ReactionTestQuestion::HardQuestion:
    multiplier = configuration().GetDouble("multiplier_hard", 1.25);
    break;
  }

  return static_cast<int>(multiplier * Random::Next(minimum_prize, maximum_prize));
}

void ReactionTest::OverrideDriverForTesting(ReactionTestDriver* driver) {
  drivers_.clear();

  DCHECK(driver);
  drivers_.push_back(std::unique_ptr<ReactionTestDriver>(driver));
}
