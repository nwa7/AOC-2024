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
  std::regex expr("mul\\(([\\d]*),([\\d]*)\\)");
  auto rend = std::sregex_iterator();

  // std::regex_search(input, matches, expr);
  std::sregex_iterator matches(lines.begin(), lines.end(), expr);
  while (matches != rend) {
    std::smatch a = *matches;
    // std::cout << a[1] << a[2] << std::endl;

    sum += stoi(a[1]) * stoi(a[2]);
    matches++;
    std::cout << std::endl;
  }
  std::cout << sum << std::endl;
  return 0;
}