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
  // constructors
  explicit ByteBuffer(size_t size);
  ByteBuffer(ByteBuffer &&buffer) noexcept;

  // setters
  void set_length(std::size_t length) { length_ = length; }

  // getters
  template <typename T = Byte>
  T *pointer() { return reinterpret_cast<T *>(ptr_.get()); }
  template <typename T = Byte>
  const T *const_pointer() const { return reinterpret_cast<const T *>(ptr_.get()); }
  std::size_t size() const { return size_; }
  std::size_t length() const { return length_; }

  // convert getters
  asio::mutable_buffer ToMutableBuffer();
  asio::const_buffer ToConstBuffer();

  // general functions
  void Reset(size_t size);
 private:
  std::unique_ptr<Byte[]> ptr_;
  std::size_t length_;
  std::size_t size_;
};

}

#endif //CHARA_BYTE_BUFFER_H