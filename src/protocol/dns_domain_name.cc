//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "dns_domain_name.h"

#include <iostream>
#include <cstring>

namespace chara {

namespace detail {

size_t CalcLabelBufferSize(const std::string &str) {
  return str.length() + ((str.back() == '.') ? 1 : 2);
}

size_t CalcLabelBufferSize(const char *str, size_t length) {
  return length + ((str[length - 1] == '.') ? 1 : 2);
}
}

DnsDomainName::DnsDomainName(const std::string &domain_name) :
    store_(detail::CalcLabelBufferSize(domain_name)) {
  do_set_domain_name(domain_name);
}

DnsDomainName::DnsDomainName(const char *domain_name) :
    DnsDomainName(domain_name, strlen(domain_name)) {}

DnsDomainName::DnsDomainName(const char *domain_name, std::size_t length) :
    store_(detail::CalcLabelBufferSize(domain_name, length)) {
  do_set_domain_name(domain_name, length);
}

void DnsDomainName::set_domain_name(const std::string &domain_name) {
  store_.Reset(detail::CalcLabelBufferSize(domain_name));
  do_set_domain_name(domain_name);
}

void DnsDomainName::do_set_domain_name(const std::string &domain_name) {
  do_set_domain_name(domain_name.data(), domain_name.size());
}

void DnsDomainName::set_domain_name(const char *domain_name) {
  set_domain_name(domain_name, strlen(domain_name));
}

void DnsDomainName::set_domain_name(const char *domain_name, std::size_t length) {
  store_.Reset(detail::CalcLabelBufferSize(domain_name, length));
  do_set_domain_name(domain_name, length);
}

void DnsDomainName::do_set_domain_name(const char *domain_name, std::size_t length) {
  auto pstart = store_.pointer();
  auto last = 0;
  Byte c = 0;

  for (auto i = 1, j = 0; i < store_.size() && j <= length; i++, j++) {
    if (domain_name[j] == '.' || domain_name[j] == '\0') {
      pstart[last] = c;
      c = 0;
      last = i;
    } else {
      pstart[i] = static_cast<Byte>(domain_name[j]);
      c++;
    }
  }
  *(store_.pointer<Byte>() + store_.size() - 1) = 0;
  store_.set_length(store_.size());
}

bool DnsDomainName::operator==(const DnsDomainName &rhs) {
  auto lhsbuf = store_.const_pointer(), rhsbuf = rhs.store_.const_pointer();
  for (int i = 0; i < store_.size(); i++) {
    if (lhsbuf[i] != rhsbuf[i]) {
      return false;
    } else if (lhsbuf[i] == 0) {
      return true;
    } else {
      auto limit = lhsbuf[i];
      for (auto j = 0; j < limit; j++) {
        i++;
        if (toupper(lhsbuf[i]) != toupper(rhsbuf[i])) {
          return false;
        }
      }
    }
  }
  // NOTE: Exception condition
  return false;
}

DnsDomainName &&DnsDomainName::Copy() const {
  return std::move(DnsDomainName(domain_name(), store_.size()));
}

std::unique_ptr<DnsDomainName> DnsDomainName::CopyUniquePtr() const {
  return std::make_unique<DnsDomainName>(domain_name(), store_.size());
}

DnsDomainName::DnsDomainName(DnsDomainName &&rhs) noexcept : store_(1) {
  store_ = std::move(rhs.store_);
}

std::unique_ptr<DnsDomainName> ConstructDnsDomainName(void *&stream) {
  return ConstructDnsDomainName(stream, strlen(static_cast<char *>(stream)) + 1);
}

std::unique_ptr<DnsDomainName> ConstructDnsDomainName(void *&stream, size_t length) {
  auto ret = std::make_unique<DnsDomainName>(length);
  ret->store_.Put(stream, length);
  ret->store_.set_length(length);
  stream = static_cast<char *>(stream) + length;
  return ret;
}


}