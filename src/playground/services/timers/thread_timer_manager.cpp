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

#include "playground/services/timers/thread_timer_manager.h"

#include "base/logging.h"
#include "playground/services/timers/timer.h"

namespace {
// Thread-specific instance of the Timer Manager.
THREAD_LOCAL ThreadTimerManager* g_thread_local_instance = nullptr;
}

// static
ThreadTimerManager* ThreadTimerManager::InstanceForThread() {
  if (!g_thread_local_instance)
    g_thread_local_instance = new ThreadTimerManager();

  return g_thread_local_instance;
}

ThreadTimerManager::ThreadTimerManager() {}

void ThreadTimerManager::Shutdown() {
  MergeTimerQueues();
  while (active_timers_.size()) {
    Timer* active_timer = active_timers_.top();
    active_timers_.pop();

    active_timer->DidRemoveFromManager();
  }

  DCHECK(g_thread_local_instance);
  delete g_thread_local_instance;
  g_thread_local_instance = nullptr;
}

void ThreadTimerManager::RegisterTimer(Timer* timer) {
  new_timers_.push(timer);
}

void ThreadTimerManager::RemoveTimer(Timer* timer) {
  MergeTimerQueues();

  std::priority_queue<Timer*> new_active_timers;
  while (active_timers_.size()) {
    Timer* active_timer = active_timers_.top();
    active_timers_.pop();

    if (active_timer == timer)
      continue;

    new_active_timers.push(active_timer);
  }

  active_timers_.swap(new_active_timers);
}

void ThreadTimerManager::ProcessTimers() {
  MergeTimerQueues();

  Time current_time = Time::Now();
  while (active_timers_.size()) {
    Timer* timer = active_timers_.top();
    if (timer->next_invocation_time() > current_time)
      break;

    active_timers_.pop();
    timer->Invoke();
  }
}

void ThreadTimerManager::MergeTimerQueues() {
  while (new_timers_.size()) {
    active_timers_.push(new_timers_.front());
    new_timers_.pop();
  }
}
