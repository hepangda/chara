//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include <core/udp_session.h>

#include <iostream>
#include <protocol/dnsds.h>
namespace chara {

UdpSession::UdpSession(DnsResolver &resolver, const std::shared_ptr<ByteBuffer> &buffer,
                       const std::shared_ptr<asio::ip::udp::endpoint> &endpoint)
    : resolver_(resolver), buffer_(buffer), endpoint_(endpoint) {}

void UdpSession::Start() {
  auto packet = ConstructDnsPacket(buffer_->pointer());
  resolver_.Delegate(std::move(packet), [] {
    // TODO: callback here
  });
}

}
