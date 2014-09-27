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

#ifndef SERVER_BINDINGS_VEHICLES_H_
#define SERVER_BINDINGS_VEHICLES_H_

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

const int CARMODTYPE_SPOILER = 0;
const int CARMODTYPE_HOOD = 1;
const int CARMODTYPE_ROOF = 2;
const int CARMODTYPE_SIDESKIRT = 3;
const int CARMODTYPE_LAMPS = 4;
const int CARMODTYPE_NITRO = 5;
const int CARMODTYPE_EXHAUST = 6;
const int CARMODTYPE_WHEELS = 7;
const int CARMODTYPE_STEREO = 8;
const int CARMODTYPE_HYDRAULICS = 9;
const int CARMODTYPE_FRONT_BUMPER = 10;
const int CARMODTYPE_REAR_BUMPER = 11;
const int CARMODTYPE_VENT_RIGHT = 12;
const int CARMODTYPE_VENT_LEFT = 13;
const int VEHICLE_PARAMS_UNSET = -1;
const int VEHICLE_PARAMS_OFF = 0;
const int VEHICLE_PARAMS_ON = 1;

int CreateVehicle(int vehicletype, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay);
int DestroyVehicle(int vehicleid);
int IsVehicleStreamedIn(int vehicleid, int forplayerid);
int GetVehiclePos(int vehicleid, float* x, float* y, float* z);
int SetVehiclePos(int vehicleid, float x, float y, float z);
int GetVehicleZAngle(int vehicleid, float* z_angle);
int GetVehicleRotationQuat(int vehicleid, float* w, float* x, float* y, float* z);
float GetVehicleDistanceFromPoint(int vehicleid, float X, float Y, float Z);
int SetVehicleZAngle(int vehicleid, float z_angle);
int SetVehicleParamsForPlayer(int vehicleid, int playerid, int objective, int doorslocked);
int ManualVehicleEngineAndLights();
int SetVehicleParamsEx(int vehicleid, int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective);
int GetVehicleParamsEx(int vehicleid, int* engine, int* lights, int* alarm, int* doors, int* bonnet, int* boot, int* objective);
int SetVehicleToRespawn(int vehicleid);
int LinkVehicleToInterior(int vehicleid, int interiorid);
int AddVehicleComponent(int vehicleid, int componentid);
int RemoveVehicleComponent(int vehicleid, int componentid);
int ChangeVehicleColor(int vehicleid, int color1, int color2);
int ChangeVehiclePaintjob(int vehicleid, int paintjobid);
int SetVehicleHealth(int vehicleid, float health);
int GetVehicleHealth(int vehicleid, float* health);
int AttachTrailerToVehicle(int trailerid, int vehicleid);
int DetachTrailerFromVehicle(int vehicleid);
int IsTrailerAttachedToVehicle(int vehicleid);
int GetVehicleTrailer(int vehicleid);
int SetVehicleNumberPlate(int vehicleid, char* numberplate);
int GetVehicleModel(int vehicleid);
int GetVehicleComponentInSlot(int vehicleid, int slot);
int GetVehicleComponentType(int component);
int RepairVehicle(int vehicleid);
int GetVehicleVelocity(int vehicleid, float* X, float* Y, float* Z);
int SetVehicleVelocity(int vehicleid, float X, float Y, float Z);
int SetVehicleAngularVelocity(int vehicleid, float X, float Y, float Z);
int GetVehicleDamageStatus(int vehicleid, int* panels, int* doors, int* lights, int* tires);
int UpdateVehicleDamageStatus(int vehicleid, int panels, int doors, int lights, int tires);
int SetVehicleVirtualWorld(int vehicleid, int worldid);
int GetVehicleVirtualWorld(int vehicleid);

}  // namespace samp

#endif  // SERVER_BINDINGS_VEHICLES_H_
