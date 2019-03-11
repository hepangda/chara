//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "karma.h"

#include "core/tcp_session.h"
#include "core/udp_session.h"
#include "protocol/dnsds.h"
#include "utils/byte_buffer.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"

namespace chara {

Karma::Karma() : context_(1), receiver_(context_), acceptor_(context_), sender_(context_) {}

void Karma::DoTcpAccept() {
  acceptor_.async_accept([this](const std::error_code &ec, neti::tcp::socket socket) {
    if (!ec) {
      std::make_shared<TcpSession>(resolver_, std::move(socket))->Start();
    }
    DoTcpAccept();
  });
}

void Karma::DoUdpAccept() {
  auto buffer = std::make_shared<ByteBuffer>(kDnsUdpPacketMaxLength);
  auto buf_seq = buffer->ToMutableBuffer();
  auto endpoint = std::make_shared<neti::udp::endpoint>();

  receiver_.async_receive_from(buf_seq, *endpoint, [this, endpoint, buffer](auto ec, auto b) {
    if (!ec) {
      buffer->set_length(b);
      std::make_shared<UdpSession>(resolver_, buffer, endpoint)->Start();
    }
    DoUdpAccept();
  });
}

void Karma::Run() {
  ListenWithReusePort(acceptor_, neti::tcp::v4(), {neti::tcp::v4(), kCharaPort});
  OpenWithReusePort(receiver_, neti::udp::v4(), {neti::udp::v4(), kCharaPort});

  DoTcpAccept();
  DoUdpAccept();

  context_.run();
}

}
#pragma clang diagnostic pop