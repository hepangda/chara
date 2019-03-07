//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_rdata.h"

namespace chara {

namespace detail {
void OnlyPutBuffer(ByteBuffer &buf, const DnsDomainName &ddn) {
  buf.Put(ddn.buffer());
}

const DoubleWord MakeDnsARecord(const char *dotdex, size_t length) {
  Byte ret[4] = {0};
  int now = 0;
  for (int i = 0; i < length; i++) {
    if (dotdex[i] == '.') {
      now++;
    } else {
      ret[now] *= 10;
      ret[now] += dotdex[i] - '0';
    }
  }
  return *reinterpret_cast<DoubleWord *>(ret);
}
}

void DnsRdata::SetRaw(void *src, size_t size) {
  buf_.Put(src, size);
}

void DnsRdata::SetCname(const DnsDomainName &name) {
  detail::OnlyPutBuffer(buf_, name);
}

void DnsRdata::SetCname(DnsDomainName &&name) {
  detail::OnlyPutBuffer(buf_, name);
}

void DnsRdata::SetMx(Word preference, const DnsDomainName &exchange) {
  buf_.Put(preference);
  buf_.Put(exchange.buffer());
}

void DnsRdata::SetMx(Word preference, DnsDomainName &&exchange) {
  buf_.Put(preference);
  buf_.Put(exchange.buffer());
}

void DnsRdata::SetNs(const DnsDomainName &name) {
  detail::OnlyPutBuffer(buf_, name);
}

void DnsRdata::SetNs(DnsDomainName &&name) {
  detail::OnlyPutBuffer(buf_, name);
}

void DnsRdata::SetPtr(const DnsDomainName &name) {
  detail::OnlyPutBuffer(buf_, name);
}

void DnsRdata::SetPtr(DnsDomainName &&name) {
  detail::OnlyPutBuffer(buf_, name);
}

void DnsRdata::SetTxt(Byte length, char *txt) {
  buf_.Put(length);
  buf_.Put(txt, length);
}

void DnsRdata::SetA(const std::string &dotdex) {
  SetA(dotdex.c_str(), dotdex.length());
}

void DnsRdata::SetA(const char *dotdex, size_t length) {
  DoubleWord dw = detail::MakeDnsARecord(dotdex, length);
  buf_.Put(dw);
}

void DnsRdata::SetSoa(const DnsDomainName &mname, const DnsDomainName &rname, DoubleWord serial, DoubleWord refresh,
                      DoubleWord retry, DoubleWord expire, DoubleWord minimum) {
  buf_.Put(mname.buffer());
  buf_.Put(rname.buffer());
  buf_.Put(serial);
  buf_.Put(refresh);
  buf_.Put(retry);
  buf_.Put(expire);
  buf_.Put(minimum);
}

void DnsRdata::SetSoa(DnsDomainName &&mname, DnsDomainName &&rname, DoubleWord serial, DoubleWord refresh,
                      DoubleWord retry, DoubleWord expire, DoubleWord minimum) {
  buf_.Put(mname.buffer());
  buf_.Put(rname.buffer());
  buf_.Put(serial);
  buf_.Put(refresh);
  buf_.Put(retry);
  buf_.Put(expire);
  buf_.Put(minimum);
}

void DnsRdata::Output(void *dest) const {
  memcpy(dest, buf_.const_pointer(), buf_.length());
}

}