//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include <iostream>
#include "karma.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

namespace chara {

Karma::Karma() : tcp_acceptor_{context_, {asio::ip::make_address_v4("0.0.0.0"), 8080}}, udp_acceptor_{context_} {
}

void Karma::DoTcpAccept() {
  tcp_acceptor_.async_accept([this] (const std::error_code &ec, asio::ip::tcp::socket socket) {
    if (!ec) {
//      std::make_shared<Session>();
    }
    DoTcpAccept();
  });
}

void Karma::Run() {
  DoTcpAccept();
  context_.run();
}

}
#pragma clang diagnostic pop