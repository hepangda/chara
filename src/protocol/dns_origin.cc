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
  *(ret.pointer<Byte>() + ret.size() - 1) = 0;
  return std::move(ret);
}

void SetDnsFlagQr(Word &word, bool qr) {
  constexpr Word kSetQR = 0b1000'0000'0000'0000;
  constexpr Word kUnsetQR = 0b0111'1111'1111'1111;
  (qr) ? (word |= kSetQR) : (word &= kUnsetQR);
}
bool GetDnsFlagQr(Word word) {
  constexpr Word getter = 0b1000'0000'0000'0000;
  return static_cast<bool>(word & getter);
}

void SetDnsFlagOpcode(Word &word, DnsHeaderOpcode code) {
  const Word setter = (code << 11) | 0b1000'0111'1111'1111;
  word &= setter;
}
DnsHeaderOpcode GetDnsFlagOpcode(Word word) {
  constexpr Word getter = 0b0111'1000'0000'0000;
  return static_cast<DnsHeaderOpcode>((word & getter) >> 11);
}

void SetDnsFlagAa(Word &word, bool aa) {
  constexpr Word kSetAA = 0b0000'0100'0000'0000;
  constexpr Word kUnsetAA = 0b1111'1011'1111'1111;
  (aa) ? (word |= kSetAA) : (word &= kUnsetAA);
}
bool GetDnsFlagAa(Word word) {
  constexpr Word getter = 0b0000'0100'0000'0000;
  return static_cast<bool>(word & getter);
}

void SetDnsFlagTc(Word &word, bool tc) {
  constexpr Word kSetTC = 0b0000'0010'0000'0000;
  constexpr Word kUnsetTC = 0b1111'1101'1111'1111;
  (tc) ? (word |= kSetTC) : (word &= kUnsetTC);
}
bool GetDnsFlagTc(Word word) {
  constexpr Word getter = 0b0000'0010'0000'0000;
  return static_cast<bool>(word & getter);
}

void SetDnsFlagRd(Word &word, bool rd) {
  constexpr Word kSetRD = 0b0000'0001'0000'0000;
  constexpr Word kUnsetRD = 0b1111'1110'1111'1111;
  (rd) ? (word |= kSetRD) : (word &= kUnsetRD);
}
bool GetDnsFlagRd(Word word) {
  constexpr Word getter = 0b0000'0001'0000'0000;
  return static_cast<bool>(word & getter);
}

void SetDnsFlagRa(Word &word, bool ra) {
  constexpr Word kSetRA = 0b0000'0000'1000'0000;
  constexpr Word kUnsetRA = 0b1111'1111'0111'1111;
  (ra) ? (word |= kSetRA) : (word &= kUnsetRA);
}
bool GetDnsFlagRa(Word word) {
  constexpr Word getter = 0b0000'0000'1000'0000;
  return static_cast<bool>(word & getter);
}

void SetDnsFlagRcode(Word &word, DnsHeaderRcode code) {
  const Word setter = code | 0b1111'1111'1111'0000;
  word &= setter;
}
DnsHeaderRcode GetDnsFlagRcode(Word word) {
  constexpr Word getter = 0b0000'0000'0000'1111;
  return static_cast<DnsHeaderRcode>(word & getter);
}

constexpr Word MakeDnsLabelPointer(Word pointer) {
  return pointer | ToWord(0xc000);
}

}