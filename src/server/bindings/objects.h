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

#ifndef SERVER_BINDINGS_OBJECTS_H_
#define SERVER_BINDINGS_OBJECTS_H_

// Generated on 2014-09-27 at 03:03:47.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace bindings {

int CreateObject(int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance);

int AttachObjectToVehicle(int objectid, int vehicleid, float OffsetX, float OffsetY, float OffsetZ, float RotX, float RotY, float RotZ);

int AttachObjectToObject(int objectid, int attachtoid, float OffsetX, float OffsetY, float OffsetZ, float RotX, float RotY, float RotZ, int SyncRotation);

int AttachObjectToPlayer(int objectid, int playerid, float OffsetX, float OffsetY, float OffsetZ, float RotX, float RotY, float RotZ);

int SetObjectPos(int objectid, float X, float Y, float Z);

int GetObjectPos(int objectid, float* X, float* Y, float* Z);

int SetObjectRot(int objectid, float RotX, float RotY, float RotZ);

int GetObjectRot(int objectid, float* RotX, float* RotY, float* RotZ);

int IsValidObject(int objectid);

int DestroyObject(int objectid);

int MoveObject(int objectid, float X, float Y, float Z, float Speed, float RotX, float RotY, float RotZ);

int StopObject(int objectid);

int IsObjectMoving(int objectid);

int CreatePlayerObject(int playerid, int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance);

int SetPlayerObjectPos(int playerid, int objectid, float X, float Y, float Z);

int GetPlayerObjectPos(int playerid, int objectid, float* X, float* Y, float* Z);

int SetPlayerObjectRot(int playerid, int objectid, float RotX, float RotY, float RotZ);

int GetPlayerObjectRot(int playerid, int objectid, float* RotX, float* RotY, float* RotZ);

int IsValidPlayerObject(int playerid, int objectid);

int DestroyPlayerObject(int playerid, int objectid);

int MovePlayerObject(int playerid, int objectid, float X, float Y, float Z, float Speed, float RotX, float RotY, float RotZ);

int StopPlayerObject(int playerid, int objectid);

int IsPlayerObjectMoving(int playerid, int objectid);

int AttachPlayerObjectToPlayer(int objectplayer, int objectid, int attachplayer, float OffsetX, float OffsetY, float OffsetZ, float rX, float rY, float rZ);

}  // namespace bindings

#endif  // SERVER_BINDINGS_OBJECTS_H_
