//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_TCP_SESSION_H
#define CHARA_TCP_SESSION_H

#include "session.h"
#include <asio.hpp>

namespace chara {

class TcpSession : public Session {
 public:
  TcpSession(asio::io_context &context, asio::ip::tcp::socket socket);

  void Start() final;
 private:
  asio::ip::tcp::socket socket_;
};

}

#endif //CHARA_TCP_SESSION_H
