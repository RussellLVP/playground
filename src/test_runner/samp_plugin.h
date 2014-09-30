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

#ifndef TEST_RUNNER_SAMP_PLUGIN_LOADER_H_
#define TEST_RUNNER_SAMP_PLUGIN_LOADER_H_

#if defined(WINDOWS)
#include <Windows.h>
#endif

class TestController;

// TODO(Russell): Replace this with some minimalistic but real AMX runtime.
typedef struct AMX AMX;

// Values of the flags which could be supported by the plugin. The Supports() function will return
// an OR'ed list of these values.
enum PluginSupportFlags {
  PluginVersion               = 0x0200,
  PluginVersionMask           = 0xFFFF,
  PluginSupportsAmxNatives    = 0x10000,
  PluginSupportsProcessTick   = 0x20000
};

// Loads a given plugin, which must conform to the architecture and exported functions of a SA-MP
// plugin, as a plugin. The loader will automatically free the library in the destructor.
//
// A module is deemed value if all of the following are true:
//   (1) It is a valid .so/.dll file which can be loaded in to this process.
//   (2) It exports a symbol called Load, taking no arguments and not returning anything.
//   (3) It exports a symbol called Supports, taking no arguments and returning an unsigned int.
class SampPlugin {
 public:
  SampPlugin();
  ~SampPlugin();

  // Loads |module_name| as a SA-MP plugin, and validates that it conforms to the specifications.
  bool LoadPlugin(const char* module_file);

  // Should be called immediately after the plugin has loaded. This function is required for
  // plugins to export in order to conform to SA-MP's architecture.
  bool Load();

  // Should be called immediately before the plugin will be unloaded.
  void Unload();

  // Returns an OR'ed list of SA-MP's SUPPORTS_FLAGS enumeration.
  unsigned int Supports();

  // Indicates to the plugin that |amx| has been loaded in the scripting engine.
  int AmxLoad(AMX* amx);

  // Indicates to the plugin that |amx| will be unloaded from the scripting engine.
  int AmxUnload(AMX* amx);

  // Indicates to the plugin that the main thread of the server is doing another iteration. It can
  // do work in here, but any work of significance will decrease performance of the server itself.
  void ProcessTick();

  // The Las Venturas Playground gamemode has an additional export, which allows us to get the
  // test controller. This controller may be used to drive tests on the gamemode.
  TestController* CreateTestController();

 private:
  // Addresses of the functions read from the library.
  void* plugin_load_addr_;
  void* plugin_unload_addr_;
  void* plugin_amx_load_addr_;
  void* plugin_amx_unload_addr_;
  void* plugin_supports_addr_;
  void* plugin_process_tick_addr_;
  void* plugin_create_test_controller_addr_;

  // Handle to the module itself. The type of this member is dependant on the host OS.
#if defined(WINDOWS)
  HMODULE module_;
#else
  void* module_;
#endif
};

#endif  // LAUNCHER_SAMP_PLUGIN_LOADER_H_
