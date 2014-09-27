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
    Takes a single include file from the SA-MP scripting SDK and writes the C++ header and
    implementation files which can be dropped in the //server/bindings/ directory.

    Example usage:
        write_bindings.py --header "players.h" --impl "players.cpp" a_players.inc

"""

import argparse
import os
import re
import sys
import time

from collections import deque
from string import maketrans

# Copyright header which should be written to the generated bindings.
COPYRIGHT_HEADER = """/**
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
 */"""

# Translation table used for creating header guards.
HEADER_GUARD_TRANSLATION_TABLE = maketrans('/\\.', '___')

# Parses the contents of |pawn_file| to constants and native methods.
class PawnBindingParser(object):
    def __init__(self, pawn_file):
        self.pawn_file_ = self._GetFileContents(pawn_file)
        self.constants_ = []
        self.natives_ = []

        while len(self.pawn_file_):
            self._ParseNextLine()

    def GetConstants(self):
        return self.constants_

    def GetNatives(self):
        return self.natives_

    def _ParseNextLine(self):
        line = self.pawn_file_.popleft()
        if line.startswith('native'):
            self._ParseNative(line)
        elif line.startswith('#define'):
            self._ParseConstant(line)
        elif line.startswith('enum'):
            print('WARNING: Skipping enumeration.')

    def _ParseNative(self, line):
        """Parses |line| containing a native function definition in to a structure similar to:
           { name: 'MyNative',
             type: 'integer',
             arguments: [
               { name: 'playerid', type: 'integer' },
               { name: 'nickname', type: 'string' },
               { name: 'positionX', type: 'float', reference: true },
               { name: 'forcesync', type: 'integer', default: '0' }
             ]
           }
        """

        if line.find(':operator') is not -1:
            return  # no need to generate bindings for operators.

        line = re.sub('\s*//.*', '', line)
        if not line.endswith(');'):
            print 'Unable to parse the following native declaration:'
            print line
            sys.exit(0)

        name, arguments = line[7:-2].split('(')
        type = 'integer'

        if name.find(':') is not -1:
            type, name = name.split(':')

        # Filter out type definitions such as "{Float,_}:" because they carry no value to us.
        arguments = re.sub('{.+?}:', '', arguments);

        args = []
        for argument in arguments.split(','):
            if not len(argument):
                continue

            args.append(self._ParseNativeArgument(argument))

        self.natives_.append({
            'name': name,
            'type': type,
            'arguments': args
        })

    def _ParseNativeArgument(self, argument):
        """Parses |argument| in a structure containing information about the argument."""
        argument = argument.strip()

        const = argument.startswith('const')
        if const:
            argument = argument[5:].strip()

        reference = argument.startswith('&')
        if reference:
            argument = argument.lstrip('&')

        type = 'integer'

        if argument.find(':') is not -1:
            type, argument = argument.split(':', 2)
        elif argument.find('[]') is not -1:
            argument = argument.replace('[]', '')
            type = 'string'

        default = None
        if argument.find('=') is not -1:
            argument, default = re.split('\s*=\s*', argument)

        return { 'name': argument,
                 'type': type,
                 'reference': reference,
                 'const': const,
                 'default': default }

    def _ParseConstant(self, line):
        """Parses |line| in a constant definition, creating a structure similar to:
           { name: 'MyConstant',
             value: '12'
           }"""

        line = re.sub('\s*//.*', '', line)
        line = line[8:].strip()

        # Ignore the "_file_included" defines, and other defines without a value.
        if line.find(' ') is -1 and line.find('\t') is -1:
            return

        name, value = re.split('\s+', line, 2)
        self.constants_.append({
            'name': name,
            'value': value
        })

    def _GetFileContents(self, pawn_file):
        if not os.path.isfile(pawn_file):
            print 'Cannot open file "%s" for reading: it does not exist.' % pawn_file
            sys.exit(1)

        with open(pawn_file, 'r') as file:
            return deque(file.read().splitlines())


def RepositoryPathForBinding(filename):
    return os.path.join('server', 'bindings', os.path.basename(filename))


# C++ type for the given Pawn type
CPP_TYPE_FOR_PAWN_TYPE = {
    'bool': 'bool',
    'float': 'float',
    'integer': 'int',
    'string': 'char*',

    # Custom types
    'db': 'int',
    'dbresult': 'int',
    'file': 'int',
    'menu': 'int',
    'playertext3d': 'int',
    'text': 'int',
    'text3d': 'int',

    # TODO(Russell): Replace with real enums
    'anglemode': 'int',
    'filemode': 'int',
    'floatround_method': 'int',
    'seek_whence': 'int'
}

def PrototypeForNative(native):
    prototype = ''
    prototype += CPP_TYPE_FOR_PAWN_TYPE[native['type'].lower()] + ' '

    # Fix for the native named "float", which converts a Pawn integer to a Pawn float.
    if native['name'] == 'float':
        native['name'] = '_float'

    prototype += native['name']
    prototype += '('

    args = []
    for argument in native['arguments']:
        if argument['name'] == '...':  # varargs
            args.append('...')
            continue

        arg = CPP_TYPE_FOR_PAWN_TYPE[argument['type'].lower()]
        if argument['reference']:
            arg += '*'

        arg += ' '
        arg += argument['name']

        args.append(arg)

    prototype += ', '.join(args)
    prototype += ')'

    return prototype

def WriteBindings(pawn_file, header_file, implementation_file):
    contents = PawnBindingParser(pawn_file)

    WriteBindingsHeader(header_file, contents)
    WriteBindingsImplementation(implementation_file, contents)

def WriteBindingsHeader(header_file, contents):
    lines = [COPYRIGHT_HEADER, '']

    header_guard = '%s_' % RepositoryPathForBinding(header_file).translate(HEADER_GUARD_TRANSLATION_TABLE).upper()

    lines.append('#ifndef %s' % header_guard)
    lines.append('#define %s' % header_guard)
    lines.append('')

    lines.append('// Generated on %s.' % time.strftime('%Y-%m-%d at %H:%M:%S %Z'))
    lines.append('// Do not modify by hand, instead, look at /scripts/write_bindings.py.')
    lines.append('namespace samp {')
    lines.append('')

    constants = contents.GetConstants()
    if constants:
        for define in constants:
            lines.append('#define %s %s' % (define['name'], define['value']))

        lines.append('')

    for native in contents.GetNatives():
        lines.append('%s;' % PrototypeForNative(native))
        lines.append('')

    lines.append('}  // namespace samp')
    lines.append('')

    lines.append('#endif  // %s' % header_guard)
    lines.append('')

    with open(header_file, 'w') as file:
        file.write('\n'.join(lines))

def WriteBindingsImplementation(implementation_file, contents):
    pass

if __name__ == "__main__":
    arguments = argparse.ArgumentParser(description='Converts a SA-MP header to C++ bindings.')
    arguments.add_argument('--header', default='bindings.h', help='Header file to generate.')
    arguments.add_argument('--impl', default='bindings.cpp', help='Implementation file to generate.')
    arguments.add_argument('input', help='Pawn header file to parse.')

    args = arguments.parse_args()
    WriteBindings(args.input, args.header, args.impl)
