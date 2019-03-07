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

template<typename T>
constexpr Word ToWord(T arg) {
  return static_cast<Word>(arg);
}

constexpr Word ExchangeEndian(Word w) {
  return (w >> 8) | (w << 8);
}

constexpr DoubleWord ExchangeEndian(DoubleWord w) {
  return ((w & 0xff000000) << 24) | ((w & 0x000000ff) >> 24) | ((w & 0x00ff0000) << 8) | ((w & 0x0000ff00) >> 8);
}

}

#endif // CHARA_BYTE_H
