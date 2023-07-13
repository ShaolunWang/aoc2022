#ifndef _AOC_UTILS_
#define _AOC_UTILS_
#include <assert.h>
#include <deque>
#include <fstream>
#include <iostream>
#include <queue>

#include "llvm/Support/Casting.h"

namespace aoc::util {

// This template provides a template for fixed length priority queue

template <typename T, int MaxLen,
          typename Container =
              std::priority_queue<T, std::vector<T>, std::greater<T>>>
class FixedQueue : public Container {
public:
  void push(const T &value) {
    if (this->size() == MaxLen)
      std::priority_queue<T, std::vector<T>, std::greater<T>>::pop();
    std::priority_queue<T, std::vector<T>, std::greater<T>>::push(value);
  }
};


// templates for reading a file
template <template <typename, typename = std::allocator<std::string>>
          class Container>
void read_file(Container<std::string> &x, const std::string &file_name) {
  std::ifstream rf(file_name);
  assert(rf.is_open());
  std::string line;
  while (std::getline(rf, line)) {
    x.push_back(line);
  }
  rf.close();
}

template <typename T,
          template <typename, typename = std::allocator<T>> class Container,
          typename = typename std::enable_if<
              std::is_same<T, std::string>::value>::type>
void read_file(Container<T> &x, const std::string &file_name) {
  std::ifstream rf(file_name);
  assert(rf.is_open());
  std::string line;
  while (std::getline(rf, line)) {
    x.push_back(llvm::dyn_cast<T>(line));
  }
  rf.close();
}

} // namespace aoc::util
#endif
