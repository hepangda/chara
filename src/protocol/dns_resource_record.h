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
  friend DnsResourceRecord ConstructDnsResourceRecord(void *&stream);

 private:
  explicit DnsResourceRecord(std::unique_ptr<DnsDomainName> ddn) : name_(std::move(*ddn)) {}

  DnsDomainName name_;
  Word type_ {0};
  Word class_ {0};
  DoubleWord ttl_ {0};
  Word rdlength_ {0};
  DnsRdata rdata_ {};
};

DnsResourceRecord ConstructDnsResourceRecord(void *&stream);

}

#endif // CHARA_DNS_RESOURCE_RECORD_H
