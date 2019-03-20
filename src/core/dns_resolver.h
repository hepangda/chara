//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_RESOLVER_H
#define CHARA_DNS_RESOLVER_H

#include <protocol/dns_packet.h>
namespace chara {

class DnsResolver {
 public:
  template <typename Callable, typename ...Args>
  void Delegate(DnsPacket packet, Callable callable, Args... args) {
    callable(std::forward(args)...);
  }
};

}

#endif // CHARA_DNS_RESOLVER_H