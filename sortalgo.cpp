#include "sortalgo.hpp"

int divide(std::vector<int> &to_sort, int start, int end) {
  int pivot = to_sort[end];
  int index = start;

  for (int i = start; i < end; i++) {
    if (to_sort[i] < pivot) {
      int temp = to_sort[i];
      to_sort[i] = to_sort[index];
      to_sort[index] = temp;
      index++;
    }
  }
  int temp = to_sort[end];
  to_sort[end] = to_sort[index];
  to_sort[index] = temp;
  return index;
}

int quickSort(std::vector<int> &to_sort, int start, int end) {
  if (start < end) {
    int d = divide(to_sort, start, end);
    quickSort(to_sort, start, (d - 1));
    quickSort(to_sort, (d + 1), end);
  }
  return 0;
}