#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> c1;           // first column
  std::vector<std::string> c2;           // second column
  std::ifstream input("D1C1_input.txt"); // Opening the file for reading
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

    std::cout << "Column 1:" << std::endl;
    for (const auto &i : c1)
      std::cout << i << std::endl;

    std::cout << "Column 2:" << std::endl;
    for (const auto &i : c2)
      std::cout << i << std::endl;

  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}
