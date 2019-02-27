//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_KARMA_H
#define CHARA_KARMA_H

#include "../utils/net_assist.h"

namespace chara {

class Karma {
 public:
  // constructors
  Karma();

  // general functions
  void Run();
  void DoTcpAccept();
  void DoUdpAccept();
  void SetTcpOption();
  void SetUdpOption(neti::udp::socket &socket, neti::udp::endpoint &endpoint);
 private:
  net::io_context context_;
  neti::tcp::acceptor acceptor_;
};

}

#endif //CHARA_KARMA_H
