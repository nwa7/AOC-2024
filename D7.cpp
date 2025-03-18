#include "getinput.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
bool contains(const std::vector<T> &vec, const T &target) {
  return std::find(vec.begin(), vec.end(), target) != vec.end();
}

bool evaluateExpression(const std::vector<int> &nums, int target) {
  int N = nums.size();
  size_t size = static_cast<size_t>(std::pow(2, N - 1));
  std::vector<int> result;
  result[0] = nums[0];
  int nb = 1;
  for (size_t i = 1; i < nums.size(); ++i) {
    int fill_vec = 0;
    int next_num = nums[i];
    int add_result;
    int mul_result;
    for (i = 0; i < nb; i++) {
      add_result = result[i] + next_num;
      mul_result = result[i] * next_num;
    }
    nb = 2 ^ nb;
    if (add_result >= target) {
      nb -= 1;
    } else {
      result[fill_vec] = add_result;
    };
    if (mul_result >= target) {
      nb -= 1;
    } else {
      result[fill_vec] = mul_result;
    };
  };
  return contains(result, target);
};

int main() {
  std::vector<std::pair<int, std::vector<int>>> lines;
  std::string path = "D7_input.txt"; // File path
  getStringLines(path, lines);

  for (const auto &line : lines) {
    int target = line.first;

    bool result = evaluateExpression(line.second, target);
    std::cout << "Target " << target << " with numbers ";
    for (int num : line.second) {
      std::cout << num << " ";
    }
    std::cout << (result ? "can" : "cannot") << " be formed.\n";
  }

  return 0;
}
