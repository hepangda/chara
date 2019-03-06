//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "core/karma.h"
#include "utils/concurrency_proxy.h"
#include "protocol/dnsds.h"
#include "protocol/dns_domain_name.h"
#include "utils/test_assist.h"
#include "protocol/dns_packet.h"
#include <iostream>

constexpr bool kTestFlag = true;
//constexpr bool kTestFlag = false;

int main(int argc, const char *argv[]) {
  using namespace chara;

  TestAssist{kTestFlag, [] {
    Byte c[] = {
        0xc0, 0xca, 0x81, 0x82, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x68, 0x75, 0x61, 0x74, 0x75,
        0x6f, 0x73, 0x70, 0x65, 0x65, 0x64, 0x06, 0x77, 0x65, 0x69, 0x79, 0x75, 0x6e, 0x03, 0x63, 0x6f, 0x6d, 0x00,
        0x00, 0x1c, 0x00, 0x01
    };

    auto pkt = ConstructDnsPacket(c);
    std::cout << pkt.header_.questions() << std::endl;
    std::cout << pkt.questions_[0].domain_name_string() << std::endl;
  }};

  return ConcurrencyProxy{[] {
    Karma().Run();
  }}.Wait();
}