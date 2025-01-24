#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

bool isSafe(std::vector<int> line, bool dampener_unused, bool is_increasing);

int main() {
  std::vector<std::vector<std::string>> lines;
  std::string path = "D4_input.txt"; // File path
  getStringLines(path, lines);
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
  std::cout << sum << std::endl;

  return 0;
}
