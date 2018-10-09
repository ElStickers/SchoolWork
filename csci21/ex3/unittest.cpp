// Exercise 3 -- searching and sorting
// unittest.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "NumberList.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("NumberList functionality") {

    NumberList myList;

    SECTION("numbers mixed up") {
      CHECK(myList.load("mixed.txt") == true);
      myList.bubbleSort();

      CHECK(myList.toString() == "1,2,3,4,5,6,7,8,9,10");
      CHECK(myList.linearSearch(1) == true);
      CHECK(myList.linearSearch(10) == true);
      CHECK(myList.linearSearch(0) == false);
    }

    SECTION("numbers ordered ascending") {
      CHECK(myList.load("ordered_asc.txt") == true);
      myList.bubbleSort();
      CHECK(myList.toString() == "1,2,3,4,5,6,7,8,9,10");
      CHECK(myList.linearSearch(1) == true);
      CHECK(myList.linearSearch(10) == true);
      CHECK(myList.linearSearch(0) == false);
    }

    SECTION("numbers ordered descending") {
      CHECK(myList.load("ordered_desc.txt") == true);
      myList.bubbleSort();
      CHECK(myList.toString() == "1,2,3,4,5,6,7,8,9,10");
      CHECK(myList.linearSearch(1) == true);
      CHECK(myList.linearSearch(10) == true);
      CHECK(myList.linearSearch(0) == false);
    }

    SECTION("numbers with duplicates") {
      CHECK(myList.load("duplicates.txt") == true);
      myList.bubbleSort();
      CHECK(myList.toString() == "1,1,2,2,3,3,4,4,5,5");
      CHECK(myList.linearSearch(1) == true);
      CHECK(myList.linearSearch(5) == true);
      CHECK(myList.linearSearch(0) == false);
    }
}
