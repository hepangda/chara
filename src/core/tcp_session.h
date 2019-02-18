//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_TCP_SESSION_H
#define CHARA_TCP_SESSION_H

#include <asio.hpp>
#include <utility>

namespace chara {

class TcpSession : public std::enable_shared_from_this<TcpSession> {
 public:
  explicit TcpSession(asio::ip::tcp::socket socket);

  void Start();
 private:
  static void Receive(std::shared_ptr<TcpSession> self, const std::error_code &ec, std::size_t bytes);
  void Consume();

  asio::ip::tcp::socket socket_;
  asio::streambuf buffer_;
  std::size_t size_;
};

}

#endif //CHARA_TCP_SESSION_H
