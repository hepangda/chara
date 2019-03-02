//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_HEADER_H
#define CHARA_DNS_HEADER_H

#include "../utils/byte.h"
#include "dnsds.h"

namespace chara {

class DnsHeader {
 public:
  // constructors
  DnsHeader() = default;

  // setters
  void set_transaction_id(Word id) { transaction_id_ = id; }
  void set_flag_qr(bool qr);
  void set_flag_opcode(DnsHeaderOpcode opcode);
  void set_flag_aa(bool aa);
  void set_flag_tc(bool tc);
  void set_flag_rd(bool rd);
  void set_flag_ra(bool ra);
  void set_flag_rcode(DnsHeaderRcode rcode);
  void set_questions(Word q) { questions_ = q;}
  void set_answer_rrs(Word rr) { answer_rrs_ = rr; }
  void set_authority_rrs(Word rr) { authority_rrs_ = rr; }
  void set_additional_rrs(Word rr) { additional_rrs_ = rr; }

  // getters
  Word transaction_id() const { return transaction_id_; }
  bool flag_qr() const;
  DnsHeaderOpcode flag_opcode() const;
  bool flag_aa() const;
  bool flag_tc() const;
  bool flag_rd() const;
  bool flag_ra() const;
  DnsHeaderRcode flag_rcode() const;
  Word questions() const { return questions_; }
  Word answer_rrs() const { return answer_rrs_; }
  Word authority_rrs() const { return authority_rrs_; }
  Word additional_rrs() const { return additional_rrs_; }
 private:
  Word transaction_id_;
  Word flags_ {0};
  Word questions_;
  Word answer_rrs_;
  Word authority_rrs_;
  Word additional_rrs_;
};

}

#endif // CHARA_DNS_HEADER_H