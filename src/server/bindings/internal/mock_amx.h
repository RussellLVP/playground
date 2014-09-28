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

#ifndef SERVER_BINDINGS_INTERNAL_MOCK_AMX_H_
#define SERVER_BINDINGS_INTERNAL_MOCK_AMX_H_

#include "server/sdk/amx.h"

#include <stack>
#include <string>

// In order to avoid changing the stack state of the real AMX instances which run the Pawn gamemode,
// we use a mocked AMX structure containing our own stack space.
class MockAMX : public AMX {
 public:
  MockAMX();
  ~MockAMX();

  // Stores the current state of the mocked AMX' heap, which can be reset using PopState(). The
  // state will be pushed on a stack in case calls are reentrant (which should be rare). By
  // restoring the previous state, we don't have to care about per-argument cleanup.
  void PushState();
  void PopState();

  // Pushes |value| on the heap of the AMX, storing the address in |address|.
  void Push(cell value, cell* address);
  void Push(const std::string& value, cell* address);

  // Reads the value stored in |address| from the heap and stores it in |value|.
  void Read(cell address, cell* value) const;
  void Read(cell address, std::string* value) const;

 private:
  AMX_HEADER header_;
  cell* heap_;

  // Serialized version of the heap state at the time of a push.
  struct HeapState {
    cell hea;
  };

  std::stack<HeapState> pushed_states_;
};

#endif  // SERVER_BINDINGS_INTERNAL_MOCK_AMX_H_
