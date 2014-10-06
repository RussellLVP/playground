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

#ifndef BASE_VECTOR3D_H_
#define BASE_VECTOR3D_H_

// Contains a 3-dimensional representation of a position in the world. One noteworthy item is that
// Rockstar switched the Y and Z axes in Grand Theft Auto, so use "z" to indicate height.
struct Vector3D {
  Vector3D(double x, double y, double z)
      : x(x), y(y), z(z) {}

  Vector3D()
      : x(0), y(0), z(0) {}

  double x;
  double y;
  double z;
};

#endif  // BASE_VECTOR3D_H_
