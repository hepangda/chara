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
  virtual void Start() = 0;
 protected:
  explicit Session(asio::io_context &context);
 private:
  asio::io_context &context_;
};

}

#endif //CHARA_SESSION_H
