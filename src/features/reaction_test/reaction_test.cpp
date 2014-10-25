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

#include "base/random.h"
#include "playground/services/service_manager.h"

DEFINE_SERVICE(ReactionTest);

ReactionTest::ReactionTest(Playground* playground)
    : Service(playground),
      timer_(std::bind(&ReactionTest::Start, this)) {
  int start_delay = configuration().GetInteger("start_delay", 30);
  timer_.Start(TimeSpan::FromSeconds(start_delay), false);
}

void ReactionTest::Start() {
  // TODO(Russell): Actually start a new reaction test.
  timer_.Start(GetNextReactionTestDelay(), false);
}

TimeSpan ReactionTest::GetNextReactionTestDelay() {
  int minimum_delay = configuration().GetInteger("minimum_delay", 120);
  int maximum_delay = configuration().GetInteger("maximum_delay", 300);

  return TimeSpan::FromSeconds(Random::Next(minimum_delay, maximum_delay));
}
