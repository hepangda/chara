//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_BYTE_H
#define CHARA_BYTE_H

#include <cstdint>

namespace chara {

using Byte = uint8_t;
using Word = uint16_t;
using DoubleWord = uint32_t;

template <typename T>
constexpr Word ToWord(T arg) {
  return static_cast<Word>(arg);
}

}

#endif // CHARA_BYTE_H
