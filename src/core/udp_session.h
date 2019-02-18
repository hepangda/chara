//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_UDP_SESSION_H
#define CHARA_UDP_SESSION_H

#include <utility>

#include <asio.hpp>

#include "../utils/byte.h"
#include "../utils/byte_buffer.h"

namespace chara {

class UdpSession : public std::enable_shared_from_this<UdpSession> {
 public:
  UdpSession(asio::ip::udp::socket socket, asio::ip::udp::endpoint endpoint, ByteBuffer buffer);

  void Start();
 private:
  ByteBuffer buffer_;
  asio::ip::udp::socket socket_;
  asio::ip::udp::endpoint endpoint_;
};

}

#endif //CHARA_UDP_SESSION_H
