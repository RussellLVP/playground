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

#include <stdio.h>

#include "launcher/samp_plugin.h"

#if defined(WINDOWS)
#define MODULE_NAME "playground.dll"
#else // !defined(WINDOWS)
#define MODULE_NAME "playground.so"
#endif

int main() {
  SampPlugin plugin;
  if (!plugin.LoadPlugin(MODULE_NAME) ||
      !plugin.Load())
    return 1;

  // TODO(Russell): Do something useful here.

  plugin.Unload();

#if defined(WINDOWS)
  system("PAUSE");
#endif

  return 0;
}
