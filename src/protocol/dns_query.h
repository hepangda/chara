//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_QUERY_H
#define CHARA_DNS_QUERY_H

#include "dnsds.h"
#include "dns_domain_name.h"
namespace chara {

class DnsQuery {
 public:
  // constructors
  explicit DnsQuery(DnsRrType qtype = kDRTA, DnsRrClass qclass = kDRCIn);
  explicit DnsQuery(const std::string &domain_name, DnsRrType qtype = kDRTA, DnsRrClass qclass = kDRCIn);
  DnsQuery(const char *domain_name, std::size_t length, DnsRrType qtype = kDRTA, DnsRrClass qclass = kDRCIn);

  // setters
  void set_domain_name(const std::string &domain_name) { qname_ = std::make_unique<DnsDomainName>(domain_name); }
  void set_domain_name(const char *domain_name, std::size_t length) {
    qname_ = std::make_unique<DnsDomainName>(domain_name, length);
  }
  void set_qtype(DnsRrType qtype) { qtype_ = static_cast<Word>(qtype); }
  void set_qclass(DnsRrClass qclass = kDRCIn) { qclass_ = static_cast<Word>(qclass); }

  // getters
  const char *domain_name() const { return (qname_ ? qname_->domain_name() : "");  }
  std::string domain_name_string() const { return (qname_ ? qname_->domain_name() : std::string()); }
  DnsRrType qtype() const { return static_cast<DnsRrType>(qtype_); }
  DnsRrClass qclass() const { return static_cast<DnsRrClass>(qclass_); }
 private:
  std::unique_ptr<DnsDomainName> qname_;
  Word qtype_;
  Word qclass_;
};

}

#endif // CHARA_DNS_QUERY_H