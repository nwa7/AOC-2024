#include "getinput.hpp"
#include "sortalgo.hpp"
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
  std::string lines;
  std::string path = "D3_input.txt"; // File path
  getString(path, lines);

  int sum = 0;
  bool enabled = true;

  std::regex expr("(do\\(\\)|don't\\(\\)|mul\\(([\\d]*),([\\d]*)\\))");
  auto rend = std::sregex_iterator();

  // std::regex_search(input, matches, expr);
  std::sregex_iterator matches(lines.begin(), lines.end(), expr);
  while (matches != rend) {
    std::smatch match = *matches;
    // std::cout << a[1] << a[2] << std::endl;
    if (match[0] == "do()") {
      enabled = true;
    } else if (match[0] == "don't()") {
      enabled = false;
    } else if (enabled && match.size() > 2) {
      int num1 = std::stoi(match[2]);
      int num2 = std::stoi(match[3]);
      sum += num1 * num2;
    }
    matches++;
  }
  std::cout << sum << std::endl;
  return 0;
}