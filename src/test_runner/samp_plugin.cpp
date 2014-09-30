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

#include "test_runner/samp_plugin.h"

namespace {

#if defined(WINDOWS)

#define PLUGIN_CALL_TYPE __stdcall

HMODULE LoadModuleFile(const char* module_file) {
  return LoadLibrary(module_file);
}

void UnloadModule(HMODULE module) {
  FreeLibrary(module);
}

void* GetModuleFunctionAddr(HMODULE module, const char* function) {
  return GetProcAddress(module, function);
}

#else  // !defined(WINDOWS)

#include <dlfcn.h>

#define PLUGIN_CALL_TYPE

void* LoadModuleFile(const char* module_file) {
  return dlopen(module_file, RTLD_LAZY);
}

void UnloadModule(void* module) {
  dlclose(module);
}

void* GetModuleFunctionAddr(void* module, const char* function) {
  return dlsym(module, function);
}

#endif

}  // namespace

// Type definitions for the methods exported by the plugin.
typedef bool(PLUGIN_CALL_TYPE * PluginLoadCall)(void** data);
typedef void(PLUGIN_CALL_TYPE * PluginUnloadCall)();
typedef int(PLUGIN_CALL_TYPE * PluginAmxLoadCall)(AMX* amx);
typedef int(PLUGIN_CALL_TYPE * PluginAmxUnloadCall)(AMX* amx);
typedef unsigned int(PLUGIN_CALL_TYPE * PluginSupportsCall)();
typedef void(PLUGIN_CALL_TYPE * PluginProcessTickCall)();
typedef TestController*(PLUGIN_CALL_TYPE * PluginCreateTestControllerCall)();

SampPlugin::SampPlugin()
    : plugin_load_addr_(nullptr),
      plugin_unload_addr_(nullptr),
      plugin_amx_load_addr_(nullptr),
      plugin_amx_unload_addr_(nullptr),
      plugin_supports_addr_(nullptr),
      plugin_process_tick_addr_(nullptr),
      plugin_create_test_controller_addr_(nullptr),
      module_(NULL) {
}

SampPlugin::~SampPlugin() {
  if (!module_)
    return;

  UnloadModule(module_);
  module_ = NULL;
}

bool SampPlugin::LoadPlugin(const char* module_file) {
  module_ = LoadModuleFile(module_file);
  if (!module_) {
    printf("Unable to load %s...\n", module_file);
    return false;
  }

  plugin_load_addr_ = GetModuleFunctionAddr(module_, "Load");
  if (!plugin_load_addr_) {
    printf("The module (%s) must specify a Load() export.\n", module_file);
    return false;
  }

  plugin_supports_addr_ = GetModuleFunctionAddr(module_, "Supports");
  if (!plugin_supports_addr_) {
    printf("The module (%s) must specify a Supports() export.\n", module_file);
    return false;
  }

  plugin_unload_addr_ = GetModuleFunctionAddr(module_, "Unload");
  plugin_amx_load_addr_ = GetModuleFunctionAddr(module_, "AmxLoad");
  plugin_amx_unload_addr_ = GetModuleFunctionAddr(module_, "AmxUnload");
  plugin_process_tick_addr_ = GetModuleFunctionAddr(module_, "ProcessTick");
  plugin_create_test_controller_addr_ =
      GetModuleFunctionAddr(module_, "CreateTestController");
  return true;
}

bool SampPlugin::Load() {
  // TODO(Russell): We should ASSERT here instead.
  // TODO(Russell): We need to pass some sane array for |data|.
  void* data[] = { nullptr };

  if (plugin_load_addr_)
    return ((PluginLoadCall)plugin_load_addr_)(data);

  return false;
}

void SampPlugin::Unload() {
  if (plugin_unload_addr_)
    ((PluginUnloadCall)plugin_unload_addr_)();
}

unsigned int SampPlugin::Supports() {
  // TODO(Russell): We should ASSERT here instead.
  if (plugin_supports_addr_)
    return ((PluginSupportsCall)plugin_supports_addr_)();

  return 0;
}

int SampPlugin::AmxLoad(AMX* amx) {
  if (plugin_amx_load_addr_)
    return ((PluginAmxLoadCall)plugin_amx_load_addr_)(amx);

  return 0;
}

int SampPlugin::AmxUnload(AMX* amx) {
  if (plugin_amx_unload_addr_)
    return ((PluginAmxUnloadCall)plugin_amx_unload_addr_)(amx);

  return 0;
}

void SampPlugin::ProcessTick() {
  if (plugin_process_tick_addr_)
    ((PluginProcessTickCall)plugin_process_tick_addr_)();
}

TestController* SampPlugin::CreateTestController() {
  if (plugin_create_test_controller_addr_)
    return ((PluginCreateTestControllerCall)plugin_create_test_controller_addr_)();

  return nullptr;
}
