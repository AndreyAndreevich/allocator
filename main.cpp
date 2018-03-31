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
  map1.clear();

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto map2 = std::map<int, int, std::less<int>, my::allocator<std::pair<const int,int>,10>>{};
  for (size_t i = 0; i < 10; ++i)
    map2[i] = factorial(i);
  std::cout << std::endl;

  for (const auto &i : map2)
    std::cout << i.first << " " << i.second << std::endl;

  map2.clear();

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto my1 = my::container<int>{};
  for (int i = 0; i < 10; i++)
    my1.push(i);
  
  my1.clear();

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  auto my2 = my::container<int,my::allocator<my::element<int>,10>>{};
  for (int i = 0; i < 10; i++)
    my2.push(i);
 
  for (auto it : my2)
    std::cout << it.data << " ";
  std::cout << std::endl;

  my2.clear();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  return 0;
}