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

#ifndef SLIM_KUBE_ORM_H
#define SLIM_KUBE_ORM_H

#include <iostream>
#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>

class Orm {
    public:
        explicit Orm(const std::string& connection_string);
        ~Orm();
    public:
        bool CreateTable(const std::string& table);
    private:
        std::string connection_string_;
        soci::session sql_;
};

#endif //SLIM_KUBE_ORM_H
