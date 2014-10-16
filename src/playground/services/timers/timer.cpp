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

#include "playground/services/timers/timer.h"

#include "playground/services/timers/thread_timer_manager.h"

Timer::Timer(const CallbackType& callback)
    : callback_(callback),
      is_repeating_(false),
      is_orphan_(false) {}

Timer::~Timer() {}

void Timer::Start(TimeSpan interval, bool repeating) {

}

void Timer::Stop() {

}

bool Timer::IsActive() const {
  return false;
}
