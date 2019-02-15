//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_BYTE_BUFFER_H
#define CHARA_BYTE_BUFFER_H

#include <memory>

#include "byte.h"
#include "noncopyable.h"
#include <asio.hpp>

namespace chara {

class ByteBuffer : public Noncopyable {
 public:
  explicit ByteBuffer(size_t size);
  ByteBuffer(ByteBuffer &&buffer) noexcept;

  asio::mutable_buffer ToMutableBuffer();
  asio::const_buffer ToConstBuffer();

  std::size_t size() const { return size_; }
  std::size_t length() const { return length_; }
  void set_length(std::size_t length) { length_ = length; }
 private:
  std::unique_ptr<Byte> ptr_;
  std::size_t length_;
  std::size_t size_;
};

}

#endif //CHARA_BYTE_BUFFER_H