//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_query.h"

#include <cstring>

namespace chara {

DnsQuery::DnsQuery(std::unique_ptr<DnsDomainName> qname, Word qtype, Word qclass)
    : qname_(std::move(qname)), qtype_(qtype), qclass_(qclass) {}

DnsQuery::DnsQuery(DnsRrType qtype, DnsRrClass qclass) :
    qtype_(qtype), qclass_(qclass), qname_(nullptr) {}

DnsQuery::DnsQuery(const std::string &domain_name, DnsRrType qtype, DnsRrClass qclass) :
    qtype_(qtype), qclass_(qclass), qname_(std::make_unique<DnsDomainName>(domain_name)) {}

DnsQuery::DnsQuery(const char *domain_name, std::size_t length, chara::DnsRrType qtype, chara::DnsRrClass qclass) :
    qtype_(qtype), qclass_(qclass), qname_(std::make_unique<DnsDomainName>(domain_name, length)) {}

DnsQuery ConstructDnsQuery(void **cursor, void *base) {
  return std::move(DnsQuery{
      ConstructDnsDomainName(cursor, base),  // qname_
      ExtractWord(cursor),                   // qtype_
      ExtractWord(cursor),                   // qclass_
  });
}


}