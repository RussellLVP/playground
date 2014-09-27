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

#ifndef SERVER_BINDINGS_PLAYERS_H_
#define SERVER_BINDINGS_PLAYERS_H_

// Generated on 2014-09-27 at 03:34:10 GMT Summer Time.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

#define SPECIAL_ACTION_NONE 0
#define SPECIAL_ACTION_DUCK 1
#define SPECIAL_ACTION_USEJETPACK 2
#define SPECIAL_ACTION_ENTER_VEHICLE 3
#define SPECIAL_ACTION_EXIT_VEHICLE 4
#define SPECIAL_ACTION_DANCE1 5
#define SPECIAL_ACTION_DANCE2 6
#define SPECIAL_ACTION_DANCE3 7
#define SPECIAL_ACTION_DANCE4 8
#define SPECIAL_ACTION_HANDSUP 10
#define SPECIAL_ACTION_USECELLPHONE 11
#define SPECIAL_ACTION_SITTING 12
#define SPECIAL_ACTION_STOPUSECELLPHONE 13
#define SPECIAL_ACTION_DRINK_BEER 20
#define SPECIAL_ACTION_SMOKE_CIGGY 21
#define SPECIAL_ACTION_DRINK_WINE 22
#define SPECIAL_ACTION_DRINK_SPRUNK 23
#define FIGHT_STYLE_NORMAL 4
#define FIGHT_STYLE_BOXING 5
#define FIGHT_STYLE_KUNGFU 6
#define FIGHT_STYLE_KNEEHEAD 7
#define FIGHT_STYLE_GRABKICK 15
#define FIGHT_STYLE_ELBOW 16
#define WEAPONSKILL_PISTOL 0
#define WEAPONSKILL_PISTOL_SILENCED 1
#define WEAPONSKILL_DESERT_EAGLE 2
#define WEAPONSKILL_SHOTGUN 3
#define WEAPONSKILL_SAWNOFF_SHOTGUN 4
#define WEAPONSKILL_SPAS12_SHOTGUN 5
#define WEAPONSKILL_MICRO_UZI 6
#define WEAPONSKILL_MP5 7
#define WEAPONSKILL_AK47 8
#define WEAPONSKILL_M4 9
#define WEAPONSKILL_SNIPERRIFLE 10
#define WEAPONSTATE_UNKNOWN -1
#define WEAPONSTATE_NO_BULLETS 0
#define WEAPONSTATE_LAST_BULLET 1
#define WEAPONSTATE_MORE_BULLETS 2
#define WEAPONSTATE_RELOADING 3
#define MAX_PLAYER_ATTACHED_OBJECTS 10
#define PLAYER_VARTYPE_NONE 0
#define PLAYER_VARTYPE_INT 1
#define PLAYER_VARTYPE_STRING 2
#define PLAYER_VARTYPE_FLOAT 3
#define MAX_CHATBUBBLE_LENGTH 144
#define MAPICON_LOCAL 0
#define MAPICON_GLOBAL 1
#define MAPICON_LOCAL_CHECKPOINT 2
#define MAPICON_GLOBAL_CHECKPOINT 3
#define SPECTATE_MODE_NORMAL 1
#define SPECTATE_MODE_FIXED 2
#define SPECTATE_MODE_SIDE 3
#define PLAYER_RECORDING_TYPE_NONE 0
#define PLAYER_RECORDING_TYPE_DRIVER 1
#define PLAYER_RECORDING_TYPE_ONFOOT 2

int SetSpawnInfo(int playerid, int team, int skin, float x, float y, float z, float rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);
int SpawnPlayer(int playerid);
int SetPlayerPos(int playerid, float x, float y, float z);
int SetPlayerPosFindZ(int playerid, float x, float y, float z);
int GetPlayerPos(int playerid, float* x, float* y, float* z);
int SetPlayerFacingAngle(int playerid, float ang);
int GetPlayerFacingAngle(int playerid, float* ang);
int IsPlayerInRangeOfPoint(int playerid, float range, float x, float y, float z);
float GetPlayerDistanceFromPoint(int playerid, float X, float Y, float Z);
int IsPlayerStreamedIn(int playerid, int forplayerid);
int SetPlayerInterior(int playerid, int interiorid);
int GetPlayerInterior(int playerid);
int SetPlayerHealth(int playerid, float health);
int GetPlayerHealth(int playerid, float* health);
int SetPlayerArmour(int playerid, float armour);
int GetPlayerArmour(int playerid, float* armour);
int SetPlayerAmmo(int playerid, int weaponslot, int ammo);
int GetPlayerAmmo(int playerid);
int GetPlayerWeaponState(int playerid);
int GetPlayerTargetPlayer(int playerid);
int SetPlayerTeam(int playerid, int teamid);
int GetPlayerTeam(int playerid);
int SetPlayerScore(int playerid, int score);
int GetPlayerScore(int playerid);
int GetPlayerDrunkLevel(int playerid);
int SetPlayerDrunkLevel(int playerid, int level);
int SetPlayerColor(int playerid, int color);
int GetPlayerColor(int playerid);
int SetPlayerSkin(int playerid, int skinid);
int GetPlayerSkin(int playerid);
int GivePlayerWeapon(int playerid, int weaponid, int ammo);
int ResetPlayerWeapons(int playerid);
int SetPlayerArmedWeapon(int playerid, int weaponid);
int GetPlayerWeaponData(int playerid, int slot, int* weapons, int* ammo);
int GivePlayerMoney(int playerid, int money);
int ResetPlayerMoney(int playerid);
int SetPlayerName(int playerid, char* name);
int GetPlayerMoney(int playerid);
int GetPlayerState(int playerid);
int GetPlayerIp(int playerid, char* name, int len);
int GetPlayerPing(int playerid);
int GetPlayerWeapon(int playerid);
int GetPlayerKeys(int playerid, int* keys, int* updown, int* leftright);
int GetPlayerName(int playerid, char* name, int len);
int SetPlayerTime(int playerid, int hour, int minute);
int GetPlayerTime(int playerid, int* hour, int* minute);
int TogglePlayerClock(int playerid, int toggle);
int SetPlayerWeather(int playerid, int weather);
int ForceClassSelection(int playerid);
int SetPlayerWantedLevel(int playerid, int level);
int GetPlayerWantedLevel(int playerid);
int SetPlayerFightingStyle(int playerid, int style);
int GetPlayerFightingStyle(int playerid);
int SetPlayerVelocity(int playerid, float X, float Y, float Z);
int GetPlayerVelocity(int playerid, float* X, float* Y, float* Z);
int PlayCrimeReportForPlayer(int playerid, int suspectid, int crime);
int PlayAudioStreamForPlayer(int playerid, char* url, float posX, float posY, float posZ, float distance, int usepos);
int StopAudioStreamForPlayer(int playerid);
int SetPlayerShopName(int playerid, char* shopname);
int SetPlayerSkillLevel(int playerid, int skill, int level);
int GetPlayerSurfingVehicleID(int playerid);
int GetPlayerSurfingObjectID(int playerid);
int RemoveBuildingForPlayer(int playerid, int modelid, float fX, float fY, float fZ, float fRadius);
int SetPlayerAttachedObject(int playerid, int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ);
int RemovePlayerAttachedObject(int playerid, int index);
int IsPlayerAttachedObjectSlotUsed(int playerid, int index);
int SetPVarInt(int playerid, char* varname, int int_value);
int GetPVarInt(int playerid, char* varname);
int SetPVarString(int playerid, char* varname, char* string_value);
int GetPVarString(int playerid, char* varname, char* string_return, int len);
int SetPVarFloat(int playerid, char* varname, float float_value);
float GetPVarFloat(int playerid, char* varname);
int DeletePVar(int playerid, char* varname);
int GetPVarsUpperIndex(int playerid);
int GetPVarNameAtIndex(int playerid, int index, char* ret_varname, int ret_len);
int GetPVarType(int playerid, char* varname);
int SetPlayerChatBubble(int playerid, char* text, int color, float drawdistance, int expiretime);
int PutPlayerInVehicle(int playerid, int vehicleid, int seatid);
int GetPlayerVehicleID(int playerid);
int GetPlayerVehicleSeat(int playerid);
int RemovePlayerFromVehicle(int playerid);
int TogglePlayerControllable(int playerid, int toggle);
int PlayerPlaySound(int playerid, int soundid, float x, float y, float z);
int ApplyAnimation(int playerid, char* animlib, char* animname, float fDelta, int loop, int lockx, int locky, int freeze, int time, int forcesync);
int ClearAnimations(int playerid, int forcesync);
int GetPlayerAnimationIndex(int playerid);
int GetAnimationName(int index, char* animlib, int len1, char* animname, int len2);
int GetPlayerSpecialAction(int playerid);
int SetPlayerSpecialAction(int playerid, int actionid);
int SetPlayerCheckpoint(int playerid, float x, float y, float z, float size);
int DisablePlayerCheckpoint(int playerid);
int SetPlayerRaceCheckpoint(int playerid, int type, float x, float y, float z, float nextx, float nexty, float nextz, float size);
int DisablePlayerRaceCheckpoint(int playerid);
int SetPlayerWorldBounds(int playerid, float x_max, float x_min, float y_max, float y_min);
int SetPlayerMarkerForPlayer(int playerid, int showplayerid, int color);
int ShowPlayerNameTagForPlayer(int playerid, int showplayerid, int show);
int SetPlayerMapIcon(int playerid, int iconid, float x, float y, float z, int markertype, int color, int style);
int RemovePlayerMapIcon(int playerid, int iconid);
int AllowPlayerTeleport(int playerid, int allow);
int SetPlayerCameraPos(int playerid, float x, float y, float z);
int SetPlayerCameraLookAt(int playerid, float x, float y, float z);
int SetCameraBehindPlayer(int playerid);
int GetPlayerCameraPos(int playerid, float* x, float* y, float* z);
int GetPlayerCameraFrontVector(int playerid, float* x, float* y, float* z);
int GetPlayerCameraMode(int playerid);
int IsPlayerConnected(int playerid);
int IsPlayerInVehicle(int playerid, int vehicleid);
int IsPlayerInAnyVehicle(int playerid);
int IsPlayerInCheckpoint(int playerid);
int IsPlayerInRaceCheckpoint(int playerid);
int SetPlayerVirtualWorld(int playerid, int worldid);
int GetPlayerVirtualWorld(int playerid);
int EnableStuntBonusForPlayer(int playerid, int enable);
int EnableStuntBonusForAll(int enable);
int TogglePlayerSpectating(int playerid, int toggle);
int PlayerSpectatePlayer(int playerid, int targetplayerid, int mode);
int PlayerSpectateVehicle(int playerid, int targetvehicleid, int mode);
int StartRecordingPlayerData(int playerid, int recordtype, char* recordname);
int StopRecordingPlayerData(int playerid);

}  // namespace samp

#endif  // SERVER_BINDINGS_PLAYERS_H_
