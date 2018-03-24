#include <iostream>
#include <vector>
#include <map>

#include "allocator.h"

size_t factorial(size_t N) {
  if(N)
    return(N*factorial(N-1));
  return 1;
}

int main() {
  auto map0 = std::map<int,int>{};
  for (size_t i = 0; i < 10; i++) {
    map0[i] = factorial(i);
  }

  auto map1 = std::map<int, int, std::less<int>, my_allocator<std::pair<const int,int>>>{};
  for (size_t i = 0; i < 21; ++i) {
    map1[i] = factorial(i);
    std::cout << std::endl;
  }
  for (const auto &i : map1) {
    std::cout << i.first << " " << i.second << std::endl;
  }
  return 0;
}