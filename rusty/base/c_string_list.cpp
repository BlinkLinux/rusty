// Copyright (c) 2020 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// in the LICENSE file.

#include "rusty/base/c_string_list.h"

#include <cassert>
#include <cstring>

namespace rusty {

CStringList::CStringList() {
  this->vector_.push_back(nullptr);
}

CStringList::~CStringList() {
  for (auto item: this->vector_) {
    if (item != nullptr) {
      delete[] item;
    }
  }
}

CStringList::CStringList(const char* str) {
  this->do_push_back(str, strlen(str));
  this->vector_.push_back(nullptr);
}

CStringList::CStringList(const std::string& str) : CStringList(str.data()) {
}

CStringList::CStringList(const std::vector<std::string>& list) {
  this->do_extend(list);
  this->vector_.push_back(nullptr);
}

CStringList::CStringList(int argc, char** argv) {
  this->vector_.push_back(nullptr);
  for (int i = 0; i < argc; ++i) {
    this->PushBack(argv[i]);
  }
}

void CStringList::Extend(char** const list) {
  assert(!this->vector_.empty());
  this->vector_.pop_back();
  this->do_extend(list);
  this->vector_.push_back(nullptr);
}

void CStringList::Extend(const std::vector<std::string>& list) {
  assert(!this->vector_.empty());
  this->vector_.pop_back();
  this->do_extend(list);
  this->vector_.push_back(nullptr);
}

void CStringList::PushBack(const char* str) {
  assert(!this->vector_.empty());
  this->vector_.pop_back();
  this->do_push_back(str, strlen(str));
  this->vector_.push_back(nullptr);
}

void CStringList::PushBack(const std::string& str) {
  this->PushBack(str.data());
}

void CStringList::PushFront(const char* str) {
  assert(!this->vector_.empty());
  const auto old_vector = this->vector_;
  this->vector_.clear();
  this->do_push_back(str, strlen(str));
  for (const auto& key: old_vector) {
    this->vector_.push_back(key);
  }
}

void CStringList::PushFront(const std::string& str) {
  this->PushFront(str.data());
}

void CStringList::InsertAt(int pos, const char* str) {
  assert(!this->vector_.empty());
  const auto old_vector = this->vector_;
  this->vector_.clear();
  int current_pos = 0;
  for (const auto& key: old_vector) {
    if (current_pos == pos) {
      this->do_push_back(str, strlen(str));
    }
    this->vector_.push_back(key);
    current_pos += 1;
  }
}

void CStringList::do_extend(char** const list) {
  for (char** str = list; *str != nullptr; str++) {
    this->do_push_back(*str, ::strlen(*str));
  }
}

void CStringList::do_extend(const std::vector<std::string>& list) {
  for (const std::string& str: list) {
    this->do_push_back(str.data(), str.size());
  }
}

void CStringList::do_push_back(const char* str, size_t len) {
  char* c_str = new char[len + 1];
  ::strncpy(c_str, str, len);
  c_str[len] = '\0';
  this->vector_.push_back(c_str);
}

}  // namespace rusty
