//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_packet.h"

namespace chara {

DnsPacket ConstructDnsPacket(void *stream) {
  DnsPacket ret;
  ret.header_ = ConstructDnsHeader(stream);

  for (int i = 0; i < ret.header_.questions(); i++) {
    ret.questions_.emplace_back(std::move(ConstructDnsQuery(stream)));
  }

  for (int i = 0; i < ret.header_.answer_rrs(); i++) {
    ret.answers_.emplace_back(std::move(ConstructDnsResourceRecord(stream)));
  }

  for (int i = 0; i < ret.header_.authority_rrs(); i++) {
    ret.authority_.emplace_back(std::move(ConstructDnsResourceRecord(stream)));
  }

  for (int i = 0; i < ret.header_.additional_rrs(); i++) {
    ret.additonal_.emplace_back(std::move(ConstructDnsResourceRecord(stream)));
  }

  return std::move(ret);
}

}