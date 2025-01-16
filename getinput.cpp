#include "getinput.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int getColumns(const std::string &path, std::vector<std::string> &c1,
               std::vector<std::string> &c2) {
  std::ifstream input(path);
  std::string line;

  if (input.is_open()) {
    // Reading each line from the file
    while (std::getline(input, line)) {
      std::stringstream ss(line);
      std::string col1, col2;

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