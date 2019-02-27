//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "udp_session.h"

namespace chara {

UdpSession::UdpSession(neti::udp::socket socket, neti::udp::endpoint endpoint, ByteBuffer buffer) :
    socket_(std::move(socket)), endpoint_(std::move(endpoint)), buffer_(std::move(buffer)) {}

void UdpSession::Start() {

}

}
