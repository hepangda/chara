//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_query.h"

#include <cstring>

namespace chara {

DnsQuery::DnsQuery(DnsRrType qtype, DnsRrClass qclass) :
    qtype_(qtype), qclass_(qclass), qname_(nullptr) {}

DnsQuery::DnsQuery(const std::string &domain_name, DnsRrType qtype, DnsRrClass qclass) :
    qtype_(qtype), qclass_(qclass), qname_(std::make_unique<DnsDomainName>(domain_name)) {}

DnsQuery::DnsQuery(const char *domain_name, std::size_t length, chara::DnsRrType qtype, chara::DnsRrClass qclass) :
    qtype_(qtype), qclass_(qclass), qname_(std::make_unique<DnsDomainName>(domain_name, length)) {}

DnsQuery ConstructDnsQuery(void *&stream) {
  auto length = strlen(static_cast<char *>(stream));

  DnsQuery ret;
  ret.qname_ = ConstructDnsDomainName(stream, length);
  auto nptr = reinterpret_cast<Word *>(static_cast<Byte *>(stream) + length);
  ret.qtype_ = *nptr;
  ret.qclass_ = *(nptr + 1);

  stream = reinterpret_cast<void *>(nptr + 2);
  return std::move(ret);
}

}