//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_KARMA_H
#define CHARA_KARMA_H

#include <asio.hpp>

namespace chara {

class Karma {
 public:
  Karma();
  void Run();
  void DoTcpAccept();
  void DoUdpAccept();
  void SetTcpOption();
  void SetUdpOption(asio::ip::udp::socket &socket, asio::ip::udp::endpoint &endpoint);
 private:
  asio::io_context context_;
  asio::ip::tcp::acceptor acceptor_;
};

}

#endif //CHARA_KARMA_H