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

#include "base/random.h"

#include <memory>
#include <random>

#include "base/macros.h"

namespace {
THREAD_LOCAL std::random_device* g_random_device;
THREAD_LOCAL std::mt19937* g_random_engine;
THREAD_LOCAL bool g_thread_initialized = false;

// TODO(Russell): We leak memory here (sizeof(std::random_device)+sizeof(std::mt19937) per thread).
// This probably is OK, but it would be nicer if we'd have a way of cleaning this up as well.
void InitializeThreadRandomIfNecessary() {
  if (g_thread_initialized)
    return;

  g_random_device = new std::random_device;
  g_random_engine = new std::mt19937((*g_random_device)());
  g_thread_initialized = true;
}

}

// static
double Random::Next() {
  InitializeThreadRandomIfNecessary();

  std::uniform_real_distribution<> generator(0, 1);
  return generator(*g_random_engine);
}

// static
int Random::Next(int start, int end) {
  InitializeThreadRandomIfNecessary();

  std::uniform_int_distribution<> generator(start, end);
  return generator(*g_random_engine);
}
