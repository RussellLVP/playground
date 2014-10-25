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

#include "base/vector3d.h"
#include "playground/entities/player.h"
#include "playground/entities/player_manager.h"
#include "playground/playground.h"

namespace {

class PlayerServerTest : public ServerTest {
 protected:
  virtual void SetUp() override {
    ServerTest::SetUp();

    player_id_ = ConnectPlayer("CJ");
    player_ = playground()->player_manager().Get(player_id_);
    ASSERT_TRUE(player_ != nullptr);
  }

  int player_id() { return player_id_; }
  Player& player() { return *player_; }

 private:
  int player_id_;
  Player* player_;
};

}  // namespace

TEST_F(PlayerServerTest, EntityFunctionality) {
  EXPECT_EQ(player().id(), player_id());

  player().SetPosition(Vector3D(10.0, 20.0, 30.0));

  Vector3D position;
  player().GetPosition(&position);
  EXPECT_DOUBLE_EQ(position.x, 10.0);
  EXPECT_DOUBLE_EQ(position.y, 20.0);
  EXPECT_DOUBLE_EQ(position.z, 30.0);

  player().SetInteriorId(11);
  EXPECT_EQ(11, player().GetInteriorId());

  player().SetVirtualWorldId(12);
  EXPECT_EQ(12, player().GetVirtualWorldId());
}

TEST_F(PlayerServerTest, BasicPlayerFunctionality) {
  EXPECT_EQ("CJ", player().name());
  EXPECT_EQ("127.0.0.1", player().ip_address());

  player().SetHealth(50);
  EXPECT_DOUBLE_EQ(50, player().GetHealth());

  player().SetArmour(60);
  EXPECT_DOUBLE_EQ(60, player().GetArmour());

  player().SetMoney(1500);
  EXPECT_EQ(1500, player().GetMoney());

  player().GiveMoney(500);
  EXPECT_EQ(2000, player().GetMoney());

  player().GiveMoney(-1000);
  EXPECT_EQ(1000, player().GetMoney());

  player().SetMoney(0);
  EXPECT_EQ(0, player().GetMoney());
}
