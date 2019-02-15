//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_CONCURRENCY_PROXY_H
#define CHARA_CONCURRENCY_PROXY_H

#include <thread>
#include <vector>

namespace chara {

class ConcurrencyProxy {
 public:
  template<typename Callable, typename ...Args>
  explicit ConcurrencyProxy(Callable callable, Args ...args) {
    auto instances = 2u;
//    TODO: replace it with below
//    auto instances = std::thread::hardware_concurrency();
    threads_.reserve(instances);

    for (auto i = 0; i < instances; i++) {
      threads_.emplace_back(std::forward<Callable>(callable), std::forward<Args>(args)...);
    }
  }

  int Wait() {
    for (auto &i: threads_) {
      i.join();
    }

    return 0;
  }

 private:
  std::vector<std::thread> threads_;
};

}

#endif //CHARA_CONCURRENCY_PROXY_H