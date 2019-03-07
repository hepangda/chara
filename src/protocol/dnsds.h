//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNSDS_H
#define CHARA_DNSDS_H

#include <string>

#include "utils/byte.h"

namespace chara {

enum DnsHeaderOpcode : Word {
  kDHOQuery = 0,
  kDHOInverseQuery = 1,
  kDHOStatus = 2,
};

enum DnsHeaderRcode : Word {
  kDHRSuccess = 0,
  kDHRFormatError = 1,
  kDHRServerError = 2,
  kDHRNameNotFound = 3,
  kDHRNotImplmentation = 4,
  kDHRServerDenied = 5,
};

enum DnsRrType : Word {
  kDRTA = 1,
  kDRTNs = 2,
  kDRTCname = 5,
  kDRTSoa = 6,
  kDRTPtr = 12,
  kDRTMx = 15,
  kDRTTxt = 16,
};

enum DnsRrClass : Word {
  kDRCIn = 1,
};

constexpr Word MakeDnsLabelPointer(Word pointer) {
  return pointer | ToWord(0xc000);
}

}

#endif // CHARA_DNSDS_H