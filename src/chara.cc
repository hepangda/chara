//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

//#include "core/karma.h"
//#include "utils/concurrency_proxy.h"

#include "protocol/dns.h"
#include <iostream>
#include <netinet/in.h>
using namespace chara;

int main(int argc, const char *argv[]) {
  Word a;
  a = 0x0c | 0xc000;
  printf("%x\n", a);
  std::cout << sizeof(chara::DnsLabelPointer) << std::endl;
//  chara::ConcurrencyProxy proxy { [] { chara::Karma().Run(); }};
//  return proxy.Wait();
}