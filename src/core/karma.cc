//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "karma.h"

#include <iostream>

#include "tcp_session.h"
#include "udp_session.h"
#include "../utils/byte_buffer.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

namespace chara {

Karma::Karma() : context_(1), acceptor_(context_) {}

void Karma::DoTcpAccept() {
  acceptor_.async_accept([this](const std::error_code &ec, neti::tcp::socket socket) {
    if (!ec) {
      std::make_shared<TcpSession>(std::move(socket))->Start();
    }
    DoTcpAccept();
  });
}

void Karma::DoUdpAccept() {
  ByteBuffer buffer{512};
  neti::udp::socket socket{context_};
  neti::udp::endpoint endpoint{neti::udp::v4(), 53};
  SetUdpOption(socket, endpoint);

  socket.async_receive_from(buffer.ToMutableBuffer(), endpoint, [this, &socket, &endpoint, &buffer](auto ec, auto b) {
    if (!ec) {
      buffer.set_length(b);
      std::make_shared<UdpSession>(std::move(socket), std::move(endpoint), std::move(buffer))->Start();
    }
    DoUdpAccept();
  });
}

void Karma::SetTcpOption() {
  acceptor_.open(neti::tcp::v4());
  int buf = 1;
  setsockopt(acceptor_.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
  acceptor_.bind({neti::make_address_v4("0.0.0.0"), 8080});
  acceptor_.listen(ASIO_OS_DEF_SOMAXCONN);
}

void Karma::SetUdpOption(neti::udp::socket &socket, neti::udp::endpoint &endpoint) {
  socket.open(neti::udp::v4());
  int buf = 1;
  setsockopt(socket.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
  socket.bind(endpoint);
}

void Karma::Run() {
  SetTcpOption();
  DoTcpAccept();
  DoUdpAccept();
  context_.run();
}

}
#pragma clang diagnostic pop