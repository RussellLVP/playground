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

#include "server/bindings/internal/mock_amx.h"

#define _STDINT  // Pawn's definitions conflict with the native ones.
#include <memory>

namespace {

const int kStackSize = 128;
const int kHeapSize = 1024;

}  // namespace

MockAMX::MockAMX() {
  memset(this, 0, sizeof(MockAMX));

  heap_ = calloc(kStackSize + kHeapSize, 1);

  base = reinterpret_cast<unsigned char*>(&header_);
  data = nullptr;
  callback = amx_Callback;
  stp = stk = (kStackSize + kHeapSize) * sizeof(cell);

  header_.magic = AMX_MAGIC;
  header_.file_version = MIN_FILE_VERSION;
  header_.amx_version = MIN_AMX_VERSION;
  header_.defsize = sizeof(AMX_FUNCSTUBNT);
  header_.dat = reinterpret_cast<int32_t>(heap_) - reinterpret_cast<int32_t>(&header_);
}

MockAMX::~MockAMX() {
  delete heap_;
}
