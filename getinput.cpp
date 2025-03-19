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

int getStringLines(const std::string &path,
                   std::vector<std::vector<std::string>> &lines) {
  std::ifstream input(path);

  if (input.is_open()) {
    std::string line;
    // Reading each line from the file
    while (std::getline(input, line)) {
      std::vector<std::string> current_line;

      for (char letter : line) {
        current_line.push_back(std::string(1, letter));
      }

      lines.push_back(current_line);
    }
    input.close();

  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}

int getStringLines(const std::string &path,
                   std::vector<std::pair<int, std::vector<int>>> &lines) {
  std::ifstream input(path);

  if (!input.is_open()) {
    std::cerr << "Unable to open file: " << path << std::endl;
    return -1; // File could not be opened
  }

  std::string line;
  while (std::getline(input, line)) {
    std::istringstream stream(line);
    std::string target_str;

    // Get the target nb before ':'
    std::getline(stream, target_str, ':');

    int target;
    try {
      // Try to convert target_str int
      target = std::stoi(target_str);
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid target value (not a number): " << target_str
                << " in line: " << line << std::endl;
      continue;
    } catch (const std::out_of_range &e) {
      std::cerr << "Target value out of range: " << target_str
                << " in line: " << line << std::endl;
      continue;
    }

    std::vector<int> numbers;
    int num;

    // Read remaining numbers after ':'
    while (stream >> num) {
      numbers.push_back(num);
    }
    lines.push_back({target, numbers});
  }

  input.close();
  return 0; // Success
}

int getString(const std::string &path, std::string &lines) {
  std::ifstream input(path);
  if (input.is_open()) {

    std::stringstream buffer;
    buffer << input.rdbuf();
    lines = buffer.str();
    input.close();
  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}

// D5

int getPrintingInstruction(const std::string &path,
                           std::vector<std::vector<int>> &rules,
                           std::vector<std::vector<int>> &updates) {
  std::ifstream input(path);
  std::string line;

  if (input.is_open()) {
    // Reading each line from the file
    while (std::getline(input, line)) {
      std::stringstream ss(line);
      std::string first, second;

      if (std::getline(ss, first, '|') && std::getline(ss, second)) {
        rules.push_back({std::stoi(first), std::stoi(second)});
      } else {
        std::vector<int> current_line;
        std::stringstream ss_update(line);
        std::string num_str;

        while (std::getline(ss_update, num_str, ',')) {
          current_line.push_back(std::stoi(num_str));
        }

        updates.push_back(current_line);
      }
    }
    input.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }

  return 0;
}