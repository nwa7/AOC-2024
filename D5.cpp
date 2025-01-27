#include "getinput.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> rules;
  std::vector<std::vector<int>> updates;

  getPrintingInstruction("D5_input.txt", rules, updates);
  /***
std::cout << "Rules:" << std::endl;
for (const auto &rule : rules) {
  std::cout << rule[0] << "|" << rule[1] << std::endl;
}

std::cout << "Updates:" << std::endl;
for (const auto &update : updates) {
  for (int num : update) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
} ***/

  return 0;
}
