//  Copyright (c) hepangda
//
//  This source code is licensed under the MIT license found in the
//  LICENSE file in the root directory of this source tree.

#ifndef CHARA_NET_ASSIST_H
#define CHARA_NET_ASSIST_H

#include <asio.hpp>

namespace chara {

namespace net = asio;
namespace neti = asio::ip;

template<typename T>
inline void SetReusePort(T &socket) {
  int buf = 1;
  setsockopt(socket.native_handle(), SOL_SOCKET, SO_REUSEPORT, &buf, sizeof(buf));
}

template<typename T>
inline void OpenWithReusePort(T &socket, typename T::protocol_type protocol, typename T::endpoint_type endpoint) {
  socket.open(protocol);
  SetReusePort(socket);
  socket.bind(endpoint);
}

template<typename T>
inline void ListenWithReusePort(T &socket, typename T::protocol_type protocol,
                                typename T::endpoint_type endpoint, int backlog = -1) {
  OpenWithReusePort(socket, protocol, endpoint);
  if (backlog == -1) {
    socket.listen();
  } else {
    socket.listen(backlog);
  }
}



}

#endif // CHARA_NET_ASSIST_H
