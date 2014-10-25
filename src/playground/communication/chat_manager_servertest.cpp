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

#include "playground/communication/chat_manager.h"

#include <string>
#include <vector>

#include "base/logging.h"
#include "server/testing/server_test.h"
#include "playground/communication/chat_event_listener.h"
#include "playground/playground.h"

using namespace logging;

namespace {

const char kDefaultMessage[] = "Hello, world!";

}  // namespace

class ChatManagerServerTest : public ServerTest,
                              public ChatEventListener {
 public:
  virtual ~ChatManagerServerTest() {}

  const std::vector<std::string>& messages() { return messages_; }

  // ServerTest overrides.
  virtual void SetUp() override {
    ServerTest::SetUp();

    previous_log_level_ = LogMessage::GetMinimumLogSeverity();
    LogMessage::SetMinimumLogSeverity(LOG_ERROR);

    playground()->chat_manager().AttachEventListener(this);
    messages_.clear();
  }

  virtual void TearDown() override {
    LogMessage::SetMinimumLogSeverity(previous_log_level_);
    ServerTest::TearDown();
  }

  // ChatEventListener implementation.
  virtual bool OnPlayerText(Player* player, const std::string& message, bool cancelled) override {
    messages_.push_back(message);
    return true;
  }

 private:
  int previous_log_level_;

  std::vector<std::string> messages_;
};

TEST_F(ChatManagerServerTest, IgnoreInvalidPlayers) {
  ASSERT_EQ(0, messages().size());
  Say(0, kDefaultMessage);
  EXPECT_EQ(0, messages().size());

  int player_id = ConnectPlayer("CJ");
  Say(player_id, kDefaultMessage);
  EXPECT_EQ(1, messages().size());

  Say(player_id + 1, kDefaultMessage);
  EXPECT_EQ(1, messages().size());
}

TEST_F(ChatManagerServerTest, IgnoreEmptyMessages) {
  ASSERT_EQ(0, messages().size());
  
  int player_id = ConnectPlayer("CJ");
  Say(player_id, kDefaultMessage);
  EXPECT_EQ(1, messages().size());

  Say(player_id, "");
  EXPECT_EQ(1, messages().size());

  Say(player_id + 1, "");
  EXPECT_EQ(1, messages().size());
}
