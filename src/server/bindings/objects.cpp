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

#include "server/bindings/objects.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int CreateObject(int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("CreateObject", "ifffffff", modelid, X, Y, Z, rX, rY, rZ, DrawDistance);
}

int AttachObjectToVehicle(int objectid, int vehicleid, float OffsetX, float OffsetY, float OffsetZ, float RotX, float RotY, float RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AttachObjectToVehicle", "iiffffff", objectid, vehicleid, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ);
}

int AttachObjectToObject(int objectid, int attachtoid, float OffsetX, float OffsetY, float OffsetZ, float RotX, float RotY, float RotZ, int SyncRotation) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AttachObjectToObject", "iiffffffi", objectid, attachtoid, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ, SyncRotation);
}

int AttachObjectToPlayer(int objectid, int playerid, float OffsetX, float OffsetY, float OffsetZ, float RotX, float RotY, float RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AttachObjectToPlayer", "iiffffff", objectid, playerid, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ);
}

int SetObjectPos(int objectid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetObjectPos", "ifff", objectid, X, Y, Z);
}

int GetObjectPos(int objectid, float* X, float* Y, float* Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetObjectPos", "iFFF", objectid, X, Y, Z);
}

int SetObjectRot(int objectid, float RotX, float RotY, float RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetObjectRot", "ifff", objectid, RotX, RotY, RotZ);
}

int GetObjectRot(int objectid, float* RotX, float* RotY, float* RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetObjectRot", "iFFF", objectid, RotX, RotY, RotZ);
}

int IsValidObject(int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsValidObject", "i", objectid);
}

int DestroyObject(int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DestroyObject", "i", objectid);
}

int MoveObject(int objectid, float X, float Y, float Z, float Speed, float RotX, float RotY, float RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("MoveObject", "ifffffff", objectid, X, Y, Z, Speed, RotX, RotY, RotZ);
}

int StopObject(int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("StopObject", "i", objectid);
}

int IsObjectMoving(int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsObjectMoving", "i", objectid);
}

int CreatePlayerObject(int playerid, int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("CreatePlayerObject", "iifffffff", playerid, modelid, X, Y, Z, rX, rY, rZ, DrawDistance);
}

int SetPlayerObjectPos(int playerid, int objectid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerObjectPos", "iifff", playerid, objectid, X, Y, Z);
}

int GetPlayerObjectPos(int playerid, int objectid, float* X, float* Y, float* Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerObjectPos", "iiFFF", playerid, objectid, X, Y, Z);
}

int SetPlayerObjectRot(int playerid, int objectid, float RotX, float RotY, float RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerObjectRot", "iifff", playerid, objectid, RotX, RotY, RotZ);
}

int GetPlayerObjectRot(int playerid, int objectid, float* RotX, float* RotY, float* RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerObjectRot", "iiFFF", playerid, objectid, RotX, RotY, RotZ);
}

int IsValidPlayerObject(int playerid, int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsValidPlayerObject", "ii", playerid, objectid);
}

int DestroyPlayerObject(int playerid, int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DestroyPlayerObject", "ii", playerid, objectid);
}

int MovePlayerObject(int playerid, int objectid, float X, float Y, float Z, float Speed, float RotX, float RotY, float RotZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("MovePlayerObject", "iifffffff", playerid, objectid, X, Y, Z, Speed, RotX, RotY, RotZ);
}

int StopPlayerObject(int playerid, int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("StopPlayerObject", "ii", playerid, objectid);
}

int IsPlayerObjectMoving(int playerid, int objectid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerObjectMoving", "ii", playerid, objectid);
}

int AttachPlayerObjectToPlayer(int objectplayer, int objectid, int attachplayer, float OffsetX, float OffsetY, float OffsetZ, float rX, float rY, float rZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AttachPlayerObjectToPlayer", "iiiffffff", objectplayer, objectid, attachplayer, OffsetX, OffsetY, OffsetZ, rX, rY, rZ);
}

}  // namespace samp