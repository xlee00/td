//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2018
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/DialogId.h"
#include "td/telegram/files/FileId.h"
#include "td/telegram/MessageEntity.h"
#include "td/telegram/Photo.h"
#include "td/telegram/UserId.h"

#include "td/utils/common.h"
#include "td/utils/StringBuilder.h"

#include "td/telegram/td_api.h"
#include "td/telegram/telegram_api.h"

namespace td {

class Td;

class Game {
  int64 id_ = 0;
  int64 access_hash_ = 0;
  UserId bot_user_id_;
  string short_name_;
  string title_;
  string description_;
  Photo photo_;
  FileId animation_file_id_;

  string text_;
  vector<MessageEntity> entities_;

  friend bool operator==(const Game &lhs, const Game &rhs);
  friend bool operator!=(const Game &lhs, const Game &rhs);

  friend StringBuilder &operator<<(StringBuilder &string_builder, const Game &game);

 public:
  Game() = default;

  Game(Td *td, tl_object_ptr<telegram_api::game> &&game, DialogId owner_dialog_id);

  Game(Td *td, string title, string description, tl_object_ptr<telegram_api::Photo> &&photo,
       tl_object_ptr<telegram_api::Document> &&document, DialogId owner_dialog_id);

  Game(UserId bot_user_id, string short_name);

  bool empty() const;

  void set_bot_user_id(UserId bot_user_id);

  UserId get_bot_user_id() const;

  void set_message_text(string text, vector<MessageEntity> &&entities);

  tl_object_ptr<td_api::game> get_game_object(const Td *td) const;

  tl_object_ptr<telegram_api::inputMediaGame> get_input_media_game(const Td *td) const;

  template <class StorerT>
  void store(StorerT &storer) const;

  template <class ParserT>
  void parse(ParserT &parser);
};

bool operator==(const Game &lhs, const Game &rhs);
bool operator!=(const Game &lhs, const Game &rhs);

StringBuilder &operator<<(StringBuilder &string_builder, const Game &game);

}  // namespace td
