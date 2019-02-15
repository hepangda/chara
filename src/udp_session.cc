//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "udp_session.h"

namespace chara {

UdpSession::UdpSession(asio::io_context &context, ByteBuffer buffer) :
    Session(context), buffer_(std::move(buffer)) {}

void UdpSession::Start() {

}

}
