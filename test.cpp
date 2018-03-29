#define BOOST_TEST_MODULE test_main
#include <boost/test/unit_test.hpp>

#include "functions.h"
#include "allocator.h"
#include "container.h"

BOOST_AUTO_TEST_SUITE(allocator_test)

    BOOST_AUTO_TEST_CASE(std_map_with_custom_allocator_10)
    {
      auto map = std::map<int, int, std::less<int>, my_allocator<std::pair<const int,int>,10>>{};
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
      auto map = std::map<int, int, std::less<int>, my_allocator<std::pair<const int,int>,10>>{};
      for (size_t i = 0; i < 12; ++i) ///
        map[i] = factorial(i);

      int count = 0;
      for (const auto& it : map) {
        BOOST_CHECK_EQUAL(it.first,count);
        BOOST_CHECK_EQUAL(it.second,factorial(count++));
      }
    }

BOOST_AUTO_TEST_SUITE_END()