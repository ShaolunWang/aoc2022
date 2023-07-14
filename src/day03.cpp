#include "utils.h"
#include <cctype>
#include <map>
#include <set>
namespace aoc::day03 {
int priority(char c) {
  int n = (int)c;
  return n >= 97 ? (int)std::toupper(c) - 64 : (int)std::tolower(c) - 70;
}
void init(std::map<char, int> &m) {
  for (char c : "abcdefghijklmnopqrstuvwxyz")
    m[c] = 0; // initialize
}

std::string remove_duplicates(std::string &subject) {
  std::string no_duplicates;

  for (std::string::const_iterator it = subject.begin(); it != subject.end();
       ++it) {

    if (no_duplicates.find(*it) == std::string::npos) // char not found
      no_duplicates += *it;
  }

  return no_duplicates;
}

int sol_pt1(std::string a, std::string b) {
  int p = 0;
  for (char c : a) {
    if (std::find(b.begin(), b.end(), c) != std::end(b))
      return priority(c);
  }
  return 0;
};
int sol_pt2(std::map<char, int> &m,

            std::string group[]) {
  int group_p = 0;
  for (auto &[_, v] : m)
    v = 0;
  for (int i = 0; i < 3; i++) {
    group[i] = remove_duplicates(group[i]);
    std::cout << group[i] << std::endl;
    for (char c : group[i]) {
      if (++m[c] == 3)
        return priority(c);
    }
  }
  return group_p;
}
void sol(int pt) {
  std::map<char, int> m;
  init(m);
  std::vector<std::string> file;
  aoc::util::read_file(file, "../input/day03.txt");
  int ans = 0;
  if (pt == 1) {
    for (std::string s : file) {
      std::string fst_sack = s.substr(0, s.length() / 2);
      std::string snd_sack = s.substr(s.length() / 2);
      ans += sol_pt1(fst_sack, snd_sack);
    }
  } else {
    for (int i = 0; i < file.size(); i += 3) {
      std::string group[3] = {file.at(i), file.at(i + 1), file.at(i + 2)};
      ans += sol_pt2(m, group);
    }
  }

  std::cout << ans << std::endl;
}
} // namespace aoc::day03
