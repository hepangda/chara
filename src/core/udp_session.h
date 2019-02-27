//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_UDP_SESSION_H
#define CHARA_UDP_SESSION_H

#include <utility>

#include "../utils/net_assist.h"
#include "../utils/byte.h"
#include "../utils/byte_buffer.h"

namespace chara {

class UdpSession : public std::enable_shared_from_this<UdpSession> {
 public:
  // constructors
  UdpSession(neti::udp::socket socket, neti::udp::endpoint endpoint, ByteBuffer buffer);

  // general functions
  void Start();
 private:
  ByteBuffer buffer_;
  neti::udp::socket socket_;
  neti::udp::endpoint endpoint_;
};

}

#endif //CHARA_UDP_SESSION_H
