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
      is_active_(false) {}

Timer::~Timer() {
  if (is_active_)
    Stop();
}

void Timer::Start(TimeSpan interval, bool repeating) {
  if (is_active_)
    Stop();

  next_invocation_time_ = Time::Now() + interval;
  invocation_interval_ = interval;
  is_repeating_ = repeating;
  is_active_ = true;

  ThreadTimerManager::InstanceForThread()->RegisterTimer(this);
}

void Timer::Stop() {
  if (!is_active_)
    return;

  ThreadTimerManager::InstanceForThread()->RemoveTimer(this);
  is_active_ = false;
}

void Timer::Invoke() {
  callback_();

  is_active_ = false;
  if (is_repeating_)
    Start(invocation_interval_, true);
}
