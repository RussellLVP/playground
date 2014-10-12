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

#ifndef PLAYGROUND_ENTITIES_PLAYER_MANAGER_H_
#define PLAYGROUND_ENTITIES_PLAYER_MANAGER_H_

#include <map>
#include <memory>
#include <string>

#include "base/macros.h"
#include "playground/entities/entity_manager.h"
#include "server/listeners/player_event_listener.h"

class Player;
class PlayerEventListener;

// The Player manager keeps track of all the players which are connected to Las Venturas Playground,
// and receives and delegates events related to them. It provides methods to query the players.
class PlayerManager final : public EntityManager<Player, PlayerEventListener>,
                            public samp::PlayerEventListener {
 public:
  PlayerManager();
  virtual ~PlayerManager();

  // Returns whether the player with Id |player_id| or name |name| is connected to the server.
  bool IsConnected(int player_id) const;
  bool IsConnected(const std::string& name) const;

  // Returns the connected player identified by |name|. May return a nullptr if they're not online.
  Player* Get(const std::string& name);

  // EntityManager implementation.
  virtual Player* Get(int player_id) override;
  virtual void AttachEventListener(EventListener* listener) override;
  virtual int size() const override;
  virtual iterator begin() override { return iterator(players_.begin()); }
  virtual iterator end() override { return iterator(players_.end()); }

 private:
  // PlayerEventListener implementation.
  virtual void OnPlayerConnect(int player_id) override;
  virtual void OnPlayerDisconnect(int player_id, int reason) override;

 private:
  std::map<int, std::unique_ptr<Player>> players_;

  DISALLOW_COPY_AND_ASSIGN(PlayerManager);
};

#endif  // PLAYGROUND_ENTITIES_PLAYER_MANAGER_H_
