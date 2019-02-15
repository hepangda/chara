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
 private:
  asio::io_context context_;
  asio::ip::tcp::acceptor tcp_acceptor_;
  asio::ip::udp::socket udp_acceptor_;

};

}

#endif //CHARA_KARMA_H
