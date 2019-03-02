//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "dns_rdata.h"

namespace chara {

namespace detail {
void OnlyPutBuffer(ByteBuffer &buf, const DnsDomainName &ddn) {
  buf.Put(ddn.buffer());
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

}