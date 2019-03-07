//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_resource_record.h"

namespace chara {

DnsResourceRecord ConstructDnsResourceRecord(void *&stream) {
  DnsResourceRecord ret(std::move(ConstructDnsDomainName(stream)));

  ret.type_ = *static_cast<Word *>(stream);
  stream = static_cast<char *>(stream) + sizeof(Word);

  ret.class_ = *static_cast<Word *>(stream);
  stream = static_cast<char *>(stream) + sizeof(Word);

  ret.ttl_ = *static_cast<DoubleWord *>(stream);
  stream = static_cast<char *>(stream) + sizeof(DoubleWord);

  ret.rdlength_ = *static_cast<Word *>(stream);
  stream = static_cast<char *>(stream) + sizeof(Word);

  ret.rdata_.SetRaw(stream, ret.rdlength_);
  stream = static_cast<char *>(stream) + ret.rdlength_;

  return std::move(ret);
}

}