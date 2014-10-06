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

#ifndef PLAYGROUND_ENTITIES_PLAYER_H_
#define PLAYGROUND_ENTITIES_PLAYER_H_

#include <string>

#include "base/macros.h"
#include "playground/entities/entity.h"

class Player final : public Entity {
 public:
  explicit Player(int player_id);
  virtual ~Player();

  // Returns the nickname this player has connecting with.
  const std::string& name() const;

  // Returns the IP address which the player is connecting with.
  const std::string& ip_address() const;

  // Entity implementation.
  virtual int id() const override;
  virtual void GetPosition(Vector3D* position) const override;
  virtual void SetPosition(const Vector3D& position) override;
  virtual int GetInteriorId() const override;
  virtual void SetInteriorId(int interior_id) override;
  virtual int GetVirtualWorldId() const override;
  virtual void SetVirtualWorldId(int virtual_world_id) override;

 private:
  int player_id_;

  std::string name_;
  std::string ip_address_;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

#endif  // PLAYGROUND_ENTITIES_PLAYER_H_
