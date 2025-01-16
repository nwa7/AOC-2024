#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> c1;
  std::vector<int> c2;
  std::string path = "D1C1_input.txt"; // File path
  getColumns(path, c1, c2);
  int sum = 0;

  quickSort(c1, 0, c1.size() - 1);
  quickSort(c2, 0, c2.size() - 1);
  // std::sort(c1.begin(), c1.end());
  // std::sort(c2.begin(), c2.end());

  for (int i = 0; i < c1.size(); i++) {
    sum += abs(c1[i] - c2[i]);
  }
  std::cout << sum << std::endl;
  return 0;
}
