#include "getinput.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int wellOrdered(std::vector<std::vector<int>> &rules,
                std::vector<std::vector<int>> &updates);

std::vector<std::vector<int>>
retrieveOrders(std::vector<std::vector<int>> &rules, std::vector<int> &update);

std::vector<std::vector<int>>
removeOrders(std::vector<std::vector<int>> selected_rules, int nb);

int reorderUpdates(std::vector<std::vector<int>> &rules,
                   std::vector<int> &update);

int main() {
  std::vector<std::vector<int>> rules;
  std::vector<std::vector<int>> updates;
  getPrintingInstruction("D5_input.txt", rules, updates);
  int iterator = 0;
  int sum = 0;
  bool reordered = false;
  for (const auto &update : updates) {
    reordered = false;
    iterator = 0;
    for (int page : update) {
      for (int i = 0; i < rules.size(); i++) {
        if (rules[i][0] == page) {
          for (int j = 0; j < iterator; j++) {
            if (rules[i][1] == update[j]) {
              reordered = true;

              /** std::vector<std::vector<int>> selected_rules =
                  retrieveOrders(rules, update);
              reorderUpdates(selected_rules, update);
              goto NextUpdate; **/
            }
          }
        }
      }

      iterator++;
    }
  }
  if (reordered) {
  NextUpdate:
    std::cout << "bof" << std::endl;
  }
  return 0;
}
int reorderUpdates(std::vector<std::vector<int>> &rules,
                   std::vector<int> &update){

};

std::vector<std::vector<int>>
retrieveOrders(std::vector<std::vector<int>> &rules, std::vector<int> &update) {
  std::vector<std::vector<int>> selected_rules;

  for (int j = 0; j < update.size(); j++) {
    for (int i = 0; i < rules.size(); i++) {
      if (rules[i][0] == update[j]) {
        auto it = std::find(update.begin(), update.end(), rules[i][1]);
        if (it != update.end()) {
          selected_rules.push_back(rules[i]);
        }
      }
    }
  }
  return selected_rules;
}

std::vector<std::vector<int>>
removeOrders(std::vector<std::vector<int>> selected_rules, int nb) {
  std::vector<std::vector<int>> cleaned_rules;
  for (int i = 0; i < selected_rules.size(); i++) {
    if (selected_rules[i][0] != nb) {
      cleaned_rules.push_back(selected_rules[i]);
    }
  }
  return cleaned_rules;
}

int wellOrdered(std::vector<std::vector<int>> &rules,
                std::vector<std::vector<int>> &updates) {
  int iterator = 0;
  int sum = 0;
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
  return sum;
}