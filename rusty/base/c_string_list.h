// Copyright (c) 2021 Xu Shaohua <shaohua@biofan.org>. All rights reserved.
// Use of this source is governed by GNU Lesser General Public License
// in the LICENSE file.

#ifndef RUSTY_RUSTY_BASE_C_STRING_LIST_H_
#define RUSTY_RUSTY_BASE_C_STRING_LIST_H_

#include <string>
#include <vector>

namespace rusty {

// CStringList class represents char** used in C.
class CStringList {
 public:
  CStringList();
  ~CStringList();
  explicit CStringList(const std::string& str);
  explicit CStringList(const char* str);
  explicit CStringList(const std::vector<std::string>& list);
  explicit CStringList(int argc, char* argv[]);

  // NULL terminated string list.
  void Extend(char** const list);

  void Extend(const std::vector<std::string>& list);

  void PushBack(const char* str);
  void PushBack(const std::string& str);

  void PushFront(const char* str);
  void PushFront(const std::string& str);

  void InsertAt(int pos, const char* str);

  char* const* data() const {
    return this->vector_.data();
  }

  char** data() {
    return this->vector_.data();
  }

  size_t size() const {
    return this->vector_.size() - 1;
  }

  [[nodiscard]] const std::vector<char*>& vector() const { return vector_; }

 private:
  void do_extend(char** const list);
  void do_extend(const std::vector<std::string>& list);
  void do_push_back(const char* str, size_t len);

  std::vector<char*> vector_;
};

}  // namespace rusty

#endif  // RUSTY_RUSTY_BASE_C_STRING_LIST_H_
