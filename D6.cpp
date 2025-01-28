#include "getinput.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int moveGuard(std::vector<std::vector<std::string>> &lines,
              std::vector<int> position);

int countString(std::vector<std::vector<std::string>> lines, std::string s);

int main() {
  std::vector<std::vector<std::string>> lines;
  std::string path = "D6_input.txt"; // File path
  getStringLines(path, lines);

  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      if ((lines[i][j] != "#") && (lines[i][j] != "X") &&
          (lines[i][j] != ".")) { // found guard! :)
        std::vector<int> position;
        position.push_back(i);
        position.push_back(j);
        moveGuard(lines, position);
        std::cout << countString(lines, "X") << std::endl;
        return 0;
      }
    }
  }
  return 0;
}

int moveGuard(std::vector<std::vector<std::string>> &lines,
              std::vector<int> position) {

  std::vector<std::string> vec = {"^", ">", "v", "<"};

  std::vector<std::vector<int>> position_update = {
      {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  auto index =
      std::find(vec.begin(), vec.end(), lines[position[0]][position[1]]);
  auto ind = index - vec.begin();

  std::vector<int> new_position;
  new_position.push_back(position[0] + position_update[ind][0]);
  new_position.push_back(position[1] + position_update[ind][1]);
  if (new_position[0] < 0 || new_position[0] >= lines.size() ||
      new_position[1] < 0 || new_position[1] >= lines[0].size()) {

    lines[position[0]][position[1]] = "X";
    return 0;
  } else if (lines[new_position[0]][new_position[1]] != "#") {
    lines[position[0]][position[1]] = "X";
    lines[new_position[0]][new_position[1]] = vec[ind];
    position = new_position;
    moveGuard(lines, position);
  } else {
    lines[position[0]][position[1]] = vec[(ind + 1) % 4];
    moveGuard(lines, position);
  }
  return 0;
}

int countString(std::vector<std::vector<std::string>> lines, std::string s) {
  int sum = 0;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[0].size(); j++) {
      if (lines[i][j] == s) {
        sum += 1;
      }
    }
  }
  return sum;
}