//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_H
#define CHARA_DNS_H

#include <string>

#include "../utils/byte.h"
#include "../utils/byte_buffer.h"

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
  Word flags;
  Word questions;
  Word answer_rrs;
  Word authority_rrs;
  Word additional_rrs;
};

struct DnsOriginQuestion {
  Word qtype;
  Word qclass;
};

struct DnsOriginRr {
  Word type;
  Word rrclass;
  DoubleWord ttl;
  Word rdlength;
};

enum DnsHeaderOpcode {
  kDHOQuery = 0,
  kDHOInverseQuery = 1,
  kDHOStatus = 2,
};

enum DnsHeaderRcode {
  kDHRSuccess = 0,
  kDHRFormatError = 1,
  kDHRServerError = 2,
  kDHRNameNotFound = 3,
  kDHRNotImplmentation = 4,
  kDHRServerDenied = 5,
};

enum DnsRrType {
  kDRTA = 1,
  kDRTNs = 2,
  kDRTCname = 5,
  kDRTSoa = 6,
  kDRTPtr = 12,
  kDRTMx = 15,
  kDRTTxt = 16,
};

enum DnsRrClass {
  kDRCIn = 1,
};

void SetDnsFlagQr(Word &word, bool qr);
bool GetDnsFlagQr(Word word);

void SetDnsFlagOpcode(Word &word, DnsHeaderOpcode code);
DnsHeaderOpcode GetDnsFlagOpcode(Word word);

void SetDnsFlagAa(Word &word, bool aa);
bool GetDnsFlagAa(Word word);

void SetDnsFlagTc(Word &word, bool tc);
bool GetDnsFlagTc(Word word);

void SetDnsFlagRd(Word &word, bool rd);
bool GetDnsFlagRd(Word word);

void SetDnsFlagRa(Word &word, bool ra);
bool GetDnsFlagRa(Word word);

void SetDnsFlagRcode(Word &word, DnsHeaderRcode code);
DnsHeaderRcode GetDnsFlagRcode(Word word);

constexpr Word MakeDnsLabelPointer(Word pointer);

ByteBuffer MakeDnsLabelString(const std::string &str);

}

#endif //CHARA_DNS_H