#include <iostream>
#include <vector>
#include <map>

#include "functions.h"
#include "allocator.h"
#include "container.h"

int main() {
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto map1 = std::map<int,int>{};
  for (size_t i = 0; i < 10; i++) {
    map1[i] = factorial(i);
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto map2 = std::map<int, int, std::less<int>, my_allocator<std::pair<const int,int>,10>>{};
  for (size_t i = 0; i < 10; ++i)
    map2[i] = factorial(i);
  std::cout << std::endl;

  for (const auto &i : map2)
    std::cout << i.first << " " << i.second << std::endl;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto my1 = my_container<int>{};
  for (int i = 0; i < 10; i++)
    my1.push(i);
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto my2 = my_container<int,my_allocator<element<int>,10>>{};
  for (int i = 0; i < 10; i++)
    my2.push(i);
 
  for (auto it : my2)
    std::cout << it.data << " ";
  std::cout << std::endl;

  return 0;
}