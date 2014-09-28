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

// In order to avoid changing the stack state of the real AMX instances which run the Pawn gamemode,
// we use a mocked AMX structure containing our own stack space.
class MockAMX : public AMX {
 public:
  MockAMX();
  ~MockAMX();

 private:
  AMX_HEADER header_;
  void* heap_;
};

#endif  // SERVER_BINDINGS_INTERNAL_MOCK_AMX_H_
