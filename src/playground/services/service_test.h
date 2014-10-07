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

#ifndef PLAYGROUND_SERVICES_SERVICE_TEST_H_
#define PLAYGROUND_SERVICES_SERVICE_TEST_H_

#include "server/testing/server_test.h"

// A service test is a service test optimized to be used for services (features and components). It
// provides a convenient accessor to the service being tested, on top of the functionality already
// available for server tests.
class ServiceTest : public ServerTest {
  // TODO(Russell): Implement an accessor to the service.
};

#endif  // PLAYGROUND_SERVICES_SERVICE_TEST_H_
