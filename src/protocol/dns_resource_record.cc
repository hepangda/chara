//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "protocol/dns_resource_record.h"

namespace chara {

DnsResourceRecord ConstructDnsResourceRecord(void **cursor, void *base) {
  DnsResourceRecord ret{
      std::move(ConstructDnsDomainName(cursor, base)),  // name_
      ExtractWord(cursor),                              // type_
      ExtractWord(cursor),                              // class_
      ExtractDoubleWord(cursor),                        // ttl_
      ExtractWord(cursor)                               // rdlength_
  };

  ret.rdata_.SetRaw(*cursor, ret.rdlength_);
  MovePointer(cursor, ret.rdlength_);

  return std::move(ret);
}

}