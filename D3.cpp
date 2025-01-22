#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::vector<int>> lines;
  std::string path = "D3_input.txt"; // File path
  getLines(path, lines);

  int sum = 0;
  // regex mul\([\d] *, [\d] *\) //

  std::cout << sum << std::endl;
  return 0;
}