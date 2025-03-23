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
  getLines(path, lines);
  get_blocks(lines, blocks);
  compact_blocks(blocks);

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
  for (int l = 0; l < blocks.size(); l++) {
    if (blocks[l] == -1) {
      std::cout << ".";
    } else {
      std::cout << blocks[l];
    }
  }
  return 0;
};

int compact_blocks(std::vector<int> &blocks) {
  int block_size = blocks.size();
  for (int i = 0; i < block_size; i++) {
    if (blocks[i] == -1) {
      int replacement = blocks[block_size];
      int count = 1;
      while (replacement == -1 || block_size - count != i) {
        count++;
        replacement = blocks[block_size - count];
      }
      std::swap(blocks[i], blocks[block_size - count]);
    }
    for (int j = 0; j < block_size; j++) {
      std::cout << blocks[i];
    };
    std::cout << " " << std::endl;
  };
  return 0;
};