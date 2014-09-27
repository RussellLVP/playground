#!/usr/bin/env python
#
# Copyright (c) 2006-2014 Las Venturas Playground
#
# This program is free software: you can redistribute it and/or modify it under the terms of the
# GNU General Public License as published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with this program.
# If not, see <http://www.gnu.org/licenses/>.
#

"""
    Creates bindings for all files in the include/ directory.
"""

import os
import sys

import write_bindings

def GenerateBindings(filename, path):
    """Generates the C++ bindings for the Pawn include |filename|."""
    name = filename[0:-4]
    if name.startswith('a_'):
        name = name[2:]

    input = path
    output_header = os.path.join(os.path.dirname(path), '%s.h' % name)
    output_impl = os.path.join(os.path.dirname(path), '%s.cpp' % name)

    write_bindings.WriteBindings(input, output_header, output_impl)


if __name__ == "__main__":
    directory_path = os.path.join(os.path.dirname(__file__), 'include')
    directory_contents = os.listdir(directory_path)

    files = []
    for file_name in directory_contents:
        file_path = os.path.join(directory_path, file_name)

        if file_name == 'README.txt':
            continue  # skip the readme

        if not os.path.isfile(file_path):
            continue  # skip directories

        if not file_name.endswith('.inc'):
            continue  # skip non-include files

        files.append([file_name, file_path])

    if not len(files):
        print 'No header files could be found. Did you follow the instructions in the README.txt'
        print 'file in the "include" directory?'
        sys.exit(1)

    for entry in files:
        print 'Generating bindings for %s...' % entry[0]
        GenerateBindings(entry[0], entry[1])

    sys.exit(0)
