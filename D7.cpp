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
  size_t size = static_cast<size_t>(std::pow(2, N - 1) + 1);
  std::vector<int> result(size, 0);
  result[0] = nums[0];
  int previous_nb = 0;
  int nb = 1;
  for (size_t i = 1; i < nums.size(); ++i) {
    int fill_incr = 0;
    int next_num = nums[i];
    int add_result;
    int mul_result;
    for (int j = previous_nb; j < nb; j++) {
      add_result = result[j] + next_num;
      mul_result = result[j] * next_num;

      result[nb + fill_incr] = add_result;
      fill_incr++;
      result[nb + fill_incr] = mul_result;
      fill_incr++;
    }
    previous_nb = nb;
    nb = std::pow(2, previous_nb - 1) + previous_nb;
  };
  for (int i = 0; i < std::pow(2, N - 1) + 1; i++) {
    std::cout << result[i] << std::endl;
  }
  std::cout << contains(result, target) << std::endl;
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
    std::cout << " " << std::endl;
    std::cout << (result ? "can" : "cannot") << " be formed.\n";
  }

  return 0;
}
