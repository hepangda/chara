//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include <iostream>
#include "karma.h"
#include "tcp_session.h"
#include "udp_session.h"
#include "byte_buffer.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

namespace chara {

Karma::Karma() : tcp_acceptor_{context_}, udp_acceptor_{context_} {}

void Karma::DoTcpAccept() {
  tcp_acceptor_.async_accept([this](const std::error_code &ec, asio::ip::tcp::socket socket) {
    if (!ec) {
      std::make_shared<TcpSession>(context_, std::move(socket))->Start();
    }
    DoTcpAccept();
  });
}

void Karma::DoUdpAccept() {
  ByteBuffer buffer{512};

  udp_acceptor_.async_receive(buffer.ToMutableBuffer(), [this, &buffer](const std::error_code &ec, std::size_t b) {
    if (!ec) {
      buffer.set_length(b);
      std::make_shared<UdpSession>(context_, std::move(buffer))->Start();
    }
    DoUdpAccept();
  });
}

void Karma::SetTcpOption() {
  tcp_acceptor_.open(asio::ip::tcp::v4());
  int buf = 1;
  setsockopt(tcp_acceptor_.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
  tcp_acceptor_.bind({asio::ip::make_address_v4("0.0.0.0"), 8080});
  tcp_acceptor_.listen(ASIO_OS_DEF_SOMAXCONN);
}

void Karma::Run() {
  SetTcpOption();
  DoTcpAccept();
  DoUdpAccept();
  context_.run();
}

}
#pragma clang diagnostic pop