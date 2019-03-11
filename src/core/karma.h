//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_KARMA_H
#define CHARA_KARMA_H

#include <core/dns_resolver.h>
#include <utils/net_assist.h>

namespace chara {

class Karma {
 public:
  // constructors
  Karma();

  // general functions
  void Run();
  void DoTcpAccept();
  void DoUdpAccept();
 private:
  net::io_context context_;
  DnsResolver resolver_;
  neti::tcp::acceptor acceptor_;
  neti::udp::socket receiver_;
  neti::udp::socket sender_;
};

}

#endif // CHARA_KARMA_H
