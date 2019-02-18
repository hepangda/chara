//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_H
#define CHARA_DNS_H

#include "../utils/byte.h"

namespace chara {

/*
 * DNS Format
 * Transcation ID
 * Flags
 * Questions
 * Answer RRs
 * Authority RRs
 * Additional RRs
 * Queries
 * Answers
 * Authoritative nameservers
 * Additional records
 */
struct DnsHeader {
  Word transaction_id;
  Word flag_qr : 1;
  Word flag_opcode : 4;
  Word flag_aa : 1;
  Word flag_tc : 1;
  Word flag_rd : 1;
  Word flag_ra : 1;
  Word flag_reserved: 3;
  Word flag_rcode : 4;
  Word questions;
  Word answer_records;
  Word authority_records;
  Word additional_records;
};

constexpr Word MakeDnsLabelPointer(Word pointer) {
  return pointer | ToWord(0xc000);
} 

enum DnsQueryType {
  kDQTA,
  kDQTNs,
  kDQTCname,
  kDQTSoa,
  kDQTWks,
  kDQTPtr,
  kDQTHinfo,
  kDQTMx,
  kDQTAaaa,
  kDQTAxfr,
  kDQTAny,
};

}

#endif //CHARA_DNS_H
