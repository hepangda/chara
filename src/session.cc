//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.#include "session.h"

#include "session.h"

namespace chara {

Session::Session(asio::ip::tcp::socket socket) : socket_(std::move(socket)) {
}

}