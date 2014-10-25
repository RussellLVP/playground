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

#ifndef BASE_COLOR_H_
#define BASE_COLOR_H_

// Represents an opaque color through its individual components.
struct Color {
  Color()
      : R(0),
        G(0),
        B(0) {}

  Color(unsigned char R, unsigned char G, unsigned char B)
      : R(R),
        G(G),
        B(B) {}

  Color(const Color& other)
      : R(other.R),
        G(other.G),
        B(other.B) {}

  bool operator==(const Color& other) {
    return other.R == R &&
           other.G == G &&
           other.B == B;
  }

  bool operator!=(const Color& other) {
    return other.R != R ||
           other.G != G ||
           other.B != B;
  }

  unsigned char R;
  unsigned char G;
  unsigned char B;
};

#endif  // BASE_COLOR_H_
