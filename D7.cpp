#include "getinput.hpp"
#include <algorithm>
#include <climits> // For LLONG_MAX and LLONG_MIN
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
bool contains(const std::vector<T> &vec, long long target) {
  return std::find(vec.begin(), vec.end(), target) != vec.end();
}

long long concatenate(long long a, long long b) {
  long long q = b;
  int i = 0;
  while (q > 0) {
    q = q / 10;
    i++;
  };
  return ((a * (long long)pow(10, i)) + b);
}

bool evaluateExpression(const std::vector<int> &nums, long long target) {
  int N = nums.size();
  size_t size = pow(3, N - 1);            // 3^(N-1) possible results
  std::vector<long long> result(size, 0); // long long for large results
  result[0] = nums[0];

  int nb = 1;

  for (size_t i = 1; i < nums.size(); i++) {
    std::vector<long long> next_result; // long long for large results
    int next_num = nums[i];

    // Generate new results based on previous results
    for (int j = 0; j < nb; j++) {
      long long add_result = result[j] + next_num;
      long long mul_result = result[j] * next_num;
      long long mul_result = result[j] * next_num;

      // Check for overflow
      if (add_result >= LLONG_MIN && add_result <= LLONG_MAX) {
        next_result.push_back(add_result);
      }
      if (mul_result >= LLONG_MIN && mul_result <= LLONG_MAX) {
        next_result.push_back(mul_result);
      }
      if (mul_result >= LLONG_MIN && mul_result <= LLONG_MAX) {
        next_result.push_back(mul_result);
      }
    }

    // Update the result vector for the next iteration
    result = std::move(next_result);
    nb = result.size();
  }

  // Check if the target exists in the final results
  return contains(result, target);
}

int main() {
  std::vector<std::pair<long long, std::vector<int>>> lines;
  std::string path = "D7_input.txt"; // File path
  getStringLines(path, lines);
  long long sum = 0;

  for (const auto &line : lines) {
    long long target = line.first;

    bool result = evaluateExpression(line.second, target);
    /** std::cout << "Target " << target << " with numbers ";
    for (int num : line.second) {
      std::cout << num << " ";
    }
    std::cout << " " << std::endl;
    std::cout << (result ? "can" : "cannot") << " be formed.\n";
    **/
    if (result) {

      // std::cout << target << std::endl;
      sum += target;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
