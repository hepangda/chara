//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_packet.h"

namespace chara {

DnsPacket ConstructDnsPacket(const void *stream) {
  void *base = const_cast<void *>(stream), *cursor = const_cast<void *>(stream);

  DnsPacket ret;
  ret.header_ = ConstructDnsHeader(&cursor, base);

  for (int i = 0; i < ret.header_.questions(); i++) {
    ret.questions_.emplace_back(std::move(ConstructDnsQuery(&cursor, base)));
  }

  for (int i = 0; i < ret.header_.answer_rrs(); i++) {
    ret.answers_.emplace_back(std::move(ConstructDnsResourceRecord(&cursor, base)));
  }

  for (int i = 0; i < ret.header_.authority_rrs(); i++) {
    ret.authority_.emplace_back(std::move(ConstructDnsResourceRecord(&cursor, base)));
  }

  for (int i = 0; i < ret.header_.additional_rrs(); i++) {
    ret.additonal_.emplace_back(std::move(ConstructDnsResourceRecord(&cursor, base)));
  }

  return std::move(ret);
}

const DnsHeader &DnsPacket::header() const {
  return header_;
}
const std::vector<DnsQuery> &DnsPacket::questions() const {
  return questions_;
}
const std::vector<DnsResourceRecord> &DnsPacket::answers() const {
  return answers_;
}
const std::vector<DnsResourceRecord> &DnsPacket::authority() const {
  return authority_;
}
const std::vector<DnsResourceRecord> &DnsPacket::additonal() const {
  return additonal_;
}

DnsPacket &DnsPacket::operator =(DnsPacket &&rhs) noexcept {
  header_ = rhs.header_;
  questions_ = std::move(rhs.questions_);
  answers_ = std::move(rhs.answers_);
  authority_ = std::move(rhs.authority_);
  additonal_ = std::move(rhs.additonal_);
  return *this;
}


}