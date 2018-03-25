#include <iostream>
#include <vector>
#include <map>

#include "allocator.h"
#include "container.h"

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

  map0.get_allocator();

  auto map1 = std::map<int, int, std::less<int>, my_allocator<std::pair<const int,int>>>{};

  for (size_t i = 0; i < 10; ++i) {
    map1[i] = factorial(i);
  }
  std::cout << std::endl;

  for (const auto &i : map1) {
    std::cout << i.first << " " << i.second << std::endl;
  }

  auto my = my_container<int>{};

  my.push(1);
  std::cout << my.front() << " " << my.back() << std::endl;
  my.push(2);
  std::cout << my.front() << " " << my.back() << std::endl;
  my.push(3);
  std::cout << my.front() << " " << my.back() << std::endl;
  my.push(4);
  std::cout << my.front() << " " << my.back() << std::endl;
  my.pop();
  std::cout << my.front() << " " << my.back() << std::endl;
  my.pop();
  std::cout << my.front() << " " << my.back() << std::endl;
  my.pop();
  std::cout << my.front() << " " << my.back() << std::endl;
  my.pop();
  std::cout << my.front() << " " << my.back() << std::endl;

  return 0;
}