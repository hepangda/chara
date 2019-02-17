//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_UDP_SESSION_H
#define CHARA_UDP_SESSION_H

#include "session.h"
#include "byte.h"
#include "byte_buffer.h"

#include <asio.hpp>

namespace chara {

class UdpSession : public Session {
 public:
  explicit UdpSession(asio::io_context &context, ByteBuffer buffer);

  void Start() final;
 private:
  ByteBuffer buffer_;
};

}


#endif //CHARA_UDP_SESSION_H
