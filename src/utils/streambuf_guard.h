//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_STREAMBUF_GUARD_H
#define CHARA_STREAMBUF_GUARD_H

#include "utils/net_assist.h"
#include "utils/noncopyable.h"

namespace chara {

class StreambufGuard : public Noncopyable {
 public:
  // constructors
  StreambufGuard(net::streambuf &buf, std::size_t size): ref_(buf), size_(size) {
    ref_.commit(size_);
  }

  // destructors
  ~StreambufGuard() {
    ref_.consume(size_);
  }
 private:
  net::streambuf &ref_;
  std::size_t size_;
};

}

#endif // CHARA_STREAMBUF_GUARD_H
