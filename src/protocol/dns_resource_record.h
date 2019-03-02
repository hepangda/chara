//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_RESOURCE_RECORD_H
#define CHARA_DNS_RESOURCE_RECORD_H

#include "dns_domain_name.h"
#include "dns_rdata.h"
namespace chara {

class DnsResourceRecord {
 public:
 private:
  DnsDomainName name_;
  Word type_;
  Word class_;
  DoubleWord ttl_;
  Word rdlength_;
  DnsRdata rdata_;
};

}

#endif // CHARA_DNS_RESOURCE_RECORD_H
