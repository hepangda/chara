//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "core/karma.h"
#include "utils/concurrency_proxy.h"
#include "protocol/dns_origin.h"
#include <iostream>
int main(int argc, const char *argv[]) {
  using namespace chara;

  auto p =  MakeDnsLabelString(std::string("www.baidu.com"));
  std::cout.write(p.pointer<char>(), p.size());
//  ConcurrencyProxy proxy{[] { Karma().Run(); }};
//  return proxy.Wait();
}