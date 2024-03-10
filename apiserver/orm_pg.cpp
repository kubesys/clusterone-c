/**
 * Copyright (2024, ) Institute of Software, Chinese Academy of Sciences
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * author: wuheng@iscas.ac.cn
 * since:  0.1
 */


#include "orm.h"


// jdbc:postgresql://localhost:5432/bookstore?user=aaa&password=bbb
// see https://jdbc.postgresql.org/documentation/use/
Orm::Orm(const std::string& connection_string) : connection_string_(connection_string) {
    sql_.open(soci::postgresql, connection_string_);
}

Orm::~Orm() {
    sql_.close();
}

bool Orm::CreateTable(const std::string& table) {
    try {
        // Define your table creation SQL statement
        std::string create_table_sql = "CREATE TABLE IF NOT EXISTS " + table + " ("
                                       "id SERIAL PRIMARY KEY, "
                                       "name VARCHAR(255) NOT NULL, "
                                       "age INT)";

        // Execute the SQL statement
        sql_ << create_table_sql;
        std::cout << "Table created successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error creating table: " << e.what() << std::endl;
        return false;
    }
    return true;
}
