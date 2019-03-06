//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "dns_header.h"

namespace chara {

void DnsHeader::set_flag_qr(bool qr) {
  constexpr Word kSetQr = 0b1000'0000'0000'0000;
  constexpr Word kUnsetQr = 0b0111'1111'1111'1111;
  (qr) ? (flags_ |= kSetQr) : (flags_ &= kUnsetQr);
}
bool DnsHeader::flag_qr() const {
  constexpr Word getter = 0b1000'0000'0000'0000;
  return static_cast<bool>(flags_ & getter);
}

void DnsHeader::set_flag_opcode(DnsHeaderOpcode opcode) {
  const Word setter = (opcode << 11) | 0b1000'0111'1111'1111;
  flags_ &= setter;
}
DnsHeaderOpcode DnsHeader::flag_opcode() const {
  constexpr Word getter = 0b0111'1000'0000'0000;
  return static_cast<DnsHeaderOpcode>((flags_ & getter) >> 11);
}

void DnsHeader::set_flag_aa(bool aa) {
  constexpr Word kSetAa = 0b0000'0100'0000'0000;
  constexpr Word kUnsetAa = 0b1111'1011'1111'1111;
  (aa) ? (flags_ |= kSetAa) : (flags_ &= kUnsetAa);
}
bool DnsHeader::flag_aa() const {
  constexpr Word getter = 0b0000'0100'0000'0000;
  return static_cast<bool>(flags_ & getter);
}

void DnsHeader::set_flag_tc(bool tc) {
  constexpr Word kSetTc = 0b0000'0010'0000'0000;
  constexpr Word kUnsetTc = 0b1111'1101'1111'1111;
  (tc) ? (flags_ |= kSetTc) : (flags_ &= kUnsetTc);
}
bool DnsHeader::flag_tc() const {
  constexpr Word getter = 0b0000'0010'0000'0000;
  return static_cast<bool>(flags_ & getter);
}

void DnsHeader::set_flag_rd(bool rd) {
  constexpr Word kSetRd = 0b0000'0001'0000'0000;
  constexpr Word kUnsetRd = 0b1111'1110'1111'1111;
  (rd) ? (flags_ |= kSetRd) : (flags_ &= kUnsetRd);
}
bool DnsHeader::flag_rd() const {
  constexpr Word getter = 0b0000'0001'0000'0000;
  return static_cast<bool>(flags_ & getter);
}

void DnsHeader::set_flag_ra(bool ra) {
  constexpr Word kSetRa = 0b0000'0000'1000'0000;
  constexpr Word kUnsetRa = 0b1111'1111'0111'1111;
  (ra) ? (flags_ |= kSetRa) : (flags_ &= kUnsetRa);
}
bool DnsHeader::flag_ra() const {
  constexpr Word getter = 0b0000'0000'1000'0000;
  return static_cast<bool>(flags_ & getter);
}

void DnsHeader::set_flag_rcode(DnsHeaderRcode rcode) {
  const Word setter = rcode | 0b1111'1111'1111'0000;
  flags_ &= setter;
}
DnsHeaderRcode DnsHeader::flag_rcode() const {
  constexpr Word getter = 0b0000'0000'0000'1111;
  return static_cast<DnsHeaderRcode>(flags_ & getter);
}

DnsHeader ConstructDnsHeader(void *&stream) {
  DnsHeader ret;
  memcpy(&ret, stream, sizeof(DnsHeader));
  ret.transaction_id_ = ExchangeEndian(ret.transaction_id_);
  ret.flags_ = ExchangeEndian(ret.flags_);
  ret.questions_ = ExchangeEndian(ret.questions_);
  ret.answer_rrs_ = ExchangeEndian(ret.answer_rrs_);
  ret.authority_rrs_ = ExchangeEndian(ret.authority_rrs_);
  ret.additional_rrs_ = ExchangeEndian(ret.additional_rrs_);
  stream = static_cast<char *>(stream) + sizeof(DnsHeader);

  return ret;
}

}