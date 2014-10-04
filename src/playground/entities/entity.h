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

#ifndef PLAYGROUND_ENTITIES_ENTITY_H_
#define PLAYGROUND_ENTITIES_ENTITY_H_

// Interface which each entity should implement, to ensure that common accessors between different
// types of entities are consistent.
class Entity {
 public:
  virtual ~Entity() {}

  // Returns the unique Id (among the type) this entity can be identified by.
  virtual int id() const = 0;
};

#endif  // PLAYGROUND_ENTITIES_ENTITY_H_
