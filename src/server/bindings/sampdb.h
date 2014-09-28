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

#ifndef SERVER_BINDINGS_SAMPDB_H_
#define SERVER_BINDINGS_SAMPDB_H_

#include <string>

// Do not modify this file by hand. Instead, look at /scripts/write_bindings.py.
namespace samp {

int db_open(std::string& name);
int db_close(int db);
int db_query(int db, std::string& query);
int db_free_result(int dbresult);
int db_num_rows(int dbresult);
int db_next_row(int dbresult);
int db_num_fields(int dbresult);
int db_field_name(int dbresult, int field, std::string& result, int maxlength);
int db_get_field(int dbresult, int field, std::string& result, int maxlength);
int db_get_field_assoc(int dbresult, std::string& field, std::string& result, int maxlength);

}  // namespace samp

#endif  // SERVER_BINDINGS_SAMPDB_H_
