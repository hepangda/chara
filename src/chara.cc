//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "core/karma.h"
#include "utils/concurrency_proxy.h"
#include "protocol/dnsds.h"
#include "protocol/dns_domain_name.h"
#include "utils/test_assist.h"
#include <iostream>

//constexpr bool kTestFlag = true;
constexpr bool kTestFlag = false;

int main(int argc, const char *argv[]) {
  using namespace chara;

  TestAssist{kTestFlag, [] {
    DnsDomainName da{"www.baidu.com"};
    DnsDomainName db{"WwW.BaiDU.cOm"};
    std::cout << da.domain_name_string() << std::endl;
    std::cout << (da == db ? "true" : "false") << std::endl;
  }};

  return ConcurrencyProxy{[] {
    Karma().Run();
  }}.Wait();
}