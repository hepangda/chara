//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "karma.h"

#include <iostream>

#include "tcp_session.h"
#include "udp_session.h"
#include "utils/byte_buffer.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

namespace chara {

Karma::Karma() : context_(1), socket_(context_), acceptor_(context_) {}

void Karma::DoTcpAccept() {
  acceptor_.async_accept([this](const std::error_code &ec, neti::tcp::socket socket) {
    if (!ec) {
      std::make_shared<TcpSession>(std::move(socket))->Start();
    }
    DoTcpAccept();
  });
}

void Karma::DoUdpAccept() {
  ByteBuffer buffer{kDnsUdpLength};
  auto bufp = buffer.ToMutableBuffer();
  auto endpoint = std::make_shared<neti::udp::endpoint>();

  socket_.async_receive_from(bufp, *endpoint, [this, endpoint, buffer = std::move(buffer)](auto ec, auto b) mutable {
    if (!ec) {
      buffer.set_length(b);
      std::make_shared<UdpSession>(context_, *endpoint, std::move(buffer))->Start();
    }
    DoUdpAccept();
  });
}

void Karma::SetTcpOption() {
  acceptor_.open(neti::tcp::v4());
  int buf = 1;
  setsockopt(acceptor_.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
  acceptor_.bind({neti::tcp::v4(), kDnsServerPort});
  acceptor_.listen(ASIO_OS_DEF_SOMAXCONN);
}

void Karma::SetUdpOption() {
  socket_.open(neti::udp::v4());
  int buf = 1;
  setsockopt(socket_.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
  socket_.bind({neti::udp::v4(), kDnsServerPort});
}

void Karma::Run() {
  SetTcpOption();
  SetUdpOption();
  DoTcpAccept();
  DoUdpAccept();
  context_.run();
}

}
#pragma clang diagnostic pop