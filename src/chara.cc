//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#include "karma.h"
#include "concurrency_proxy.h"

int main(int argc, const char *argv[]) {
  chara::ConcurrencyProxy proxy { [] { chara::Karma().Run(); }};
  return proxy.Wait();
}