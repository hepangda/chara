//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "dns_origin.h"

#include "../utils/byte_buffer.h"

namespace chara {

namespace detail {

size_t CalcLabelBufferLength(const std::string &str) {
  return str.length() + ((str.back() == '.') ? 1 : 2);
}

size_t CalcLabelBufferLength(const char *str, size_t length) {
  return length + ((str[length - 1] == '.') ? 1 : 2);
}

}

ByteBuffer MakeDnsLabelString(const std::string &str) {
  ByteBuffer ret{detail::CalcLabelBufferLength(str)};
  auto pstart = ret.pointer();
  Byte c = 0;
  auto last = 0;
  for (auto i = 1, j = 0; i < ret.size(); i++, j++) {
    if (str[j] == '.' || str[j] == '\0') {
      pstart[last] = c+'0';
      c = 0;
      last = i;
    } else {
      pstart[i] = static_cast<Byte>(str[j]);
      c++;
    }
  }

  return std::move(ret);
}

}