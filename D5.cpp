#include "getinput.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> rules;
  std::vector<std::vector<int>> updates;
  int sum = 0;
  int iterator = 0;
  getPrintingInstruction("D5_input.txt", rules, updates);
  bool well_ordered = true;
  for (const auto &update : updates) {
    well_ordered = true;
    iterator = 0;
    for (int page : update) {
      for (int i = 0; i < rules.size(); i++) {
        if (rules[i][0] == page) {
          for (int j = 0; j < iterator; j++) {
            if (rules[i][1] == update[j]) {
              well_ordered = false;
              break;
            }
          }
        }
      }

      iterator++;
    }
    if (well_ordered && !update.empty()) {
      int middle_index = update.size() / 2;
      sum += update[middle_index];
    }
  }

  /** std::cout << "Rules:" << std::endl;
  for (const auto &rule : rules) {
    std::cout << rule[0] << "|" << rule[1] << std::endl;
  }

  std::cout << "Updates:" << std::endl;
  for (const auto &update : updates) {
    for (int num : update) {
      std::cout << num << " ";
    }
  }
  std::cout << std::endl;**/
  std::cout << sum << std::endl;
  return 0;
}