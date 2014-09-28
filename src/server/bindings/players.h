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

// Generated on 2014-09-28.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

const int SPECIAL_ACTION_NONE = 0;
const int SPECIAL_ACTION_DUCK = 1;
const int SPECIAL_ACTION_USEJETPACK = 2;
const int SPECIAL_ACTION_ENTER_VEHICLE = 3;
const int SPECIAL_ACTION_EXIT_VEHICLE = 4;
const int SPECIAL_ACTION_DANCE1 = 5;
const int SPECIAL_ACTION_DANCE2 = 6;
const int SPECIAL_ACTION_DANCE3 = 7;
const int SPECIAL_ACTION_DANCE4 = 8;
const int SPECIAL_ACTION_HANDSUP = 10;
const int SPECIAL_ACTION_USECELLPHONE = 11;
const int SPECIAL_ACTION_SITTING = 12;
const int SPECIAL_ACTION_STOPUSECELLPHONE = 13;
const int SPECIAL_ACTION_DRINK_BEER = 20;
const int SPECIAL_ACTION_SMOKE_CIGGY = 21;
const int SPECIAL_ACTION_DRINK_WINE = 22;
const int SPECIAL_ACTION_DRINK_SPRUNK = 23;
const int FIGHT_STYLE_NORMAL = 4;
const int FIGHT_STYLE_BOXING = 5;
const int FIGHT_STYLE_KUNGFU = 6;
const int FIGHT_STYLE_KNEEHEAD = 7;
const int FIGHT_STYLE_GRABKICK = 15;
const int FIGHT_STYLE_ELBOW = 16;
const int WEAPONSKILL_PISTOL = 0;
const int WEAPONSKILL_PISTOL_SILENCED = 1;
const int WEAPONSKILL_DESERT_EAGLE = 2;
const int WEAPONSKILL_SHOTGUN = 3;
const int WEAPONSKILL_SAWNOFF_SHOTGUN = 4;
const int WEAPONSKILL_SPAS12_SHOTGUN = 5;
const int WEAPONSKILL_MICRO_UZI = 6;
const int WEAPONSKILL_MP5 = 7;
const int WEAPONSKILL_AK47 = 8;
const int WEAPONSKILL_M4 = 9;
const int WEAPONSKILL_SNIPERRIFLE = 10;
const int WEAPONSTATE_UNKNOWN = -1;
const int WEAPONSTATE_NO_BULLETS = 0;
const int WEAPONSTATE_LAST_BULLET = 1;
const int WEAPONSTATE_MORE_BULLETS = 2;
const int WEAPONSTATE_RELOADING = 3;
const int MAX_PLAYER_ATTACHED_OBJECTS = 10;
const int PLAYER_VARTYPE_NONE = 0;
const int PLAYER_VARTYPE_INT = 1;
const int PLAYER_VARTYPE_STRING = 2;
const int PLAYER_VARTYPE_FLOAT = 3;
const int MAX_CHATBUBBLE_LENGTH = 144;
const int MAPICON_LOCAL = 0;
const int MAPICON_GLOBAL = 1;
const int MAPICON_LOCAL_CHECKPOINT = 2;
const int MAPICON_GLOBAL_CHECKPOINT = 3;
const int SPECTATE_MODE_NORMAL = 1;
const int SPECTATE_MODE_FIXED = 2;
const int SPECTATE_MODE_SIDE = 3;
const int PLAYER_RECORDING_TYPE_NONE = 0;
const int PLAYER_RECORDING_TYPE_DRIVER = 1;
const int PLAYER_RECORDING_TYPE_ONFOOT = 2;

int SetSpawnInfo(int playerid, int team, int skin, double x, double y, double z, double rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);
int SpawnPlayer(int playerid);
int SetPlayerPos(int playerid, double x, double y, double z);
int SetPlayerPosFindZ(int playerid, double x, double y, double z);
int GetPlayerPos(int playerid, double* x, double* y, double* z);
int SetPlayerFacingAngle(int playerid, double ang);
int GetPlayerFacingAngle(int playerid, double* ang);
int IsPlayerInRangeOfPoint(int playerid, double range, double x, double y, double z);
double GetPlayerDistanceFromPoint(int playerid, double X, double Y, double Z);
int IsPlayerStreamedIn(int playerid, int forplayerid);
int SetPlayerInterior(int playerid, int interiorid);
int GetPlayerInterior(int playerid);
int SetPlayerHealth(int playerid, double health);
int GetPlayerHealth(int playerid, double* health);
int SetPlayerArmour(int playerid, double armour);
int GetPlayerArmour(int playerid, double* armour);
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
int SetPlayerVelocity(int playerid, double X, double Y, double Z);
int GetPlayerVelocity(int playerid, double* X, double* Y, double* Z);
int PlayCrimeReportForPlayer(int playerid, int suspectid, int crime);
int PlayAudioStreamForPlayer(int playerid, char* url, double posX, double posY, double posZ, double distance, int usepos);
int StopAudioStreamForPlayer(int playerid);
int SetPlayerShopName(int playerid, char* shopname);
int SetPlayerSkillLevel(int playerid, int skill, int level);
int GetPlayerSurfingVehicleID(int playerid);
int GetPlayerSurfingObjectID(int playerid);
int RemoveBuildingForPlayer(int playerid, int modelid, double fX, double fY, double fZ, double fRadius);
int SetPlayerAttachedObject(int playerid, int index, int modelid, int bone, double fOffsetX, double fOffsetY, double fOffsetZ, double fRotX, double fRotY, double fRotZ, double fScaleX, double fScaleY, double fScaleZ);
int RemovePlayerAttachedObject(int playerid, int index);
int IsPlayerAttachedObjectSlotUsed(int playerid, int index);
int SetPVarInt(int playerid, char* varname, int int_value);
int GetPVarInt(int playerid, char* varname);
int SetPVarString(int playerid, char* varname, char* string_value);
int GetPVarString(int playerid, char* varname, char* string_return, int len);
int SetPVarFloat(int playerid, char* varname, double float_value);
double GetPVarFloat(int playerid, char* varname);
int DeletePVar(int playerid, char* varname);
int GetPVarsUpperIndex(int playerid);
int GetPVarNameAtIndex(int playerid, int index, char* ret_varname, int ret_len);
int GetPVarType(int playerid, char* varname);
int SetPlayerChatBubble(int playerid, char* text, int color, double drawdistance, int expiretime);
int PutPlayerInVehicle(int playerid, int vehicleid, int seatid);
int GetPlayerVehicleID(int playerid);
int GetPlayerVehicleSeat(int playerid);
int RemovePlayerFromVehicle(int playerid);
int TogglePlayerControllable(int playerid, int toggle);
int PlayerPlaySound(int playerid, int soundid, double x, double y, double z);
int ApplyAnimation(int playerid, char* animlib, char* animname, double fDelta, int loop, int lockx, int locky, int freeze, int time, int forcesync);
int ClearAnimations(int playerid, int forcesync);
int GetPlayerAnimationIndex(int playerid);
int GetAnimationName(int index, char* animlib, int len1, char* animname, int len2);
int GetPlayerSpecialAction(int playerid);
int SetPlayerSpecialAction(int playerid, int actionid);
int SetPlayerCheckpoint(int playerid, double x, double y, double z, double size);
int DisablePlayerCheckpoint(int playerid);
int SetPlayerRaceCheckpoint(int playerid, int type, double x, double y, double z, double nextx, double nexty, double nextz, double size);
int DisablePlayerRaceCheckpoint(int playerid);
int SetPlayerWorldBounds(int playerid, double x_max, double x_min, double y_max, double y_min);
int SetPlayerMarkerForPlayer(int playerid, int showplayerid, int color);
int ShowPlayerNameTagForPlayer(int playerid, int showplayerid, int show);
int SetPlayerMapIcon(int playerid, int iconid, double x, double y, double z, int markertype, int color, int style);
int RemovePlayerMapIcon(int playerid, int iconid);
int AllowPlayerTeleport(int playerid, int allow);
int SetPlayerCameraPos(int playerid, double x, double y, double z);
int SetPlayerCameraLookAt(int playerid, double x, double y, double z);
int SetCameraBehindPlayer(int playerid);
int GetPlayerCameraPos(int playerid, double* x, double* y, double* z);
int GetPlayerCameraFrontVector(int playerid, double* x, double* y, double* z);
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
