#include "day01.h"

int main() {
  int day;
  std::cout << "Input day number for solution" << std::endl;
  std::cin >> day;
  while (true) {
    switch (day) {
    case 1:
      aoc::day01::sol();
      return 0;
    default:
      std::cout << "Not valid input, please try again" << std::endl;
      break;
    }
  }
}
