//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_STREAMBUF_GUARD_H
#define CHARA_STREAMBUF_GUARD_H

#include <asio/streambuf.hpp>
#include "noncopyable.h"

namespace chara {

class StreambufGuard : public Noncopyable {
 public:
  StreambufGuard(asio::streambuf &buf, std::size_t size): ref_(buf), size_(size) {
    ref_.commit(size_);
  }
  ~StreambufGuard() {
    ref_.consume(size_);
  }
 private:
  asio::streambuf &ref_;
  std::size_t size_;
};

}

#endif //CHARA_STREAMBUF_GUARD_H
