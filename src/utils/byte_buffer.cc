//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "utils/byte_buffer.h"
#include <iostream>
namespace chara {

ByteBuffer::ByteBuffer(size_t size) : ptr_(std::make_unique<Byte[]>(size)), size_(size), length_(0) {}

ByteBuffer::ByteBuffer(ByteBuffer &&buffer) noexcept
    : ptr_(buffer.ptr_.release()), size_(buffer.size_), length_(buffer.length_) {}

ByteBuffer &ByteBuffer::operator=(ByteBuffer &&rhs) noexcept {
  ptr_.swap(rhs.ptr_);
  size_ = rhs.size_;
  length_ = rhs.length_;
  return *this;
}

net::const_buffer ByteBuffer::ToConstBuffer() {
  return asio::buffer(ptr_.get(), length_);
}

net::mutable_buffer ByteBuffer::ToMutableBuffer() {
  return asio::buffer(ptr_.get(), size_);
}

void ByteBuffer::Reset(size_t size) {
  ptr_ = std::make_unique<Byte[]>(size);
  size_ = size;
  length_ = 0;
}

void ByteBuffer::CopyAll(ByteBuffer &dest) const {
  dest.Reset(size());
  dest.size_ = size_;
  dest.length_ = length_;
  memcpy(dest.ptr_.get(), ptr_.get(), size());
}

void ByteBuffer::Expand(size_t size) {
  auto new_ptr = std::make_unique<Byte[]>(size_ + size);
  memcpy(new_ptr.get(), ptr_.get(), size_);
  ptr_.swap(new_ptr);
  size_ += size;
}

void ByteBuffer::Put(const void *x, size_t size) {
  if (Available() < size) {
    Expand(size);
  }
  memcpy(write_pointer(), x, size);
  length_ += size;
}

void ByteBuffer::Put(const ByteBuffer &buffer) {
  Put(buffer.const_pointer(), buffer.length());
}

}