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

#include <algorithm>
#include <memory>

#include "base/logging.h"

namespace {

const unsigned int kStackSize = 128;
const unsigned int kHeapSize = 16 * 1024;  // 16384 cells, 65KiB of memory.

const unsigned int kStringLength = 2048;

}  // namespace

MockAMX::MockAMX() {
  memset(this, 0, sizeof(AMX) + sizeof(AMX_HEADER));

  heap_ = static_cast<cell*>(calloc(kStackSize + kHeapSize, 1));

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

// -------------------------------------------------------------------------------------------------

void MockAMX::PushState() {
  HeapState state;
  state.hea = hea;

  pushed_states_.push(state);
}

void MockAMX::PopState() {
  DCHECK(!pushed_states_.empty());

  HeapState state = pushed_states_.top();
  hea = state.hea;

  pushed_states_.pop();
}

// -------------------------------------------------------------------------------------------------

void MockAMX::Push(cell value, cell* address) {
  CHECK((hea + sizeof(cell)) < (kHeapSize * sizeof(cell))) << "Mocked AMX heap overflow detected (cell).";
  CHECK(address);

  *address = hea;

  hea += sizeof(cell);
  heap_[*address / sizeof(cell)] = value;
}

void MockAMX::Push(const std::string& value, cell* address) {
  unsigned int length = std::max(kStringLength, value.length());

  CHECK((hea + 1 + length * sizeof(cell)) < (kHeapSize * sizeof(cell))) << "Mocked AMX heap overflow detected (string).";
  CHECK(address);

  *address = hea;
  hea += (length + 1) * sizeof(cell);

  unsigned int start = *address / sizeof(cell);
  for (unsigned int index = 0; index < value.length(); ++index)
    heap_[start + index] = value[index];

  heap_[start + length] = 0;
}

// -------------------------------------------------------------------------------------------------

void MockAMX::Read(cell address, cell* value) const {
  CHECK(address < (kHeapSize * sizeof(cell)));
  CHECK(value);

  *value = heap_[address / sizeof(cell)];
}

void MockAMX::Read(cell address, std::string* value) const {
  CHECK(address < (kHeapSize * sizeof(cell)));
  CHECK(value);

  const cell* string = &heap_[address / sizeof(cell)];
  unsigned int length = 0;

  while (string[length])
    ++length;

  if (value->length() != length)
    value->resize(length);

  for (unsigned int index = 0; index < length; ++index)
    (*value)[index] = string[index];
}
