//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_PACKET_H
#define CHARA_DNS_PACKET_H

#include <vector>
#include "../utils/byte.h"
#include "dns_query.h"
#include "dns_header.h"
#include "dns_resource_record.h"
namespace chara {

class DnsPacket {
 public:
 private:
  DnsHeader header_;
  std::vector<DnsQuery> questions_;
  std::vector<DnsResourceRecord> answers_;
  std::vector<DnsResourceRecord> authority_;
  std::vector<DnsResourceRecord> additonal_;
};

}

#endif // CHARA_DNS_PACKET_H
