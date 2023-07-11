#ifndef _AOC_UTILS_
#define _AOC_UTILS_
#include <assert.h>
#include <deque>
#include <fstream>
#include <iostream>
#include <queue>

namespace aoc::util {

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

} // namespace aoc::util
#endif