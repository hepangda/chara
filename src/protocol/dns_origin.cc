//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "dns_origin.h"

#include "../utils/byte_buffer.h"

namespace chara {

ByteBuffer MakeDnsLabelString(const std::string &str) {
  // TODO: code here...
  ByteBuffer ret {str.length()};
  return ret;
}

}