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

#ifndef BASE_RANDOM_H_
#define BASE_RANDOM_H_

// Generates random numbers using a the Mersenne Twister algorithm. The random number generator is
// safe to use from any thread, and will initialize itself when necessary.
class Random {
 public:
  // Returns a random number between 0 and 1, as a double.
  static double Next();

  // Returns a random number between |start| and |end|, as an integer.
  static int Next(int start, int end);
};

#endif  // BASE_RANDOM_H_
