#include "getinput.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> c1;
  std::vector<std::string> c2;
  std::string path = "D1C1_input.txt"; // File path
  getColumns(path, c1, c2);

  // Print column 1
  std::cout << "Column 1:" << std::endl;
  for (const auto &i : c1) {
    std::cout << i << std::endl;
  }

  // Print column 2
  std::cout << "Column 2:" << std::endl;
  for (const auto &i : c2) {
    std::cout << i << std::endl;
  }

  return 0;
}
