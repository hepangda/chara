//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "tcp_session.h"
#include "byte_buffer.h"
#include <iostream>
namespace chara {

TcpSession::TcpSession(asio::io_context &context, asio::ip::tcp::socket socket)
    : socket_(std::move(socket)) {}

void TcpSession::Consume() {
  //
}

void TcpSession::Receive(std::shared_ptr<TcpSession> self, const std::error_code &ec, std::size_t bytes) {
  if (!ec) {
    self->buffer_.commit(bytes);
    if (self->size_ == self->buffer_.size()) {
      self->Consume();
    } else {
      auto buf = self->buffer_.prepare(self->size_ - self->buffer_.size());
      self->socket_.async_receive(buf, [self](const std::error_code &ec, std::size_t bytes) {
        Receive(self, ec, bytes);
      });
    }
  }
}

void TcpSession::Start() {
  auto len_buf = std::make_shared<ByteBuffer>(2);
  auto self = this->shared_from_this();
  socket_.async_receive(len_buf->ToMutableBuffer(), [self, len_buf](const std::error_code &ec, std::size_t bytes) {
    if (!ec) {
      // TODO: set size_ here.
      auto buf = self->buffer_.prepare(self->size_);
      self->socket_.async_receive(buf, [self](const std::error_code &ec, std::size_t bytes) {
        Receive(self, ec, bytes);
      });
    }
  });
}

}
