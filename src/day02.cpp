#include "day02.h"
#include "utils.h"
#include <numeric>

namespace aoc::day02 {

void parse_file(std::vector<int> &p, bool pt) {
  std::vector<std::string> rx;
  read_file(rx, "../input/day02.txt");
  for (auto x : rx) {
    //
    int z = ((int)x[0]) + 1 - (int)'A';
    int y = ((int)x[2]) + 1 - (int)'X';
    int s = pt == 1 ? score_pt1(z, y) : score_pt2(z, y);

    p.push_back(s);
  }
}
int score_pt1(int x, int y) {
  switch (y - x) {
  case 1:
    return 6 + y;
  case -2:
    return 6 + y;
  case 0:
    return 3 + y;
  default:
    return y;
  }
}

int score_pt2(int x, int y) {
  switch (y) {
  case 1:
    return x - 1 != 0 ? x - 1 : 3;
  case 2:
    return 3 + x;
  default:
    return x + 1 == 4 ? 7 : x + 7;
  }
};
void sol(int pt) {
  std::vector<int> rx;
  parse_file(rx, pt);
  int result = std::accumulate(rx.begin(), rx.end(), 0);
  std::cout << result << std::endl;
}

} // namespace aoc::day02
