//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "byte_buffer.h"

namespace chara {

ByteBuffer::ByteBuffer(size_t size) : ptr_(std::make_unique<Byte>(size)), size_(size) {}

ByteBuffer::ByteBuffer(ByteBuffer &&buffer) noexcept : ptr_(buffer.ptr_.release()), size_(buffer.size_) {}

asio::const_buffer ByteBuffer::ToConstBuffer() {
  return asio::buffer(ptr_.get(), size_);
}

asio::mutable_buffer ByteBuffer::ToMutableBuffer() {
  return asio::buffer(ptr_.get(), size_);
}

}