#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> lines;
  std::string path = "D2_input.txt"; // File path
  getLines(path, lines);
  int sum = 0;

  for (int i = 0; i < lines.size(); i++) {
    bool is_safe = true;
    bool is_increasing = lines[i][0] < lines[i][1];

    for (int j = 1; j < lines[i].size(); j++) {
      int diff = std::abs(lines[i][j] - lines[i][j - 1]);
      if (diff < 1 || diff > 3) {
        is_safe = false;
        break;
      }
      if ((is_increasing && lines[i][j] < lines[i][j - 1]) ||
          (!is_increasing && lines[i][j] > lines[i][j - 1])) {
        is_safe = false;
        break;
      }
    }
    if (is_safe) {
      sum++;
    }
  }
  std::cout << sum << std::endl;

  return 0;
}
