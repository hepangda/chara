//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "udp_session.h"
#include <iostream>
#include <protocol/dnsds.h>
namespace chara {

UdpSession::UdpSession(DnsResolver &resolver, const std::shared_ptr<ByteBuffer> &buffer,
                       const std::shared_ptr<asio::ip::udp::endpoint> &endpoint)
    : resolver_(resolver), buffer_(buffer), endpoint_(endpoint) {}

void UdpSession::Start() {
//  auto self = shared_from_this();
//  rep_socket_.connect(neti::udp::endpoint{neti::make_address("114.114.114.114"), kDnsRemoteServerPort});
//  rep_socket_.async_send(buffer_.ToConstBuffer(), [self](const std::error_code &ec, size_t bytes) {
//    auto p = self->rep_buf_.prepare(kDnsUdpPacketMaxLength);
//    self->rep_socket_.async_receive(p, [self](const std::error_code &ec, size_t bytes) {
//      self->rep_buf_.commit(bytes);
//
//      OpenWithReusePort(self->socket_, neti::udp::v4(), {neti::udp::v4(), kCharaPort});
//
//      self->socket_.async_send_to(self->rep_buf_.data(), self->endpoint_,
//          [self](const std::error_code &ec, size_t bytes) {
//            printf("Twice Send %zu bytes, ec: %s\n", bytes, ec.message().c_str());
//          });
//    });
//  });
}

}
