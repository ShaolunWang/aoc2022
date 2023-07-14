#include "day01.h"
#include "day02.h"
#include "day03.h"

int main() {
  int day;
  int pt;
  std::cout << "Input day number for solution" << std::endl;
  std::cin >> day;
  std::cout << "Which part?" << std::endl;
  std::cin >> pt;
  while (true) {
    switch (day) {
    case 1:
      aoc::day01::sol();
      return 0;
    case 2:
      aoc::day02::sol(pt);
      return 0;
    case 3:
      aoc::day03::sol(pt);
      return 0;
    default:
      std::cout << "Not valid input, please try again" << std::endl;
      break;
    }
  }
}
