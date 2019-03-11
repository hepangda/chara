//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include <protocol/dnsds.h>
#include "tcp_session.h"

#include "utils/byte_buffer.h"
#include "utils/streambuf_guard.h"

namespace chara {
TcpSession::TcpSession(DnsResolver &resolver, asio::ip::tcp::socket socket)
    : resolver_(resolver), socket_(std::move(socket)) {}

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
  auto len_buf = buffer_.prepare(2);
  auto self = this->shared_from_this();
  socket_.async_receive(len_buf, [self](const std::error_code &ec, std::size_t bytes) {
    if (!ec) {
      {
        StreambufGuard guard{self->buffer_, 2};
        self->size_ = ExtractWord(self->buffer_.data().data());
      }
      auto buf = self->buffer_.prepare(self->size_);
      self->socket_.async_receive(buf, [self](const std::error_code &ec, std::size_t bytes) {
        Receive(self, ec, bytes);
      });
    }
  });
}

}
