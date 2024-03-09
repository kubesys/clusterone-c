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


#include "server.h"

Server::Server(boost::asio::io_context& io_context, short port)
        : io_context_(io_context),
          acceptor_(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    StartAccept();
}

void Server::StartAccept() {
    // 创建新的连接
    auto new_connection = std::make_shared<boost::asio::ip::tcp::socket>(io_context_);

    // 异步等待连接
    acceptor_.async_accept(*new_connection,
                           [this, new_connection](const boost::system::error_code& error) {
                               // 处理连接完成事件
                               if (!error) {
                                   HandleRequest(new_connection);
                               }

                               // 继续等待下一个连接
                               StartAccept();
                           });
}

void Server::HandleRequest(std::shared_ptr<boost::asio::ip::tcp::socket> socket) {
    // 在这里处理HTTP请求，你可以使用Boost.Beast或其他库来解析和处理HTTP请求
    // 示例中只是简单地回复一个 "Hello, World!" 字符串
    std::string message = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    boost::asio::write(*socket, boost::asio::buffer(message));

    // 关闭连接
    socket->close();
}