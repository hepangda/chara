//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_DNS_DOMAIN_NAME_H
#define CHARA_DNS_DOMAIN_NAME_H

#include "../utils/byte_buffer.h"
#include "dnsds.h"
namespace chara {

class DnsDomainName : public Noncopyable {
 public:
  // constructors
  explicit DnsDomainName(const std::string &domain_name);
  explicit DnsDomainName(const char *domain_name);
  DnsDomainName(const char *domain_name, std::size_t length);

  // setters
  void set_domain_name(const std::string &domain_name);
  void set_domain_name(const char *domain_name);
  void set_domain_name(const char *domain_name, std::size_t length);

  // getters
  const char *domain_name() const { return reinterpret_cast<const char *>(store_.const_pointer()); }
  std::string domain_name_string() const { return std::move(std::string(store_.const_pointer<char>(), store_.size())); }

  // operators
  bool operator==(const DnsDomainName &rhs);

  // general functions
  DnsDomainName &&Copy() const;
  std::unique_ptr<DnsDomainName> CopyUniquePtr() const;
 private:
  void do_set_domain_name(const std::string &domain_name);
  void do_set_domain_name(const char *domain_name, std::size_t length);

  ByteBuffer store_;
};

}

#endif //CHARA_DNS_DOMAIN_NAME_H
