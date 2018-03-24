#include <iostream>
#include <vector>
#include <map>

#include "allocator.h"

int main() {
  auto m = std::map<int, int, std::less<int>, my_allocator<std::pair<const int,int>>>{};
  for (size_t i = 0; i < 5; ++i) {
    m[i] = i;
    std::cout << std::endl;
  }
  for (const auto &i : m) {
    std::cout << i.first << std::endl;
  }
  return 0;
}