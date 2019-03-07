//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_RESOURCE_RECORD_H
#define CHARA_DNS_RESOURCE_RECORD_H

#include "protocol/dns_domain_name.h"
#include "protocol/dns_rdata.h"

namespace chara {

class DnsResourceRecord {
 public:
  friend DnsResourceRecord ConstructDnsResourceRecord(void **cursor, void *base);

 private:
  DnsResourceRecord(std::unique_ptr<DnsDomainName> ddn, Word type, Word rclass, DoubleWord ttl, Word rdlength) :
      name_(std::move(*ddn)), type_(type), class_(rclass), ttl_(ttl), rdlength_(rdlength) {}

  DnsDomainName name_;
  Word type_;
  Word class_;
  DoubleWord ttl_;
  Word rdlength_;
  DnsRdata rdata_{};
};

DnsResourceRecord ConstructDnsResourceRecord(void **cursor, void *base);

}

#endif // CHARA_DNS_RESOURCE_RECORD_H
