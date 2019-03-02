//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "udp_session.h"
#include <iostream>
namespace chara {

UdpSession::UdpSession(net::io_context &context, neti::udp::endpoint endpoint, ByteBuffer buffer) :
    endpoint_(std::move(endpoint)), buffer_(std::move(buffer)), rep_socket_(context), socket_(context) {
}

void UdpSession::Start() {
  auto self = shared_from_this();
  rep_socket_.connect(neti::udp::endpoint{neti::make_address("114.114.114.114"), 53});
  rep_socket_.async_send(buffer_.ToConstBuffer(), [self](const std::error_code &ec, size_t bytes) {
    auto p = self->rep_buf_.prepare(512);
    self->rep_socket_.async_receive(p, [self](const std::error_code &ec, size_t bytes) {
      self->rep_buf_.commit(bytes);

      self->socket_.open(neti::udp::v4());
      int buf = 1;
      setsockopt(self->socket_.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
      self->socket_.bind({neti::udp::v4(), 53});

      self->socket_.async_send_to(self->rep_buf_.data(),
          self->endpoint_,
          [self](const std::error_code &ec, size_t bytes) {
            printf("Twice Send %zu bytes, ec: %s\n", bytes, ec.message().c_str());
          });
    });
  });
}

}
