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

#ifndef SERVER_BINDINGS_SAMP_H_
#define SERVER_BINDINGS_SAMP_H_

// Generated on 2014-09-27 at 03:13:47 GMT Summer Time.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

#define MAX_PLAYER_NAME (24)
#define MAX_PLAYERS (500)
#define MAX_VEHICLES (2000)
#define INVALID_PLAYER_ID (0xFFFF)
#define INVALID_VEHICLE_ID (0xFFFF)
#define NO_TEAM (255)
#define MAX_OBJECTS (1000)
#define INVALID_OBJECT_ID (0xFFFF)
#define MAX_GANG_ZONES (1024)
#define MAX_TEXT_DRAWS (2048)
#define MAX_MENUS (128)
#define MAX_3DTEXT_GLOBAL (1024)
#define MAX_3DTEXT_PLAYER (1024)
#define MAX_PICKUPS (4096)
#define INVALID_MENU (0xFF)
#define INVALID_TEXT_DRAW (0xFFFF)
#define INVALID_GANG_ZONE (-1)
#define INVALID_3DTEXT_ID (0xFFFF)
#define DIALOG_STYLE_MSGBOX 0
#define DIALOG_STYLE_INPUT 1
#define DIALOG_STYLE_LIST 2
#define DIALOG_STYLE_PASSWORD 3
#define PLAYER_STATE_NONE (0)
#define PLAYER_STATE_ONFOOT (1)
#define PLAYER_STATE_DRIVER (2)
#define PLAYER_STATE_PASSENGER (3)
#define PLAYER_STATE_EXIT_VEHICLE (4)
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER (5)
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER (6)
#define PLAYER_STATE_WASTED (7)
#define PLAYER_STATE_SPAWNED (8)
#define PLAYER_STATE_SPECTATING (9)
#define PLAYER_MARKERS_MODE_OFF (0)
#define PLAYER_MARKERS_MODE_GLOBAL (1)
#define PLAYER_MARKERS_MODE_STREAMED (2)
#define WEAPON_BRASSKNUCKLE (1)
#define WEAPON_GOLFCLUB (2)
#define WEAPON_NITESTICK (3)
#define WEAPON_KNIFE (4)
#define WEAPON_BAT (5)
#define WEAPON_SHOVEL (6)
#define WEAPON_POOLSTICK (7)
#define WEAPON_KATANA (8)
#define WEAPON_CHAINSAW (9)
#define WEAPON_DILDO (10)
#define WEAPON_DILDO2 (11)
#define WEAPON_VIBRATOR (12)
#define WEAPON_VIBRATOR2 (13)
#define WEAPON_FLOWER (14)
#define WEAPON_CANE (15)
#define WEAPON_GRENADE (16)
#define WEAPON_TEARGAS (17)
#define WEAPON_MOLTOV (18)
#define WEAPON_COLT45 (22)
#define WEAPON_SILENCED (23)
#define WEAPON_DEAGLE (24)
#define WEAPON_SHOTGUN (25)
#define WEAPON_SAWEDOFF (26)
#define WEAPON_SHOTGSPA (27)
#define WEAPON_UZI (28)
#define WEAPON_MP5 (29)
#define WEAPON_AK47 (30)
#define WEAPON_M4 (31)
#define WEAPON_TEC9 (32)
#define WEAPON_RIFLE (33)
#define WEAPON_SNIPER (34)
#define WEAPON_ROCKETLAUNCHER (35)
#define WEAPON_HEATSEEKER (36)
#define WEAPON_FLAMETHROWER (37)
#define WEAPON_MINIGUN (38)
#define WEAPON_SATCHEL (39)
#define WEAPON_BOMB (40)
#define WEAPON_SPRAYCAN (41)
#define WEAPON_FIREEXTINGUISHER (42)
#define WEAPON_CAMERA (43)
#define WEAPON_PARACHUTE (46)
#define WEAPON_VEHICLE (49)
#define WEAPON_DROWN (53)
#define WEAPON_COLLISION (54)
#define KEY_ACTION (1)
#define KEY_CROUCH (2)
#define KEY_FIRE (4)
#define KEY_SPRINT (8)
#define KEY_SECONDARY_ATTACK (16)
#define KEY_JUMP (32)
#define KEY_LOOK_RIGHT (64)
#define KEY_HANDBRAKE (128)
#define KEY_LOOK_LEFT (256)
#define KEY_SUBMISSION (512)
#define KEY_LOOK_BEHIND (512)
#define KEY_WALK (1024)
#define KEY_ANALOG_UP (2048)
#define KEY_ANALOG_DOWN (4096)
#define KEY_ANALOG_LEFT (8192)
#define KEY_ANALOG_RIGHT (16384)
#define KEY_YES (65536)
#define KEY_NO (131072)
#define KEY_CTRL_BACK (262144)
#define KEY_UP (-128)
#define KEY_DOWN (128)
#define KEY_LEFT (-128)
#define KEY_RIGHT (128)
#define CLICK_SOURCE_SCOREBOARD 0

int print(char* string);

int printf(char* format, ...);

int format(char* output, int len, char* format, ...);

int SendClientMessage(int playerid, int color, char* message);

int SendClientMessageToAll(int color, char* message);

int SendPlayerMessageToPlayer(int playerid, int senderid, char* message);

int SendPlayerMessageToAll(int senderid, char* message);

int SendDeathMessage(int killer, int killee, int weapon);

int GameTextForAll(char* string, int time, int style);

int GameTextForPlayer(int playerid, char* string, int time, int style);

int SetTimer(char* funcname, int interval, int repeating);

int SetTimerEx(char* funcname, int interval, int repeating, char* format, ...);

int KillTimer(int timerid);

int GetTickCount();

int GetMaxPlayers();

int CallRemoteFunction(char* function, char* format, ...);

int CallLocalFunction(char* function, char* format, ...);

float asin(float value);

float acos(float value);

float atan(float value);

float atan2(float x, float y);

int SetGameModeText(char* string);

int SetTeamCount(int count);

int AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);

int AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);

int AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2);

int AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2, int respawn_delay);

int AddStaticPickup(int model, int type, float X, float Y, float Z, int virtualworld);

int CreatePickup(int model, int type, float X, float Y, float Z, int virtualworld);

int DestroyPickup(int pickup);

int ShowNameTags(int show);

int ShowPlayerMarkers(int mode);

int GameModeExit();

int SetWorldTime(int hour);

int GetWeaponName(int weaponid, char* weapon, int len);

int EnableTirePopping(int enable);

int AllowInteriorWeapons(int allow);

int SetWeather(int weatherid);

int SetGravity(float gravity);

int AllowAdminTeleport(int allow);

int SetDeathDropAmount(int amount);

int CreateExplosion(float X, float Y, float Z, int type, float Radius);

int EnableZoneNames(int enable);

int UsePlayerPedAnims();

int DisableInteriorEnterExits();

int SetNameTagDrawDistance(float distance);

int DisableNameTagLOS();

int LimitGlobalChatRadius(float chat_radius);

int LimitPlayerMarkerRadius(float marker_radius);

int ConnectNPC(char* name, char* script);

int IsPlayerNPC(int playerid);

int IsPlayerAdmin(int playerid);

int Kick(int playerid);

int Ban(int playerid);

int BanEx(int playerid, char* reason);

int SendRconCommand(char* command);

int GetServerVarAsString(char* varname, char* buffer, int len);

int GetServerVarAsInt(char* varname);

int GetServerVarAsBool(char* varname);

int GetPlayerNetworkStats(int playerid, char* retstr, int retstr_size);

int GetNetworkStats(char* retstr, int retstr_size);

int CreateMenu(char* title, int columns, float x, float y, float col1width, float col2width);

int DestroyMenu(int menuid);

int AddMenuItem(int menuid, int column, char* menutext);

int SetMenuColumnHeader(int menuid, int column, char* columnheader);

int ShowMenuForPlayer(int menuid, int playerid);

int HideMenuForPlayer(int menuid, int playerid);

int IsValidMenu(int menuid);

int DisableMenu(int menuid);

int DisableMenuRow(int menuid, int row);

int GetPlayerMenu(int playerid);

int TextDrawCreate(float x, float y, char* text);

int TextDrawDestroy(int text);

int TextDrawLetterSize(int text, float x, float y);

int TextDrawTextSize(int text, float x, float y);

int TextDrawAlignment(int text, int alignment);

int TextDrawColor(int text, int color);

int TextDrawUseBox(int text, int use);

int TextDrawBoxColor(int text, int color);

int TextDrawSetShadow(int text, int size);

int TextDrawSetOutline(int text, int size);

int TextDrawBackgroundColor(int text, int color);

int TextDrawFont(int text, int font);

int TextDrawSetProportional(int text, int set);

int TextDrawShowForPlayer(int playerid, int text);

int TextDrawHideForPlayer(int playerid, int text);

int TextDrawShowForAll(int text);

int TextDrawHideForAll(int text);

int TextDrawSetString(int text, char* string);

int GangZoneCreate(float minx, float miny, float maxx, float maxy);

int GangZoneDestroy(int zone);

int GangZoneShowForPlayer(int playerid, int zone, int color);

int GangZoneShowForAll(int zone, int color);

int GangZoneHideForPlayer(int playerid, int zone);

int GangZoneHideForAll(int zone);

int GangZoneFlashForPlayer(int playerid, int zone, int flashcolor);

int GangZoneFlashForAll(int zone, int flashcolor);

int GangZoneStopFlashForPlayer(int playerid, int zone);

int GangZoneStopFlashForAll(int zone);

int Create3DTextLabel(char* text, int color, float X, float Y, float Z, float DrawDistance, int virtualworld, int testLOS);

int Delete3DTextLabel(int id);

int Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX, float OffsetY, float OffsetZ);

int Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ);

int Update3DTextLabelText(int id, int color, char* text);

int CreatePlayer3DTextLabel(int playerid, char* text, int color, float X, float Y, float Z, float DrawDistance, int attachedplayer, int attachedvehicle, int testLOS);

int DeletePlayer3DTextLabel(int playerid, int id);

int UpdatePlayer3DTextLabelText(int playerid, int id, int color, char* text);

int ShowPlayerDialog(int playerid, int dialogid, int style, char* caption, char* info, char* button1, char* button2);

}  // namespace samp

#endif  // SERVER_BINDINGS_SAMP_H_
