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

#ifndef PLAYGROUND_THEME_COLORS_H_
#define PLAYGROUND_THEME_COLORS_H_

#include "base/color.h"

// Defines the theme colors to use on Las Venturas Playground. These colors are defined based on
// their purpose and should be used by features and components rather than them choosing their own.
namespace theme {

// -----------------------------------------------------------------------------------------------
// Colors in this namespace must have been approved by a lead developer.
// -----------------------------------------------------------------------------------------------

extern const Color kDefaultTextColor;

extern const Color kReactionTestColor;
extern const Color kReactionTestHighlightColor;

}  // namespace theme

#endif  // PLAYGROUND_THEME_COLORS_H_
