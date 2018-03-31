#define BOOST_TEST_MODULE test_main
#include <boost/test/unit_test.hpp>

#include <map>

#include "functions.h"
#include "allocator.h"
#include "container.h"

BOOST_AUTO_TEST_SUITE(allocator_test)

  BOOST_AUTO_TEST_CASE(std_map_with_custom_allocator_10)
  {
    auto map = std::map<int, int, std::less<int>, my::allocator<std::pair<const int,int>,10>>{};
    for (size_t i = 0; i < 10; ++i)
      map[i] = factorial(i);

    int count = 0;
    for (const auto& it : map) {
      BOOST_CHECK_EQUAL(it.first,count);
      BOOST_CHECK_EQUAL(it.second,factorial(count++));
    }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

  BOOST_AUTO_TEST_CASE(std_map_with_custom_allocator_12)
  {
    auto map = std::map<int, int, std::less<int>, my::allocator<std::pair<const int,int>,10>>{};
    for (size_t i = 0; i < 12; ++i)
      map[i] = factorial(i);

    int count = 0;
    for (const auto& it : map) {
      BOOST_CHECK_EQUAL(it.first,count);
      BOOST_CHECK_EQUAL(it.second,factorial(count++));
    }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

  BOOST_AUTO_TEST_CASE(std_map_with_custom_allocator_clear_and_add)
  {
    auto map = std::map<int, int, std::less<int>, my::allocator<std::pair<const int,int>,5>>{};
    for (size_t i = 0; i < 12; ++i)
      map[i] = 1;

    map.clear();

    for (size_t i = 0; i < 12; ++i)
      map[i] = 2;

    for (size_t i = 5; i < 10; ++i)
      map.erase(i);

    map.erase(11);
    map.erase(10);

    map[21] = 2;

    for (const auto& it : map) 
      BOOST_CHECK_EQUAL(it.second,2);
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

  BOOST_AUTO_TEST_CASE(my_container_with_custom_allocator_10)
  {
    auto container = my::container<int,my::allocator<my::element<int>,10>>{};
    for (size_t i = 0; i < 10; ++i)
      container.push(factorial(i));

    int count = 0;
    for (auto it : container) 
      BOOST_CHECK_EQUAL(it.data,factorial(count++));
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  BOOST_AUTO_TEST_CASE(my_container_with_custom_allocator_12)
  {
    auto container = my::container<int,my::allocator<my::element<int>,5>>{};
    for (size_t i = 0; i < 12; ++i)
      container.push(factorial(i));

    int count = 0;
    for (auto it : container) 
      BOOST_CHECK_EQUAL(it.data,factorial(count++));
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  BOOST_AUTO_TEST_CASE(my_container_with_custom_allocator_clear_and_add)
  {
    auto container = my::container<int,my::allocator<my::element<int>,5>>{};
    for (size_t i = 0; i < 12; ++i)
      container.push(1);

    container.clear();

    for (size_t i = 0; i < 7; ++i)
      container.push(2);
    
    for (size_t i = 0; i < 3; ++i)
      container.pop();

    for (auto it : container) 
      BOOST_CHECK_EQUAL(it.data,2);
  }

BOOST_AUTO_TEST_SUITE_END()