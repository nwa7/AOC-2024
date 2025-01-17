#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

bool isSafe(std::vector<int> line, bool dampener_unused, bool is_increasing);

int main() {
  std::vector<std::vector<int>> lines;
  std::string path = "D2_input.txt"; // File path
  getLines(path, lines);
  int sum = 0;

  for (int i = 0; i < lines.size(); i++) {
    bool dampener_unused = true;
    bool is_increasing = lines[i][0] < lines[i][1];

    if (isSafe(lines[i], dampener_unused, is_increasing)) {
      sum++;
    }
  }
  std::cout << sum << std::endl;

  return 0;
}

bool isSafe(std::vector<int> line, bool dampener_unused, bool is_increasing) {
  bool is_safe = true;

  for (int j = 1; j < line.size(); j++) {
    int diff = std::abs(line[j] - line[j - 1]);
    if (diff < 1 || diff > 3) {
      is_safe = false;
      break;
    }
    if ((is_increasing && line[j] < line[j - 1]) ||
        (!is_increasing && line[j] > line[j - 1])) {
      is_safe = false;
      break;
    }
  }
  return (is_safe);
}