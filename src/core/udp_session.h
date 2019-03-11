//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_UDP_SESSION_H
#define CHARA_UDP_SESSION_H

#include <utility>
#include <core/dns_resolver.h>

#include "utils/net_assist.h"
#include "utils/byte.h"
#include "utils/byte_buffer.h"

namespace chara {

class UdpSession : public std::enable_shared_from_this<UdpSession> {
 public:
  // constructors
  UdpSession(DnsResolver &resolver, const std::shared_ptr<ByteBuffer> &buffer,
             const std::shared_ptr<asio::ip::udp::endpoint> &endpoint);
  // general functions
  void Start();
 private:
//  static void Receive(std::shared_ptr<UdpSession> self, )
  DnsResolver &resolver_;
  std::shared_ptr<ByteBuffer> buffer_;
  std::shared_ptr<neti::udp::endpoint> endpoint_;
};

}

#endif // CHARA_UDP_SESSION_H
