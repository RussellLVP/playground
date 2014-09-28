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
        self.enums_ = []
        self.natives_ = []

        while len(self.pawn_file_):
            self._ParseNextLine()

    def GetConstants(self):
        return self.constants_

    def GetEnums(self):
        return self.enums_

    def GetNatives(self):
        return self.natives_

    def IsKnownEnum(self, name):
        for enum in self.enums_:
            if enum['name'] == name:
                return True
        return False

    def IsUsingStrings(self):
        for native in self.natives_:
            for argument in native['arguments']:
                if argument['type'] == 'string':
                    return True
        return False

    def _ParseNextLine(self):
        line = self._GetNextLine()
        if line.startswith('native'):
            self._ParseNative(line)
        elif line.startswith('#define'):
            self._ParseConstant(line)
        elif line.startswith('enum'):
            self._ParseEnum(line)

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

        if not line.endswith(');'):
            print 'Unable to parse the following native declaration:'
            print line
            sys.exit(1)

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
            'name': name.strip(),
            'type': type.strip(),
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

        line = line[8:].strip()

        # Ignore the "_file_included" defines, and other defines without a value.
        if line.find(' ') is -1 and line.find('\t') is -1:
            return

        name, value = re.split('\s+', line, 2)
        self.constants_.append({
            'name': name,
            'value': value
        })

    def _ParseEnum(self, line):
        """Parses |line| and the following lines into an enumeration, creating a structure like:
           { name: 'MyEnumeration',
             values: [ 'Foo', 'Bar', 'Baz' ] }"""

        while line.find('}') == -1:
            line += self._GetNextLine()

        if not line.endswith('}'):
            print 'Unable to parse the following enumeration:'
            print line
            sys.exit(1)

        line = line[5:-1].strip()
        name, line = line.split('{', 2)

        values = []
        for value in line.split(','):
            value = value.strip()
            if not len(value):
                continue

            values.append(value)

        self.enums_.append({
            'name': name.strip(),
            'values': values
        })

    def _GetNextLine(self):
        line = self.pawn_file_.popleft()
        line = re.sub('\s*//.*', '', line)
        line = re.sub('/\*.+?\*/', '', line)

        return line.strip()

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
    'float': 'double',
    'integer': 'int',
    'string': 'std::string&',

    # Custom types
    'db': 'int',
    'dbresult': 'int',
    'file': 'int',
    'menu': 'int',
    'playertext3d': 'int',
    'text': 'int',
    'text3d': 'int'
}

def PrototypeForNative(native, contents):
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

        arg = None
        if contents.IsKnownEnum(argument['type']):
            arg = argument['type']
        else:
            arg = CPP_TYPE_FOR_PAWN_TYPE[argument['type'].lower()]

        if argument['reference']:
            arg += '*'

        arg += ' '
        arg += argument['name']

        args.append(arg)

    prototype += ', '.join(args)
    prototype += ')'

    return prototype

def HasVariableArguments(native):
    for argument in native['arguments']:
        if argument['name'] == '...':
            return True
    return False

def SignatureForNative(native, contents):
    parameters = []
    signature = []

    for argument in native['arguments']:
        if contents.IsKnownEnum(argument['type']):
            parameters.append('static_cast<int>(%s)' % argument['name'])
            signature.append('i')
            continue;

        type = CPP_TYPE_FOR_PAWN_TYPE[argument['type'].lower()]
        if type == 'bool' or type == 'int':
            if type == 'bool':
                parameters.append('static_cast<int>(%s)' % argument['name'])
            else:
                parameters.append(argument['name'])

            if argument['reference']:
                signature.append('I')
            else:
                signature.append('i')
        elif type == 'double':
            parameters.append(argument['name'])
            if argument['reference']:
                signature.append('F')
            else:
                signature.append('f')
        elif type == 'std::string&':
            parameters.append('&%s' % argument['name'])
            signature.append('s')
        else:
            print 'WARNING: Unrecognized type: %s (%s)' % (type, argument['type'])
            continue

    params = ''
    if parameters:
        params = ', ' + ', '.join(parameters)

    return ''.join(signature), params

def WriteBindings(pawn_file, header_file, implementation_file):
    contents = PawnBindingParser(pawn_file)

    WriteBindingsHeader(header_file, contents)
    WriteBindingsImplementation(implementation_file, header_file, contents)

def WriteBindingsHeader(header_file, contents):
    lines = [COPYRIGHT_HEADER, '']

    header_guard = '%s_' % RepositoryPathForBinding(header_file).translate(HEADER_GUARD_TRANSLATION_TABLE).upper()

    lines.append('#ifndef %s' % header_guard)
    lines.append('#define %s' % header_guard)
    lines.append('')

    if contents.IsUsingStrings():
        lines.append('#include <string>')
        lines.append('')

    lines.append('// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.')
    lines.append('namespace samp {')
    lines.append('')

    constants = contents.GetConstants()
    if constants:
        for define in constants:
            lines.append('const int %s = %s;' % (define['name'], define['value']))

        lines.append('')

    for enum in contents.GetEnums():
        lines.append('enum %s {' % enum['name'])
        for value in enum['values']:
            lines.append('  %s,' % value)

        lines.append('};')
        lines.append('')

    for native in contents.GetNatives():
        lines.append('%s;' % PrototypeForNative(native, contents))

    lines.append('')
    lines.append('}  // namespace samp')
    lines.append('')

    lines.append('#endif  // %s' % header_guard)
    lines.append('')

    with open(header_file, 'w') as file:
        file.write('\n'.join(lines))

def WriteBindingsImplementation(implementation_file, header_file, contents):
    if not contents.GetNatives():
        return

    lines = [COPYRIGHT_HEADER, '']

    header = os.path.basename(header_file);
    lines.append('#include "server/bindings/%s"' % header)
    lines.append('')

    lines.append('#include "base/logging.h"')
    lines.append('#include "server/native_function_manager.h"')
    lines.append('')

    lines.append('extern NativeFunctionManager* g_native_function_manager;')
    lines.append('')

    lines.append('// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.')
    lines.append('namespace samp {')
    lines.append('')

    for native in contents.GetNatives():
        lines.append('%s {' % PrototypeForNative(native, contents))
        lines.append('  CHECK(g_native_function_manager);')

        if HasVariableArguments(native):
            lines.append('  CHECK(false) << "Support for Pawn functions with variable argument counts has not been implemented yet.";')
            lines.append('  return 0;')
            lines.append('}')
            lines.append('')
            continue

        signature, parameters = SignatureForNative(native, contents)
        call = 'g_native_function_manager->Invoke("%s", "%s"%s)' % (native['name'], signature, parameters)

        if native['type'] == 'integer':
            lines.append('  return %s;' % call)
        elif native['type'] == 'Float':
            lines.append('  int result = %s;' % call)
            lines.append('  return static_cast<double>(amx_ctof(result));')
        else:
            lines.append('  int result = %s;' % call)
            lines.append('  return * (%s*) &result;' % CPP_TYPE_FOR_PAWN_TYPE[native['type'].lower()])

        lines.append('}')
        lines.append('')

    lines.append('}  // namespace samp')
    lines.append('')

    with open(implementation_file, 'w') as file:
        file.write('\n'.join(lines))

if __name__ == "__main__":
    arguments = argparse.ArgumentParser(description='Converts a SA-MP header to C++ bindings.')
    arguments.add_argument('--header', default='bindings.h', help='Header file to generate.')
    arguments.add_argument('--impl', default='bindings.cpp', help='Implementation file to generate.')
    arguments.add_argument('input', help='Pawn header file to parse.')

    args = arguments.parse_args()
    WriteBindings(args.input, args.header, args.impl)
