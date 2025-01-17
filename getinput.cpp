#include "getinput.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int getColumns(const std::string &path, std::vector<int> &c1,
               std::vector<int> &c2) {
  std::ifstream input(path);
  std::string line;

  if (input.is_open()) {
    // Reading each line from the file
    while (std::getline(input, line)) {
      std::stringstream ss(line);
      int col1, col2;

      // Extracting the two columns from the line
      ss >> col1 >> col2;
      c1.push_back(col1);
      c2.push_back(col2);
    }
    input.close();

  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}

int getLines(const std::string &path, std::vector<std::vector<int>> &lines) {
  std::ifstream input(path);
  std::string line;

  if (input.is_open()) {
    // Reading each line from the file
    while (std::getline(input, line)) {
      std::stringstream ss(line);
      std::vector<int> current_line;
      int n;

      while (ss >> n) {
        current_line.push_back(n);
      }

      lines.push_back(current_line);
    }
    input.close();

  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}