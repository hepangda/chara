//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_TCP_SESSION_H
#define CHARA_TCP_SESSION_H

#include <utility>

#include "../utils/net_assist.h"

namespace chara {

class TcpSession : public std::enable_shared_from_this<TcpSession> {
 public:
  // constructors
  explicit TcpSession(neti::tcp::socket socket);

  // general functions
  void Start();
 private:
  // callbacks
  static void Receive(std::shared_ptr<TcpSession> self, const std::error_code &ec, std::size_t bytes);

  // helper functions
  void Consume();

  // members
  neti::tcp::socket socket_;
  net::streambuf buffer_;
  std::size_t size_;
};

}

#endif //CHARA_TCP_SESSION_H
