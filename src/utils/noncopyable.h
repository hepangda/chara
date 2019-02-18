//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_NONCOPYABLE_H
#define CHARA_NONCOPYABLE_H

namespace chara {

class Noncopyable {
 public:
  // delete copy constructor and copy assign operator to avoid copy
  Noncopyable(const Noncopyable &) = delete;
  Noncopyable &operator=(const Noncopyable &) = delete;
 protected:
  // declared `protected` to avoid get instance of `Noncopyable` itself
  constexpr Noncopyable() = default;
  ~Noncopyable() = default;
};

}

#endif //CHARA_NONCOPYABLE_H
