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

#include "server/bindings/samp.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Generated on 2014-09-27.
// Do not modify by hand, instead, look at /scripts/write_bindings.py.
namespace samp {

int print(char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("print", "c", string);
}

int printf(char* format, ...) {
  CHECK(g_native_function_manager);
  CHECK(false) << "Support for Pawn functions with variable argument counts has not been implemented yet.";
  return 0;
}

int format(char* output, int len, char* format, ...) {
  CHECK(g_native_function_manager);
  CHECK(false) << "Support for Pawn functions with variable argument counts has not been implemented yet.";
  return 0;
}

int SendClientMessage(int playerid, int color, char* message) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SendClientMessage", "iic", playerid, color, message);
}

int SendClientMessageToAll(int color, char* message) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SendClientMessageToAll", "ic", color, message);
}

int SendPlayerMessageToPlayer(int playerid, int senderid, char* message) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SendPlayerMessageToPlayer", "iic", playerid, senderid, message);
}

int SendPlayerMessageToAll(int senderid, char* message) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SendPlayerMessageToAll", "ic", senderid, message);
}

int SendDeathMessage(int killer, int killee, int weapon) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SendDeathMessage", "iii", killer, killee, weapon);
}

int GameTextForAll(char* string, int time, int style) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GameTextForAll", "cii", string, time, style);
}

int GameTextForPlayer(int playerid, char* string, int time, int style) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GameTextForPlayer", "icii", playerid, string, time, style);
}

int SetTimer(char* funcname, int interval, int repeating) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetTimer", "cii", funcname, interval, repeating);
}

int SetTimerEx(char* funcname, int interval, int repeating, char* format, ...) {
  CHECK(g_native_function_manager);
  CHECK(false) << "Support for Pawn functions with variable argument counts has not been implemented yet.";
  return 0;
}

int KillTimer(int timerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("KillTimer", "i", timerid);
}

int GetTickCount() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetTickCount", "");
}

int GetMaxPlayers() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetMaxPlayers", "");
}

int CallRemoteFunction(char* function, char* format, ...) {
  CHECK(g_native_function_manager);
  CHECK(false) << "Support for Pawn functions with variable argument counts has not been implemented yet.";
  return 0;
}

int CallLocalFunction(char* function, char* format, ...) {
  CHECK(g_native_function_manager);
  CHECK(false) << "Support for Pawn functions with variable argument counts has not been implemented yet.";
  return 0;
}

float asin(float value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("asin", "f", value);
  return * (float*) &result;
}

float acos(float value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("acos", "f", value);
  return * (float*) &result;
}

float atan(float value) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("atan", "f", value);
  return * (float*) &result;
}

float atan2(float x, float y) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("atan2", "ff", x, y);
  return * (float*) &result;
}

int SetGameModeText(char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetGameModeText", "c", string);
}

int SetTeamCount(int count) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetTeamCount", "i", count);
}

int AddPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddPlayerClass", "iffffiiiiii", modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

int AddPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddPlayerClassEx", "iiffffiiiiii", teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

int AddStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddStaticVehicle", "iffffii", modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
}

int AddStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2, int respawn_delay) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddStaticVehicleEx", "iffffiii", modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay);
}

int AddStaticPickup(int model, int type, float X, float Y, float Z, int virtualworld) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddStaticPickup", "iifffi", model, type, X, Y, Z, virtualworld);
}

int CreatePickup(int model, int type, float X, float Y, float Z, int virtualworld) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("CreatePickup", "iifffi", model, type, X, Y, Z, virtualworld);
}

int DestroyPickup(int pickup) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DestroyPickup", "i", pickup);
}

int ShowNameTags(int show) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ShowNameTags", "i", show);
}

int ShowPlayerMarkers(int mode) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ShowPlayerMarkers", "i", mode);
}

int GameModeExit() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GameModeExit", "");
}

int SetWorldTime(int hour) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetWorldTime", "i", hour);
}

int GetWeaponName(int weaponid, char* weapon, int len) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetWeaponName", "ici", weaponid, weapon, len);
}

int EnableTirePopping(int enable) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("EnableTirePopping", "i", enable);
}

int AllowInteriorWeapons(int allow) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AllowInteriorWeapons", "i", allow);
}

int SetWeather(int weatherid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetWeather", "i", weatherid);
}

int SetGravity(float gravity) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetGravity", "f", gravity);
}

int AllowAdminTeleport(int allow) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AllowAdminTeleport", "i", allow);
}

int SetDeathDropAmount(int amount) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetDeathDropAmount", "i", amount);
}

int CreateExplosion(float X, float Y, float Z, int type, float Radius) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("CreateExplosion", "fffif", X, Y, Z, type, Radius);
}

int EnableZoneNames(int enable) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("EnableZoneNames", "i", enable);
}

int UsePlayerPedAnims() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("UsePlayerPedAnims", "");
}

int DisableInteriorEnterExits() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DisableInteriorEnterExits", "");
}

int SetNameTagDrawDistance(float distance) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetNameTagDrawDistance", "f", distance);
}

int DisableNameTagLOS() {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DisableNameTagLOS", "");
}

int LimitGlobalChatRadius(float chat_radius) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("LimitGlobalChatRadius", "f", chat_radius);
}

int LimitPlayerMarkerRadius(float marker_radius) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("LimitPlayerMarkerRadius", "f", marker_radius);
}

int ConnectNPC(char* name, char* script) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ConnectNPC", "cc", name, script);
}

int IsPlayerNPC(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerNPC", "i", playerid);
}

int IsPlayerAdmin(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsPlayerAdmin", "i", playerid);
}

int Kick(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("Kick", "i", playerid);
}

int Ban(int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("Ban", "i", playerid);
}

int BanEx(int playerid, char* reason) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("BanEx", "ic", playerid, reason);
}

int SendRconCommand(char* command) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SendRconCommand", "c", command);
}

int GetServerVarAsString(char* varname, char* buffer, int len) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetServerVarAsString", "cci", varname, buffer, len);
}

int GetServerVarAsInt(char* varname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetServerVarAsInt", "c", varname);
}

int GetServerVarAsBool(char* varname) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetServerVarAsBool", "c", varname);
}

int GetPlayerNetworkStats(int playerid, char* retstr, int retstr_size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetPlayerNetworkStats", "ici", playerid, retstr, retstr_size);
}

int GetNetworkStats(char* retstr, int retstr_size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GetNetworkStats", "ci", retstr, retstr_size);
}

int CreateMenu(char* title, int columns, float x, float y, float col1width, float col2width) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("CreateMenu", "ciffff", title, columns, x, y, col1width, col2width);
  return * (int*) &result;
}

int DestroyMenu(int menuid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DestroyMenu", "i", menuid);
}

int AddMenuItem(int menuid, int column, char* menutext) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("AddMenuItem", "iic", menuid, column, menutext);
}

int SetMenuColumnHeader(int menuid, int column, char* columnheader) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("SetMenuColumnHeader", "iic", menuid, column, columnheader);
}

int ShowMenuForPlayer(int menuid, int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ShowMenuForPlayer", "ii", menuid, playerid);
}

int HideMenuForPlayer(int menuid, int playerid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("HideMenuForPlayer", "ii", menuid, playerid);
}

int IsValidMenu(int menuid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("IsValidMenu", "i", menuid);
}

int DisableMenu(int menuid) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DisableMenu", "i", menuid);
}

int DisableMenuRow(int menuid, int row) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DisableMenuRow", "ii", menuid, row);
}

int GetPlayerMenu(int playerid) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("GetPlayerMenu", "i", playerid);
  return * (int*) &result;
}

int TextDrawCreate(float x, float y, char* text) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("TextDrawCreate", "ffc", x, y, text);
  return * (int*) &result;
}

int TextDrawDestroy(int text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawDestroy", "i", text);
}

int TextDrawLetterSize(int text, float x, float y) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawLetterSize", "iff", text, x, y);
}

int TextDrawTextSize(int text, float x, float y) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawTextSize", "iff", text, x, y);
}

int TextDrawAlignment(int text, int alignment) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawAlignment", "ii", text, alignment);
}

int TextDrawColor(int text, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawColor", "ii", text, color);
}

int TextDrawUseBox(int text, int use) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawUseBox", "ii", text, use);
}

int TextDrawBoxColor(int text, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawBoxColor", "ii", text, color);
}

int TextDrawSetShadow(int text, int size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawSetShadow", "ii", text, size);
}

int TextDrawSetOutline(int text, int size) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawSetOutline", "ii", text, size);
}

int TextDrawBackgroundColor(int text, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawBackgroundColor", "ii", text, color);
}

int TextDrawFont(int text, int font) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawFont", "ii", text, font);
}

int TextDrawSetProportional(int text, int set) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawSetProportional", "ii", text, set);
}

int TextDrawShowForPlayer(int playerid, int text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawShowForPlayer", "ii", playerid, text);
}

int TextDrawHideForPlayer(int playerid, int text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawHideForPlayer", "ii", playerid, text);
}

int TextDrawShowForAll(int text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawShowForAll", "i", text);
}

int TextDrawHideForAll(int text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawHideForAll", "i", text);
}

int TextDrawSetString(int text, char* string) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("TextDrawSetString", "ic", text, string);
}

int GangZoneCreate(float minx, float miny, float maxx, float maxy) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneCreate", "ffff", minx, miny, maxx, maxy);
}

int GangZoneDestroy(int zone) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneDestroy", "i", zone);
}

int GangZoneShowForPlayer(int playerid, int zone, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneShowForPlayer", "iii", playerid, zone, color);
}

int GangZoneShowForAll(int zone, int color) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneShowForAll", "ii", zone, color);
}

int GangZoneHideForPlayer(int playerid, int zone) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneHideForPlayer", "ii", playerid, zone);
}

int GangZoneHideForAll(int zone) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneHideForAll", "i", zone);
}

int GangZoneFlashForPlayer(int playerid, int zone, int flashcolor) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneFlashForPlayer", "iii", playerid, zone, flashcolor);
}

int GangZoneFlashForAll(int zone, int flashcolor) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneFlashForAll", "ii", zone, flashcolor);
}

int GangZoneStopFlashForPlayer(int playerid, int zone) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneStopFlashForPlayer", "ii", playerid, zone);
}

int GangZoneStopFlashForAll(int zone) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("GangZoneStopFlashForAll", "i", zone);
}

int Create3DTextLabel(char* text, int color, float X, float Y, float Z, float DrawDistance, int virtualworld, int testLOS) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("Create3DTextLabel", "ciffffii", text, color, X, Y, Z, DrawDistance, virtualworld, testLOS);
  return * (int*) &result;
}

int Delete3DTextLabel(int id) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("Delete3DTextLabel", "i", id);
}

int Attach3DTextLabelToPlayer(int id, int playerid, float OffsetX, float OffsetY, float OffsetZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("Attach3DTextLabelToPlayer", "iifff", id, playerid, OffsetX, OffsetY, OffsetZ);
}

int Attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("Attach3DTextLabelToVehicle", "iifff", id, vehicleid, OffsetX, OffsetY, OffsetZ);
}

int Update3DTextLabelText(int id, int color, char* text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("Update3DTextLabelText", "iic", id, color, text);
}

int CreatePlayer3DTextLabel(int playerid, char* text, int color, float X, float Y, float Z, float DrawDistance, int attachedplayer, int attachedvehicle, int testLOS) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("CreatePlayer3DTextLabel", "iciffffiii", playerid, text, color, X, Y, Z, DrawDistance, attachedplayer, attachedvehicle, testLOS);
  return * (int*) &result;
}

int DeletePlayer3DTextLabel(int playerid, int id) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("DeletePlayer3DTextLabel", "ii", playerid, id);
}

int UpdatePlayer3DTextLabelText(int playerid, int id, int color, char* text) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("UpdatePlayer3DTextLabelText", "iiic", playerid, id, color, text);
}

int ShowPlayerDialog(int playerid, int dialogid, int style, char* caption, char* info, char* button1, char* button2) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("ShowPlayerDialog", "iiicccc", playerid, dialogid, style, caption, info, button1, button2);
}

}  // namespace samp
