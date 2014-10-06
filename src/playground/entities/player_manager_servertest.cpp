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

#include "server/testing/server_test.h"

#include "playground/entities/player.h"
#include "playground/entities/player_manager.h"
#include "playground/playground.h"

namespace {

class PlayerManagerServerTest : public ServerTest {
 protected:
  PlayerManager& player_manager() const {
    return playground()->player_manager();
  }
};

}  // namespace

TEST_F(PlayerManagerServerTest, ConnectDisconnect) {
  EXPECT_EQ(0, player_manager().size());

  int player_id = ConnectPlayer("CJ");
  ASSERT_EQ(1, player_manager().size());

  Player* player = player_manager().Get(player_id);
  ASSERT_TRUE(player != nullptr);

  EXPECT_EQ(player_id, player->id());
  EXPECT_EQ("CJ", player->name());
  EXPECT_EQ("127.0.0.1", player->ip_address());

  Player* player2 = player_manager().Get("CJ");
  EXPECT_EQ(player, player2);

  DisconnectPlayer(player_id);
  ASSERT_EQ(0, player_manager().size());
}

TEST_F(PlayerManagerServerTest, Iterator) {
  EXPECT_EQ(0, player_manager().size());

  ConnectPlayer("CJ");
  ConnectPlayer("Big_Smoke");

  ASSERT_EQ(2, player_manager().size());

  int count = 0, checks = 0;
  for (const auto& player : player_manager()) {
    EXPECT_TRUE(player.id() == 0 ||
                player.id() == 1);
    ++count;
  }

  EXPECT_EQ(count, 2);
  count = 0;

  for (auto& player : player_manager()) {
    EXPECT_TRUE(player.id() == 0 ||
                player.id() == 1);
    ++count;
  }

  EXPECT_EQ(count, 2);
}
