//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2018
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "td/mtproto/IStreamTransport.h"

#include "td/mtproto/HttpTransport.h"
#include "td/mtproto/TcpTransport.h"

#include "td/utils/logging.h"

namespace td {
namespace mtproto {
std::unique_ptr<IStreamTransport> create_transport(TransportType type) {
  switch (type) {
    case TransportType::ObfuscatedTcp:
      return std::make_unique<tcp::ObfuscatedTransport>();
    case TransportType::Tcp:
      return std::make_unique<tcp::OldTransport>();
    case TransportType::Http:
      return std::make_unique<http::Transport>();
  }
  UNREACHABLE();
}
}  // namespace mtproto
}  // namespace td