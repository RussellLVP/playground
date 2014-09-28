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

#include "server/bindings/sampdb.h"

#include "base/logging.h"
#include "server/native_function_manager.h"

extern NativeFunctionManager* g_native_function_manager;

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int db_open(char* name) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("db_open", "c", name);
  return * (int*) &result;
}

int db_close(int db) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_close", "i", db);
}

int db_query(int db, char* query) {
  CHECK(g_native_function_manager);
  int result = g_native_function_manager->Invoke("db_query", "ic", db, query);
  return * (int*) &result;
}

int db_free_result(int dbresult) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_free_result", "i", dbresult);
}

int db_num_rows(int dbresult) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_num_rows", "i", dbresult);
}

int db_next_row(int dbresult) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_next_row", "i", dbresult);
}

int db_num_fields(int dbresult) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_num_fields", "i", dbresult);
}

int db_field_name(int dbresult, int field, char* result, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_field_name", "iici", dbresult, field, result, maxlength);
}

int db_get_field(int dbresult, int field, char* result, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_get_field", "iici", dbresult, field, result, maxlength);
}

int db_get_field_assoc(int dbresult, char* field, char* result, int maxlength) {
  CHECK(g_native_function_manager);
  return g_native_function_manager->Invoke("db_get_field_assoc", "icci", dbresult, field, result, maxlength);
}

}  // namespace samp
