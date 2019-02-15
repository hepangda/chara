//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "tcp_session.h"
#include "byte_buffer.h"
#include <iostream>
namespace chara {

TcpSession::TcpSession(asio::io_context &context, asio::ip::tcp::socket socket)
    : Session(context), socket_(std::move(socket)) {}

void TcpSession::Start() {
  ByteBuffer buf{1024};
  socket_.async_receive(buf.ToMutableBuffer(), [] (const std::error_code &ec, std::size_t bytes) {

  });
}

}
