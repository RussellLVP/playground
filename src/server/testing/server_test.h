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

#ifndef SERVER_TESTING_SERVER_TEST_H_
#define SERVER_TESTING_SERVER_TEST_H_

#include <string>

#include "gtest/gtest.h"

class Playground;

// Server tests are large tests which will have an entirely new server environment set up for them.
// Put in different words, the server will be empty, with no players or entities. Tests may rely on
// certain SA-MP native functions being available (even though there is no SA-MP server).
class ServerTest : public ::testing::Test {
 protected:
  virtual ~ServerTest();

  // Connects a new player named |nickname| from |ip_address|. Their Id will be returned.
  int ConnectPlayer(const std::string& nickname,
                    const std::string& ip_address = "127.0.0.1");

  // Makes the player with |player_id| say |message|. Returns whether the message was allowed to be
  // displayed in the chat windows of other players.
  bool Say(int player_id, const std::string& message);

  // Disconnects |player_id| from the server.
  void DisconnectPlayer(int player_id);

  // Returns the active Playground instance. This is a deliberate layering violation.
  Playground* playground() const;

  // The SetUp method will be called before a test runs, whereas the TearDown method will be called
  // after the test. They control the lifetime of the server environment for the test.
  virtual void SetUp() override;
  virtual void TearDown() override;
};

#endif  // SERVER_TESTING_SERVER_TEST_H_
