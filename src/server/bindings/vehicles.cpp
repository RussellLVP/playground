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

#include "server/bindings/vehicles.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int CreateVehicle(int vehicletype, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("CreateVehicle", "iffffiii", vehicletype, x, y, z, rotation, color1, color2, respawn_delay);
}

int DestroyVehicle(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DestroyVehicle", "i", vehicleid);
}

int IsVehicleStreamedIn(int vehicleid, int forplayerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsVehicleStreamedIn", "ii", vehicleid, forplayerid);
}

int GetVehiclePos(int vehicleid, float* x, float* y, float* z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehiclePos", "iFFF", vehicleid, x, y, z);
}

int SetVehiclePos(int vehicleid, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehiclePos", "ifff", vehicleid, x, y, z);
}

int GetVehicleZAngle(int vehicleid, float* z_angle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleZAngle", "iF", vehicleid, z_angle);
}

int GetVehicleRotationQuat(int vehicleid, float* w, float* x, float* y, float* z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleRotationQuat", "iFFFF", vehicleid, w, x, y, z);
}

float GetVehicleDistanceFromPoint(int vehicleid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("GetVehicleDistanceFromPoint", "ifff", vehicleid, X, Y, Z);
  return * (float*) &result;
}

int SetVehicleZAngle(int vehicleid, float z_angle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleZAngle", "if", vehicleid, z_angle);
}

int SetVehicleParamsForPlayer(int vehicleid, int playerid, int objective, int doorslocked) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleParamsForPlayer", "iiii", vehicleid, playerid, objective, doorslocked);
}

int ManualVehicleEngineAndLights() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ManualVehicleEngineAndLights", "");
}

int SetVehicleParamsEx(int vehicleid, int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleParamsEx", "iiiiiiii", vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

int GetVehicleParamsEx(int vehicleid, int* engine, int* lights, int* alarm, int* doors, int* bonnet, int* boot, int* objective) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleParamsEx", "iIIIIIII", vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

int SetVehicleToRespawn(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleToRespawn", "i", vehicleid);
}

int LinkVehicleToInterior(int vehicleid, int interiorid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("LinkVehicleToInterior", "ii", vehicleid, interiorid);
}

int AddVehicleComponent(int vehicleid, int componentid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddVehicleComponent", "ii", vehicleid, componentid);
}

int RemoveVehicleComponent(int vehicleid, int componentid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("RemoveVehicleComponent", "ii", vehicleid, componentid);
}

int ChangeVehicleColor(int vehicleid, int color1, int color2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ChangeVehicleColor", "iii", vehicleid, color1, color2);
}

int ChangeVehiclePaintjob(int vehicleid, int paintjobid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ChangeVehiclePaintjob", "ii", vehicleid, paintjobid);
}

int SetVehicleHealth(int vehicleid, float health) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleHealth", "if", vehicleid, health);
}

int GetVehicleHealth(int vehicleid, float* health) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleHealth", "iF", vehicleid, health);
}

int AttachTrailerToVehicle(int trailerid, int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AttachTrailerToVehicle", "ii", trailerid, vehicleid);
}

int DetachTrailerFromVehicle(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DetachTrailerFromVehicle", "i", vehicleid);
}

int IsTrailerAttachedToVehicle(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsTrailerAttachedToVehicle", "i", vehicleid);
}

int GetVehicleTrailer(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleTrailer", "i", vehicleid);
}

int SetVehicleNumberPlate(int vehicleid, char* numberplate) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleNumberPlate", "ic", vehicleid, numberplate);
}

int GetVehicleModel(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleModel", "i", vehicleid);
}

int GetVehicleComponentInSlot(int vehicleid, int slot) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleComponentInSlot", "ii", vehicleid, slot);
}

int GetVehicleComponentType(int component) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleComponentType", "i", component);
}

int RepairVehicle(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("RepairVehicle", "i", vehicleid);
}

int GetVehicleVelocity(int vehicleid, float* X, float* Y, float* Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleVelocity", "iFFF", vehicleid, X, Y, Z);
}

int SetVehicleVelocity(int vehicleid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleVelocity", "ifff", vehicleid, X, Y, Z);
}

int SetVehicleAngularVelocity(int vehicleid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleAngularVelocity", "ifff", vehicleid, X, Y, Z);
}

int GetVehicleDamageStatus(int vehicleid, int* panels, int* doors, int* lights, int* tires) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleDamageStatus", "iIIII", vehicleid, panels, doors, lights, tires);
}

int UpdateVehicleDamageStatus(int vehicleid, int panels, int doors, int lights, int tires) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("UpdateVehicleDamageStatus", "iiiii", vehicleid, panels, doors, lights, tires);
}

int SetVehicleVirtualWorld(int vehicleid, int worldid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetVehicleVirtualWorld", "ii", vehicleid, worldid);
}

int GetVehicleVirtualWorld(int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetVehicleVirtualWorld", "i", vehicleid);
}

}  // namespace samp
