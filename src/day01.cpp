#include "utils.h"
#include <assert.h>
#include <fstream>
#include <iostream>
#include <queue>

using namespace aoc::util;
namespace aoc::day01 {
void lineToNum(FixedQueue<int, 3> &x, const std::string &file_name) {
  std::ifstream read_file(file_name);
  assert(read_file.is_open());
  std::string line;
  int n = 0;
  while (std::getline(read_file, line)) {
    if (line.size()) {
      n += std::stoi(line);
    } else {
      x.push(n);
      n = 0;
    }
  }

  x.push(n);
  read_file.close();
}

void sol() {

  FixedQueue<int, 3> x;
  x.push(0);
  x.push(0);
  x.push(0);
  lineToNum(x, "../input/day01.txt");
  std::cout << "Top 3: " << std::endl;
  int k = 0;
  while (x.size()) {
    std::cout << x.top() << std::endl;
    k += x.top();
    x.pop();
  }
  std::cout << "Sum of Top 3: " << k << std::endl;

}
} // namespace aoc::day01
