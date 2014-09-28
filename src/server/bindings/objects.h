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

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int CreateObject(int modelid, double X, double Y, double Z, double rX, double rY, double rZ, double DrawDistance);
int AttachObjectToVehicle(int objectid, int vehicleid, double OffsetX, double OffsetY, double OffsetZ, double RotX, double RotY, double RotZ);
int AttachObjectToObject(int objectid, int attachtoid, double OffsetX, double OffsetY, double OffsetZ, double RotX, double RotY, double RotZ, int SyncRotation);
int AttachObjectToPlayer(int objectid, int playerid, double OffsetX, double OffsetY, double OffsetZ, double RotX, double RotY, double RotZ);
int SetObjectPos(int objectid, double X, double Y, double Z);
int GetObjectPos(int objectid, double* X, double* Y, double* Z);
int SetObjectRot(int objectid, double RotX, double RotY, double RotZ);
int GetObjectRot(int objectid, double* RotX, double* RotY, double* RotZ);
int IsValidObject(int objectid);
int DestroyObject(int objectid);
int MoveObject(int objectid, double X, double Y, double Z, double Speed, double RotX, double RotY, double RotZ);
int StopObject(int objectid);
int IsObjectMoving(int objectid);
int CreatePlayerObject(int playerid, int modelid, double X, double Y, double Z, double rX, double rY, double rZ, double DrawDistance);
int SetPlayerObjectPos(int playerid, int objectid, double X, double Y, double Z);
int GetPlayerObjectPos(int playerid, int objectid, double* X, double* Y, double* Z);
int SetPlayerObjectRot(int playerid, int objectid, double RotX, double RotY, double RotZ);
int GetPlayerObjectRot(int playerid, int objectid, double* RotX, double* RotY, double* RotZ);
int IsValidPlayerObject(int playerid, int objectid);
int DestroyPlayerObject(int playerid, int objectid);
int MovePlayerObject(int playerid, int objectid, double X, double Y, double Z, double Speed, double RotX, double RotY, double RotZ);
int StopPlayerObject(int playerid, int objectid);
int IsPlayerObjectMoving(int playerid, int objectid);
int AttachPlayerObjectToPlayer(int objectplayer, int objectid, int attachplayer, double OffsetX, double OffsetY, double OffsetZ, double rX, double rY, double rZ);

}  // namespace samp

#endif  // SERVER_BINDINGS_OBJECTS_H_
