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

#include <string>

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

const int MAX_PLAYER_NAME = (24);
const int MAX_PLAYERS = (500);
const int MAX_VEHICLES = (2000);
const int INVALID_PLAYER_ID = (0xFFFF);
const int INVALID_VEHICLE_ID = (0xFFFF);
const int NO_TEAM = (255);
const int MAX_OBJECTS = (1000);
const int INVALID_OBJECT_ID = (0xFFFF);
const int MAX_GANG_ZONES = (1024);
const int MAX_TEXT_DRAWS = (2048);
const int MAX_MENUS = (128);
const int MAX_3DTEXT_GLOBAL = (1024);
const int MAX_3DTEXT_PLAYER = (1024);
const int MAX_PICKUPS = (4096);
const int INVALID_MENU = (0xFF);
const int INVALID_TEXT_DRAW = (0xFFFF);
const int INVALID_GANG_ZONE = (-1);
const int INVALID_3DTEXT_ID = (0xFFFF);
const int DIALOG_STYLE_MSGBOX = 0;
const int DIALOG_STYLE_INPUT = 1;
const int DIALOG_STYLE_LIST = 2;
const int DIALOG_STYLE_PASSWORD = 3;
const int PLAYER_STATE_NONE = (0);
const int PLAYER_STATE_ONFOOT = (1);
const int PLAYER_STATE_DRIVER = (2);
const int PLAYER_STATE_PASSENGER = (3);
const int PLAYER_STATE_EXIT_VEHICLE = (4);
const int PLAYER_STATE_ENTER_VEHICLE_DRIVER = (5);
const int PLAYER_STATE_ENTER_VEHICLE_PASSENGER = (6);
const int PLAYER_STATE_WASTED = (7);
const int PLAYER_STATE_SPAWNED = (8);
const int PLAYER_STATE_SPECTATING = (9);
const int PLAYER_MARKERS_MODE_OFF = (0);
const int PLAYER_MARKERS_MODE_GLOBAL = (1);
const int PLAYER_MARKERS_MODE_STREAMED = (2);
const int WEAPON_BRASSKNUCKLE = (1);
const int WEAPON_GOLFCLUB = (2);
const int WEAPON_NITESTICK = (3);
const int WEAPON_KNIFE = (4);
const int WEAPON_BAT = (5);
const int WEAPON_SHOVEL = (6);
const int WEAPON_POOLSTICK = (7);
const int WEAPON_KATANA = (8);
const int WEAPON_CHAINSAW = (9);
const int WEAPON_DILDO = (10);
const int WEAPON_DILDO2 = (11);
const int WEAPON_VIBRATOR = (12);
const int WEAPON_VIBRATOR2 = (13);
const int WEAPON_FLOWER = (14);
const int WEAPON_CANE = (15);
const int WEAPON_GRENADE = (16);
const int WEAPON_TEARGAS = (17);
const int WEAPON_MOLTOV = (18);
const int WEAPON_COLT45 = (22);
const int WEAPON_SILENCED = (23);
const int WEAPON_DEAGLE = (24);
const int WEAPON_SHOTGUN = (25);
const int WEAPON_SAWEDOFF = (26);
const int WEAPON_SHOTGSPA = (27);
const int WEAPON_UZI = (28);
const int WEAPON_MP5 = (29);
const int WEAPON_AK47 = (30);
const int WEAPON_M4 = (31);
const int WEAPON_TEC9 = (32);
const int WEAPON_RIFLE = (33);
const int WEAPON_SNIPER = (34);
const int WEAPON_ROCKETLAUNCHER = (35);
const int WEAPON_HEATSEEKER = (36);
const int WEAPON_FLAMETHROWER = (37);
const int WEAPON_MINIGUN = (38);
const int WEAPON_SATCHEL = (39);
const int WEAPON_BOMB = (40);
const int WEAPON_SPRAYCAN = (41);
const int WEAPON_FIREEXTINGUISHER = (42);
const int WEAPON_CAMERA = (43);
const int WEAPON_PARACHUTE = (46);
const int WEAPON_VEHICLE = (49);
const int WEAPON_DROWN = (53);
const int WEAPON_COLLISION = (54);
const int KEY_ACTION = (1);
const int KEY_CROUCH = (2);
const int KEY_FIRE = (4);
const int KEY_SPRINT = (8);
const int KEY_SECONDARY_ATTACK = (16);
const int KEY_JUMP = (32);
const int KEY_LOOK_RIGHT = (64);
const int KEY_HANDBRAKE = (128);
const int KEY_LOOK_LEFT = (256);
const int KEY_SUBMISSION = (512);
const int KEY_LOOK_BEHIND = (512);
const int KEY_WALK = (1024);
const int KEY_ANALOG_UP = (2048);
const int KEY_ANALOG_DOWN = (4096);
const int KEY_ANALOG_LEFT = (8192);
const int KEY_ANALOG_RIGHT = (16384);
const int KEY_YES = (65536);
const int KEY_NO = (131072);
const int KEY_CTRL_BACK = (262144);
const int KEY_UP = (-128);
const int KEY_DOWN = (128);
const int KEY_LEFT = (-128);
const int KEY_RIGHT = (128);
const int CLICK_SOURCE_SCOREBOARD = 0;

int print(std::string& string);
int printf(std::string& format, ...);
int format(std::string& output, int len, std::string& format, ...);
int SendClientMessage(int playerid, int color, std::string& message);
int SendClientMessageToAll(int color, std::string& message);
int SendPlayerMessageToPlayer(int playerid, int senderid, std::string& message);
int SendPlayerMessageToAll(int senderid, std::string& message);
int SendDeathMessage(int killer, int killee, int weapon);
int GameTextForAll(std::string& string, int time, int style);
int GameTextForPlayer(int playerid, std::string& string, int time, int style);
int SetTimer(std::string& funcname, int interval, int repeating);
int SetTimerEx(std::string& funcname, int interval, int repeating, std::string& format, ...);
int KillTimer(int timerid);
int GetTickCount();
int GetMaxPlayers();
int CallRemoteFunction(std::string& function, std::string& format, ...);
int CallLocalFunction(std::string& function, std::string& format, ...);
double asin(double value);
double acos(double value);
double atan(double value);
double atan2(double x, double y);
int SetGameModeText(std::string& string);
int SetTeamCount(int count);
int AddPlayerClass(int modelid, double spawn_x, double spawn_y, double spawn_z, double z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);
int AddPlayerClassEx(int teamid, int modelid, double spawn_x, double spawn_y, double spawn_z, double z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);
int AddStaticVehicle(int modelid, double spawn_x, double spawn_y, double spawn_z, double z_angle, int color1, int color2);
int AddStaticVehicleEx(int modelid, double spawn_x, double spawn_y, double spawn_z, double z_angle, int color1, int color2, int respawn_delay);
int AddStaticPickup(int model, int type, double X, double Y, double Z, int virtualworld);
int CreatePickup(int model, int type, double X, double Y, double Z, int virtualworld);
int DestroyPickup(int pickup);
int ShowNameTags(int show);
int ShowPlayerMarkers(int mode);
int GameModeExit();
int SetWorldTime(int hour);
int GetWeaponName(int weaponid, std::string& weapon, int len);
int EnableTirePopping(int enable);
int AllowInteriorWeapons(int allow);
int SetWeather(int weatherid);
int SetGravity(double gravity);
double GetGravity();
int AllowAdminTeleport(int allow);
int SetDeathDropAmount(int amount);
int CreateExplosion(double X, double Y, double Z, int type, double Radius);
int EnableZoneNames(int enable);
int UsePlayerPedAnims();
int DisableInteriorEnterExits();
int SetNameTagDrawDistance(double distance);
int DisableNameTagLOS();
int LimitGlobalChatRadius(double chat_radius);
int LimitPlayerMarkerRadius(double marker_radius);
int ConnectNPC(std::string& name, std::string& script);
int IsPlayerNPC(int playerid);
int IsPlayerAdmin(int playerid);
int Kick(int playerid);
int Ban(int playerid);
int BanEx(int playerid, std::string& reason);
int SendRconCommand(std::string& command);
int GetServerVarAsString(std::string& varname, std::string& buffer, int len);
int GetServerVarAsInt(std::string& varname);
int GetServerVarAsBool(std::string& varname);
int GetPlayerNetworkStats(int playerid, std::string& retstr, int retstr_size);
int GetNetworkStats(std::string& retstr, int retstr_size);
int CreateMenu(std::string& title, int columns, double x, double y, double col1width, double col2width);
int DestroyMenu(int menuid);
int AddMenuItem(int menuid, int column, std::string& menutext);
int SetMenuColumnHeader(int menuid, int column, std::string& columnheader);
int ShowMenuForPlayer(int menuid, int playerid);
int HideMenuForPlayer(int menuid, int playerid);
int IsValidMenu(int menuid);
int DisableMenu(int menuid);
int DisableMenuRow(int menuid, int row);
int GetPlayerMenu(int playerid);
int TextDrawCreate(double x, double y, std::string& text);
int TextDrawDestroy(int text);
int TextDrawLetterSize(int text, double x, double y);
int TextDrawTextSize(int text, double x, double y);
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
int TextDrawSetString(int text, std::string& string);
int GangZoneCreate(double minx, double miny, double maxx, double maxy);
int GangZoneDestroy(int zone);
int GangZoneShowForPlayer(int playerid, int zone, int color);
int GangZoneShowForAll(int zone, int color);
int GangZoneHideForPlayer(int playerid, int zone);
int GangZoneHideForAll(int zone);
int GangZoneFlashForPlayer(int playerid, int zone, int flashcolor);
int GangZoneFlashForAll(int zone, int flashcolor);
int GangZoneStopFlashForPlayer(int playerid, int zone);
int GangZoneStopFlashForAll(int zone);
int Create3DTextLabel(std::string& text, int color, double X, double Y, double Z, double DrawDistance, int virtualworld, int testLOS);
int Delete3DTextLabel(int id);
int Attach3DTextLabelToPlayer(int id, int playerid, double OffsetX, double OffsetY, double OffsetZ);
int Attach3DTextLabelToVehicle(int id, int vehicleid, double OffsetX, double OffsetY, double OffsetZ);
int Update3DTextLabelText(int id, int color, std::string& text);
int CreatePlayer3DTextLabel(int playerid, std::string& text, int color, double X, double Y, double Z, double DrawDistance, int attachedplayer, int attachedvehicle, int testLOS);
int DeletePlayer3DTextLabel(int playerid, int id);
int UpdatePlayer3DTextLabelText(int playerid, int id, int color, std::string& text);
int ShowPlayerDialog(int playerid, int dialogid, int style, std::string& caption, std::string& info, std::string& button1, std::string& button2);

}  // namespace samp

#endif  // SERVER_BINDINGS_SAMP_H_
