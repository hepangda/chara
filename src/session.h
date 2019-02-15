//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_SESSION_H
#define CHARA_SESSION_H

#include <utility>

#include <asio.hpp>

namespace chara {

class Session : public std::enable_shared_from_this<Session> {
 public:
  Session() = delete;
  explicit Session(asio::ip::tcp::socket socket);
 private:
  asio::ip::tcp::socket socket_;
};

}

#endif //CHARA_SESSION_H
