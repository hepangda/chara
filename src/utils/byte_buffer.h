//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_BYTE_BUFFER_H
#define CHARA_BYTE_BUFFER_H

#include <memory>

#include "utils/byte.h"
#include "utils/noncopyable.h"
#include "utils/net_assist.h"

namespace chara {

class ByteBuffer : public Noncopyable {
 public:
  // constructors
  explicit ByteBuffer(size_t size);
  ByteBuffer(ByteBuffer &&buffer) noexcept;

  // move operator
  ByteBuffer &operator =(ByteBuffer &&rhs) noexcept;

  // setters
  void set_length(std::size_t length) { length_ = length; }

  // getters
  template<typename T = Byte>
  T *pointer() { return reinterpret_cast<T *>(ptr_.get()); }
  template<typename T = Byte>
  T *write_pointer() { return reinterpret_cast<T *>(ptr_.get() + length_); }
  template<typename T = Byte>
  const T *const_pointer() const { return reinterpret_cast<const T *>(ptr_.get()); }
  std::size_t size() const { return size_; }
  std::size_t length() const { return length_; }

  // convert getters
  net::mutable_buffer ToMutableBuffer();
  net::const_buffer ToConstBuffer();

  // general functions
  size_t Available() const { return size_ - length_; }
  void Reset(size_t size);
  void Expand(size_t size);
  void CopyAll(ByteBuffer &dest) const;
  void Put(const ByteBuffer &buffer);
  void Put(const void *x, size_t size);
  template<typename T>
  void Put(T x) {
    if (Available() < sizeof(T)) {
      Expand(sizeof(T));
    }
    *write_pointer() = x;
    length_ += sizeof(T);
  }


 private:
  std::unique_ptr<Byte[]> ptr_;
  std::size_t length_;
  std::size_t size_;
};

}

#endif // CHARA_BYTE_BUFFER_H