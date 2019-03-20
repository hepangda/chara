//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_PACKET_H
#define CHARA_DNS_PACKET_H

#include <vector>
#include "utils/byte.h"
#include "protocol/dns_query.h"
#include "protocol/dns_header.h"
#include "protocol/dns_resource_record.h"
namespace chara {

class DnsPacket {
 public:
  // constructors
  DnsPacket(DnsPacket &&packet) noexcept : header_(packet.header_), questions_(std::move(packet.questions_)),
      answers_(std::move(packet.answers_)), authority_(std::move(packet.authority_)),
      additonal_(std::move(packet.additonal_)) {}

  // operators
  DnsPacket &operator =(DnsPacket &&rhs) noexcept;

  // getters
  const DnsHeader &header() const;
  const std::vector<DnsQuery> &questions() const;
  const std::vector<DnsResourceRecord> &answers() const;
  const std::vector<DnsResourceRecord> &authority() const;
  const std::vector<DnsResourceRecord> &additonal() const;

  // raw constructor
  friend DnsPacket ConstructDnsPacket(const void *stream);
 private:
  DnsPacket() = default;

  DnsHeader header_;
  std::vector<DnsQuery> questions_;
  std::vector<DnsResourceRecord> answers_;
  std::vector<DnsResourceRecord> authority_;
  std::vector<DnsResourceRecord> additonal_;
};

DnsPacket ConstructDnsPacket(const void *stream);

}

#endif // CHARA_DNS_PACKET_H
