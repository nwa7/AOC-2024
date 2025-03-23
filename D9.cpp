#include "getinput.hpp"
#include "sortalgo.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int get_blocks(std::vector<int> &lines, std::vector<int> &blocks);
int compact_blocks(std::vector<int> &blocks);

int main() {
  std::vector<int> lines;
  std::vector<int> blocks;
  std::string path = "D9_input.txt"; // File path
  long long sum = 0;
  getLines(path, lines);
  get_blocks(lines, blocks);
  compact_blocks(blocks);

  for (int i = 0; i < blocks.size(); i++) {
    if (blocks[i] == -1) {
      std::cout << "sum is " << sum << std::endl;
      return 0;
    }
    std::cout << "sum += " << blocks[i] << " * " << i;
    sum += blocks[i] * i;
  }

  for (int l = 0; l < blocks.size(); l++) {
    if (blocks[l] == -1) {
      std::cout << ".";
    } else {
      std::cout << blocks[l];
    }
  }
  std::cout << " " << std::endl;

  return 0;
}

int get_blocks(std::vector<int> &lines, std::vector<int> &blocks) {
  int size = lines.size();

  for (int i = 0; i < size; i += 2) {
    for (int j = 0; j < lines[i]; j++) {
      blocks.push_back(i / 2);
    }

    if ((i + 1) < size) {
      for (int k = 0; k < lines[i + 1]; k++) {
        blocks.push_back(-1);
      };
    };
  };

  return 0;
};

int compact_blocks(std::vector<int> &blocks) {
  int block_size = blocks.size();

  // std::cout << block_size << std::endl;
  for (int i = 0; i < block_size; i++) {
    if (blocks[i] == -1) {

      for (int j = (block_size - 1); j >= i; j--) {
        if (blocks[j] != -1) {
          std::swap(blocks[i], blocks[j]);
          break;
        }
      };
    };
  }
  return 0;
}