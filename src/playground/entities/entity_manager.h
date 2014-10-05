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

#include <iterator>
#include <map>
#include <memory>

// Iterator which powers iteration over the entities owned by an EntityManager. Since the storage
// type for each entity is defined to be an std::map, this iterator only returns the value.
template <class EntityType>
class EntityIterator : public std::iterator<std::input_iterator_tag, EntityType> {
  typedef typename std::map<int, std::unique_ptr<EntityType>>::iterator StorageIterator;

 public:
  EntityIterator(StorageIterator iter)
      : iter_(iter) {}

  // std::input_iterator_tag implementation.
  reference operator*() const { return *(iter_->second.get()); }
  pointer operator->() const { return iter_->second.get(); }

  EntityIterator<EntityType>& operator++() { ++iter_; return *this; }
  bool operator!=(EntityIterator<EntityType> const& other) {
    return iter_ != other.iter_;
  }

 private:
  StorageIterator iter_;
};

// Interface which each entity manager should implement. This ensures that a consistent interface
// will be provided for each type of interface available on the server.
template <class EntityType>
class EntityManager {
 public:
  virtual ~EntityManager() {}

  // Returns a pointer to the entity identified by |entity_id|. May return a nullptr.
  virtual EntityType* Get(int entity_id) = 0;

  // Returns the number of active entities of this type connected to the server.
  virtual int size() const = 0;

  typedef typename EntityIterator<EntityType> iterator;

  // Allows consumers of one of the managers to iterate over the entities owned by it. The players
  // will be ordered by their player Id in the iteration.
  virtual iterator begin() = 0;
  virtual iterator end() = 0;
};

#endif  // PLAYGROUND_ENTITIES_ENTITY_MANAGER_H_
