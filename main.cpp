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

#include "apiserver/server.h"
#include "apiserver/orm.h"
#include <iostream>

int startAPIServer();

int main() {
//    return startAPIServer();
    //std::string connection_string = "postgresql://postgres:onceas@139.9.165.93:30306/kine";
	std::string connection_string = "dbname=kine user=postgres password=onceas host=139.9.165.93 port=30306";
	Orm orm(connection_string);

    // Call the createTable method to create the table
    orm.CreateTable("test");

    return 0;
}

//int startAPIServer() {
//    try {
//        boost::asio::io_context io_context;
//        Server server(io_context, 8080);
//
//        // 运行IO循环
//        io_context.run();
//    } catch (const std::exception& e) {
//        std::cerr << "Exception: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
