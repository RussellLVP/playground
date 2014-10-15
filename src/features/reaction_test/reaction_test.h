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

#include <string>

#include "playground/services/service.h"

// The reaction test feature sends an occasional puzzle to the connected players, a valid answer to
// which will make them some money. The puzzle can be of repetitive nature ("copy this string") or
// of mathematical nature ("calculate (60 - 15) * 2").
class ReactionTest : public Service {
  DECLARE_SERVICE(ReactionTest);

 protected:
  explicit ReactionTest(Playground* playground)
      : Service(playground) {}

  // Called when the reaction test service has been installed.
  virtual void OnServiceInstalled() override;
};

#endif  // FEATURES_REACTION_TEST_REACTION_TEST_H_
