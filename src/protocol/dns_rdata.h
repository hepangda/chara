//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_RDATA_H
#define CHARA_DNS_RDATA_H

#include <memory>

#include "utils/byte_buffer.h"
#include "protocol/dns_domain_name.h"

namespace chara {

class DnsRdata {
 public:
  enum { kDefaultSize = 16 };

  // constructors
  DnsRdata() : buf_(kDefaultSize) {}

  // setters
  void SetRaw(void *src, size_t size);

  void SetCname(const DnsDomainName &name);
  void SetCname(DnsDomainName &&name);

  void SetMx(Word preference, const DnsDomainName &exchange);
  void SetMx(Word preference, DnsDomainName &&exchange);

  void SetNs(const DnsDomainName &name);
  void SetNs(DnsDomainName &&name);

  void SetPtr(const DnsDomainName &name);
  void SetPtr(DnsDomainName &&name);

  void SetTxt(Byte length, char *txt);

  void SetA(const std::string &dotdex);
  void SetA(const char *dotdex, size_t length);

  void SetSoa(const DnsDomainName &mname, const DnsDomainName &rname, DoubleWord serial, DoubleWord refresh,
              DoubleWord retry, DoubleWord expire, DoubleWord minimum);

  void SetSoa(DnsDomainName &&mname, DnsDomainName &&rname, DoubleWord serial, DoubleWord refresh, DoubleWord retry,
              DoubleWord expire, DoubleWord minimum);

  // getters
  void Output(void *dest) const;
 private:
  ByteBuffer buf_;
};

}

#endif // CHARA_DNS_RDATA_H
