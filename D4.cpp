#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int tangledXmas(std::vector<std::vector<std::string>> lines);
int CrossMas(std::vector<std::vector<std::string>> lines);

int main() {
  std::vector<std::vector<std::string>> lines;
  std::string path = "D4_input.txt"; // File path
  getStringLines(path, lines);

  CrossMas(lines);

  return 0;
}
int CrossMas(std::vector<std::vector<std::string>> lines) {
  std::vector<std::string> v = {"M", "A", "S"};
  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      if (lines[i][j] == v[0]) {
        if ((i - 2 >= 0) && (j + 2 < lines[0].size())) {
          if ((lines[i - 1][j + 1] == v[1]) && (lines[i][j + 2] == v[2])) {
            if ((lines[i - 2][j] == v[0]) && (lines[i - 2][j + 2] == v[2])) {
              sum += 1;
              std::cout << "first ";
              std::cout << i + 1 << "," << j + 1 << std::endl;
            }
          }
        };

        if ((i - 2 >= 0) && (j - 2 >= 0)) {
          if ((lines[i - 1][j - 1] == v[1]) && (lines[i - 2][j] == v[2])) {
            if ((lines[i][j - 2] == v[0]) && (lines[i - 2][j - 2] == v[2])) {
              sum += 1;
              std::cout << "sec ";
              std::cout << i + 1 << "," << j + 1 << std::endl;
            }
          }
        };
        if ((i + 2 < lines.size()) && (j - 2 >= 0)) {
          if ((lines[i + 1][j - 1] == v[1]) && (lines[i + 2][j - 2] == v[2])) {
            if ((lines[i + 2][j] == v[0]) && (lines[i][j - 2] == v[2])) {
              sum += 1;
              std::cout << "third ";
              std::cout << i + 1 << "," << j + 1 << std::endl;
            }
          }
        };
        if ((i + 2 < lines.size()) && (j + 2 < lines[0].size())) {
          if ((lines[i + 1][j + 1] == v[1]) && (lines[i + 2][j + 2] == v[2])) {
            if ((lines[i][j + 2] == v[0]) && (lines[i + 2][j] == v[2])) {
              sum += 1;
              std::cout << "fourth ";
              std::cout << i + 1 << "," << j + 1 << std::endl;
            }
          }
        };
      };
    }
  }
  std::cout << sum << std::endl;
  return 0;
}

int tangledXmas(std::vector<std::vector<std::string>> lines) {
  std::vector<std::string> v = {"X", "M", "A", "S"};
  int sum = 0;

  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      if (lines[i][j] == v[0]) {
        if (j + 3 < lines[0].size()) {
          if (lines[i][j + 1] == v[1]) {
            if (lines[i][j + 2] == v[2]) {
              if (lines[i][j + 3] == v[3]) {
                sum += 1;
              }
            }
          }
        }

        if (j - 3 >= 0) {
          if (lines[i][j - 1] == v[1]) {
            if (lines[i][j - 2] == v[2]) {
              if (lines[i][j - 3] == v[3]) {
                sum += 1;
              }
            }
          }
        }

        if (i + 3 < lines.size()) {
          if (lines[i + 1][j] == v[1]) {
            if (lines[i + 2][j] == v[2]) {
              if (lines[i + 3][j] == v[3]) {
                sum += 1;
              }
            }
          }
        }

        if (i - 3 >= 0) {
          if (lines[i - 1][j] == v[1]) {
            if (lines[i - 2][j] == v[2]) {
              if (lines[i - 3][j] == v[3]) {
                sum += 1;
              }
            }
          }
        }

        if ((i - 3 >= 0) && (j - 3 >= 0)) {
          if (lines[i - 1][j - 1] == v[1]) {
            if (lines[i - 2][j - 2] == v[2]) {
              if (lines[i - 3][j - 3] == v[3]) {
                sum += 1;
              }
            }
          }
        }
        if ((i - 3 >= 0) && (j + 3 < lines[0].size())) {
          if (lines[i - 1][j + 1] == v[1]) {
            if (lines[i - 2][j + 2] == v[2]) {
              if (lines[i - 3][j + 3] == v[3]) {
                sum += 1;
              }
            }
          }
        }
        if ((i + 3 < lines.size()) && (j - 3 >= 0)) {
          if (lines[i + 1][j - 1] == v[1]) {
            if (lines[i + 2][j - 2] == v[2]) {
              if (lines[i + 3][j - 3] == v[3]) {
                sum += 1;
              }
            }
          }
        }
        if ((i + 3 < lines.size()) && (j + 3 < lines[0].size())) {
          if (lines[i + 1][j + 1] == v[1]) {
            if (lines[i + 2][j + 2] == v[2]) {
              if (lines[i + 3][j + 3] == v[3]) {
                sum += 1;
              }
            }
          }
        };
      }
    }
  }
  return sum;
};