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

#include "server/bindings/players.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int SetSpawnInfo(int playerid, int team, int skin, float x, float y, float z, float rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetSpawnInfo", "iiiffffiiiiii", playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

int SpawnPlayer(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SpawnPlayer", "i", playerid);
}

int SetPlayerPos(int playerid, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerPos", "ifff", playerid, x, y, z);
}

int SetPlayerPosFindZ(int playerid, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerPosFindZ", "ifff", playerid, x, y, z);
}

int GetPlayerPos(int playerid, float* x, float* y, float* z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerPos", "iFFF", playerid, x, y, z);
}

int SetPlayerFacingAngle(int playerid, float ang) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerFacingAngle", "if", playerid, ang);
}

int GetPlayerFacingAngle(int playerid, float* ang) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerFacingAngle", "iF", playerid, ang);
}

int IsPlayerInRangeOfPoint(int playerid, float range, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerInRangeOfPoint", "iffff", playerid, range, x, y, z);
}

float GetPlayerDistanceFromPoint(int playerid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("GetPlayerDistanceFromPoint", "ifff", playerid, X, Y, Z);
  return * (float*) &result;
}

int IsPlayerStreamedIn(int playerid, int forplayerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerStreamedIn", "ii", playerid, forplayerid);
}

int SetPlayerInterior(int playerid, int interiorid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerInterior", "ii", playerid, interiorid);
}

int GetPlayerInterior(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerInterior", "i", playerid);
}

int SetPlayerHealth(int playerid, float health) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerHealth", "if", playerid, health);
}

int GetPlayerHealth(int playerid, float* health) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerHealth", "iF", playerid, health);
}

int SetPlayerArmour(int playerid, float armour) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerArmour", "if", playerid, armour);
}

int GetPlayerArmour(int playerid, float* armour) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerArmour", "iF", playerid, armour);
}

int SetPlayerAmmo(int playerid, int weaponslot, int ammo) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerAmmo", "iii", playerid, weaponslot, ammo);
}

int GetPlayerAmmo(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerAmmo", "i", playerid);
}

int GetPlayerWeaponState(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerWeaponState", "i", playerid);
}

int GetPlayerTargetPlayer(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerTargetPlayer", "i", playerid);
}

int SetPlayerTeam(int playerid, int teamid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerTeam", "ii", playerid, teamid);
}

int GetPlayerTeam(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerTeam", "i", playerid);
}

int SetPlayerScore(int playerid, int score) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerScore", "ii", playerid, score);
}

int GetPlayerScore(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerScore", "i", playerid);
}

int GetPlayerDrunkLevel(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerDrunkLevel", "i", playerid);
}

int SetPlayerDrunkLevel(int playerid, int level) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerDrunkLevel", "ii", playerid, level);
}

int SetPlayerColor(int playerid, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerColor", "ii", playerid, color);
}

int GetPlayerColor(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerColor", "i", playerid);
}

int SetPlayerSkin(int playerid, int skinid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerSkin", "ii", playerid, skinid);
}

int GetPlayerSkin(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerSkin", "i", playerid);
}

int GivePlayerWeapon(int playerid, int weaponid, int ammo) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GivePlayerWeapon", "iii", playerid, weaponid, ammo);
}

int ResetPlayerWeapons(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ResetPlayerWeapons", "i", playerid);
}

int SetPlayerArmedWeapon(int playerid, int weaponid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerArmedWeapon", "ii", playerid, weaponid);
}

int GetPlayerWeaponData(int playerid, int slot, int* weapons, int* ammo) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerWeaponData", "iiII", playerid, slot, weapons, ammo);
}

int GivePlayerMoney(int playerid, int money) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GivePlayerMoney", "ii", playerid, money);
}

int ResetPlayerMoney(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ResetPlayerMoney", "i", playerid);
}

int SetPlayerName(int playerid, char* name) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerName", "ic", playerid, name);
}

int GetPlayerMoney(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerMoney", "i", playerid);
}

int GetPlayerState(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerState", "i", playerid);
}

int GetPlayerIp(int playerid, char* name, int len) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerIp", "ici", playerid, name, len);
}

int GetPlayerPing(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerPing", "i", playerid);
}

int GetPlayerWeapon(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerWeapon", "i", playerid);
}

int GetPlayerKeys(int playerid, int* keys, int* updown, int* leftright) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerKeys", "iIII", playerid, keys, updown, leftright);
}

int GetPlayerName(int playerid, char* name, int len) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerName", "ici", playerid, name, len);
}

int SetPlayerTime(int playerid, int hour, int minute) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerTime", "iii", playerid, hour, minute);
}

int GetPlayerTime(int playerid, int* hour, int* minute) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerTime", "iII", playerid, hour, minute);
}

int TogglePlayerClock(int playerid, int toggle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TogglePlayerClock", "ii", playerid, toggle);
}

int SetPlayerWeather(int playerid, int weather) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerWeather", "ii", playerid, weather);
}

int ForceClassSelection(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ForceClassSelection", "i", playerid);
}

int SetPlayerWantedLevel(int playerid, int level) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerWantedLevel", "ii", playerid, level);
}

int GetPlayerWantedLevel(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerWantedLevel", "i", playerid);
}

int SetPlayerFightingStyle(int playerid, int style) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerFightingStyle", "ii", playerid, style);
}

int GetPlayerFightingStyle(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerFightingStyle", "i", playerid);
}

int SetPlayerVelocity(int playerid, float X, float Y, float Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerVelocity", "ifff", playerid, X, Y, Z);
}

int GetPlayerVelocity(int playerid, float* X, float* Y, float* Z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerVelocity", "iFFF", playerid, X, Y, Z);
}

int PlayCrimeReportForPlayer(int playerid, int suspectid, int crime) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("PlayCrimeReportForPlayer", "iii", playerid, suspectid, crime);
}

int PlayAudioStreamForPlayer(int playerid, char* url, float posX, float posY, float posZ, float distance, int usepos) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("PlayAudioStreamForPlayer", "icffffi", playerid, url, posX, posY, posZ, distance, usepos);
}

int StopAudioStreamForPlayer(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("StopAudioStreamForPlayer", "i", playerid);
}

int SetPlayerShopName(int playerid, char* shopname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerShopName", "ic", playerid, shopname);
}

int SetPlayerSkillLevel(int playerid, int skill, int level) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerSkillLevel", "iii", playerid, skill, level);
}

int GetPlayerSurfingVehicleID(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerSurfingVehicleID", "i", playerid);
}

int GetPlayerSurfingObjectID(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerSurfingObjectID", "i", playerid);
}

int RemoveBuildingForPlayer(int playerid, int modelid, float fX, float fY, float fZ, float fRadius) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("RemoveBuildingForPlayer", "iiffff", playerid, modelid, fX, fY, fZ, fRadius);
}

int SetPlayerAttachedObject(int playerid, int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerAttachedObject", "iiiifffffffff", playerid, index, modelid, bone, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
}

int RemovePlayerAttachedObject(int playerid, int index) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("RemovePlayerAttachedObject", "ii", playerid, index);
}

int IsPlayerAttachedObjectSlotUsed(int playerid, int index) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerAttachedObjectSlotUsed", "ii", playerid, index);
}

int SetPVarInt(int playerid, char* varname, int int_value) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPVarInt", "ici", playerid, varname, int_value);
}

int GetPVarInt(int playerid, char* varname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPVarInt", "ic", playerid, varname);
}

int SetPVarString(int playerid, char* varname, char* string_value) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPVarString", "icc", playerid, varname, string_value);
}

int GetPVarString(int playerid, char* varname, char* string_return, int len) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPVarString", "icci", playerid, varname, string_return, len);
}

int SetPVarFloat(int playerid, char* varname, float float_value) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPVarFloat", "icf", playerid, varname, float_value);
}

float GetPVarFloat(int playerid, char* varname) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("GetPVarFloat", "ic", playerid, varname);
  return * (float*) &result;
}

int DeletePVar(int playerid, char* varname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DeletePVar", "ic", playerid, varname);
}

int GetPVarsUpperIndex(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPVarsUpperIndex", "i", playerid);
}

int GetPVarNameAtIndex(int playerid, int index, char* ret_varname, int ret_len) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPVarNameAtIndex", "iici", playerid, index, ret_varname, ret_len);
}

int GetPVarType(int playerid, char* varname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPVarType", "ic", playerid, varname);
}

int SetPlayerChatBubble(int playerid, char* text, int color, float drawdistance, int expiretime) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerChatBubble", "icifi", playerid, text, color, drawdistance, expiretime);
}

int PutPlayerInVehicle(int playerid, int vehicleid, int seatid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("PutPlayerInVehicle", "iii", playerid, vehicleid, seatid);
}

int GetPlayerVehicleID(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerVehicleID", "i", playerid);
}

int GetPlayerVehicleSeat(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerVehicleSeat", "i", playerid);
}

int RemovePlayerFromVehicle(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("RemovePlayerFromVehicle", "i", playerid);
}

int TogglePlayerControllable(int playerid, int toggle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TogglePlayerControllable", "ii", playerid, toggle);
}

int PlayerPlaySound(int playerid, int soundid, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("PlayerPlaySound", "iifff", playerid, soundid, x, y, z);
}

int ApplyAnimation(int playerid, char* animlib, char* animname, float fDelta, int loop, int lockx, int locky, int freeze, int time, int forcesync) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ApplyAnimation", "iccfiiiiii", playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
}

int ClearAnimations(int playerid, int forcesync) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ClearAnimations", "ii", playerid, forcesync);
}

int GetPlayerAnimationIndex(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerAnimationIndex", "i", playerid);
}

int GetAnimationName(int index, char* animlib, int len1, char* animname, int len2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetAnimationName", "icici", index, animlib, len1, animname, len2);
}

int GetPlayerSpecialAction(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerSpecialAction", "i", playerid);
}

int SetPlayerSpecialAction(int playerid, int actionid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerSpecialAction", "ii", playerid, actionid);
}

int SetPlayerCheckpoint(int playerid, float x, float y, float z, float size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerCheckpoint", "iffff", playerid, x, y, z, size);
}

int DisablePlayerCheckpoint(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DisablePlayerCheckpoint", "i", playerid);
}

int SetPlayerRaceCheckpoint(int playerid, int type, float x, float y, float z, float nextx, float nexty, float nextz, float size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerRaceCheckpoint", "iifffffff", playerid, type, x, y, z, nextx, nexty, nextz, size);
}

int DisablePlayerRaceCheckpoint(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DisablePlayerRaceCheckpoint", "i", playerid);
}

int SetPlayerWorldBounds(int playerid, float x_max, float x_min, float y_max, float y_min) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerWorldBounds", "iffff", playerid, x_max, x_min, y_max, y_min);
}

int SetPlayerMarkerForPlayer(int playerid, int showplayerid, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerMarkerForPlayer", "iii", playerid, showplayerid, color);
}

int ShowPlayerNameTagForPlayer(int playerid, int showplayerid, int show) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ShowPlayerNameTagForPlayer", "iii", playerid, showplayerid, show);
}

int SetPlayerMapIcon(int playerid, int iconid, float x, float y, float z, int markertype, int color, int style) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerMapIcon", "iifffiii", playerid, iconid, x, y, z, markertype, color, style);
}

int RemovePlayerMapIcon(int playerid, int iconid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("RemovePlayerMapIcon", "ii", playerid, iconid);
}

int AllowPlayerTeleport(int playerid, int allow) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AllowPlayerTeleport", "ii", playerid, allow);
}

int SetPlayerCameraPos(int playerid, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerCameraPos", "ifff", playerid, x, y, z);
}

int SetPlayerCameraLookAt(int playerid, float x, float y, float z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerCameraLookAt", "ifff", playerid, x, y, z);
}

int SetCameraBehindPlayer(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetCameraBehindPlayer", "i", playerid);
}

int GetPlayerCameraPos(int playerid, float* x, float* y, float* z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerCameraPos", "iFFF", playerid, x, y, z);
}

int GetPlayerCameraFrontVector(int playerid, float* x, float* y, float* z) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerCameraFrontVector", "iFFF", playerid, x, y, z);
}

int GetPlayerCameraMode(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerCameraMode", "i", playerid);
}

int IsPlayerConnected(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerConnected", "i", playerid);
}

int IsPlayerInVehicle(int playerid, int vehicleid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerInVehicle", "ii", playerid, vehicleid);
}

int IsPlayerInAnyVehicle(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerInAnyVehicle", "i", playerid);
}

int IsPlayerInCheckpoint(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerInCheckpoint", "i", playerid);
}

int IsPlayerInRaceCheckpoint(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerInRaceCheckpoint", "i", playerid);
}

int SetPlayerVirtualWorld(int playerid, int worldid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetPlayerVirtualWorld", "ii", playerid, worldid);
}

int GetPlayerVirtualWorld(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerVirtualWorld", "i", playerid);
}

int EnableStuntBonusForPlayer(int playerid, int enable) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("EnableStuntBonusForPlayer", "ii", playerid, enable);
}

int EnableStuntBonusForAll(int enable) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("EnableStuntBonusForAll", "i", enable);
}

int TogglePlayerSpectating(int playerid, int toggle) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TogglePlayerSpectating", "ii", playerid, toggle);
}

int PlayerSpectatePlayer(int playerid, int targetplayerid, int mode) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("PlayerSpectatePlayer", "iii", playerid, targetplayerid, mode);
}

int PlayerSpectateVehicle(int playerid, int targetvehicleid, int mode) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("PlayerSpectateVehicle", "iii", playerid, targetvehicleid, mode);
}

int StartRecordingPlayerData(int playerid, int recordtype, char* recordname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("StartRecordingPlayerData", "iic", playerid, recordtype, recordname);
}

int StopRecordingPlayerData(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("StopRecordingPlayerData", "i", playerid);
}

}  // namespace samp