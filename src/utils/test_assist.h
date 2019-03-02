//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_TEST_ASSIST_H
#define CHARA_TEST_ASSIST_H

#include <cstdlib>

namespace chara {

class TestAssist {
 public:
  template<typename Callable, typename ...Args>
  explicit TestAssist(bool enable, Callable callable, Args ...args) {
    if (enable) {
      callable(args...);
      exit(0);
    }
  }
};

}

#endif // CHARA_TEST_ASSIST_H
