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

#ifndef PLAYGROUND_ENTITIES_ENTITY_MANAGER_H_
#define PLAYGROUND_ENTITIES_ENTITY_MANAGER_H_

// Interface which each entity manager should implement. This ensures that a consistent interface
// will be provided for each type of interface available on the server.
template <class EntityType>
class EntityManager {
 public:
  virtual ~EntityManager() {}

  // Returns a pointer to the entity identified by |entity_id|. May return a nullptr.
  virtual EntityType* Get(int entity_id) = 0;

  // Returns the number of active entities of this type connected to the server.
  virtual int GetCount() const = 0;
};

#endif  // PLAYGROUND_ENTITIES_ENTITY_MANAGER_H_
