//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "core/karma.h"
#include "utils/concurrency_proxy.h"
#include "protocol/dns_origin.h"
#include "protocol/dns_domain_name.h"
#include "utils/test_assist.h"
#include <iostream>

int main(int argc, const char *argv[]) {
  using namespace chara;

  TestAssist ta { false, [] {
    DnsDomainName da { "www.baidu.com" };
    std::cout << da.domain_name_string() << std::endl;
  }};

  ConcurrencyProxy proxy{[] { Karma().Run(); }};
  return proxy.Wait();
}