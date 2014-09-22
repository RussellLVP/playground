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

#include "playground/playground_export.h"

typedef struct AMX AMX;

PLAYGROUND_EXPORT(bool) Load(void** data) {
  printf("Playground::Load()\n");
  return true;
}

PLAYGROUND_EXPORT(void) Unload() {
  printf("Playground::Unload()\n");
}

PLAYGROUND_EXPORT(unsigned int) Supports() {
  printf("Playground::Supports()\n");
  return 0;
}

PLAYGROUND_EXPORT(int) AmxLoad(AMX* amx) {
  printf("Playground::AmxLoad()\n");
  return 0;
}

PLAYGROUND_EXPORT(int) AmxUnload(AMX* amx) {
  printf("Playground::AmxUnload()\n");
  return 0;
}

PLAYGROUND_EXPORT(void) ProcessTick() {
  printf("Playground::ProcessTick()\n");
}
