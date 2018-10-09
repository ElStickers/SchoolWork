// Exercise 2 -- std::array loaded from file
// unittest.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "NumberList.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("NumberList functionality") {

    NumberList myList;

    SECTION("check defaults") {
      CHECK(myList.load("nofile.txt") == false);
      CHECK(myList.getSize() == 1000);
      CHECK(myList.getNumber(0) == 0);
      CHECK(myList.getNumber(1000) == 0);
      CHECK(myList.replaceNumber(0, 1) == true);
      CHECK(myList.getNumber(0) == 1);
      CHECK(myList.replaceNumber(1000, 1) == false);
    }

    SECTION("load a small file") {
    }

    SECTION("load a large file and apply various filters") {
      CHECK(myList.load("numbers.txt") == true);
      CHECK(myList.getNumber(0) == 271);
      CHECK(myList.getNumber(999) == -827);

      function<bool (int)> hundreds = [](int n) { return n % 100 == 0; };
      CHECK(myList.filter(hundreds) ==
        "-400,1000,600,-1000,400,700,600,0,-400,-500");

      function<bool (int)> tinies = [](int n) { return n < -990; };
      CHECK(myList.filter(tinies) ==
        "-999,-1000,-992,-999,-992,-992,-992");

      function<bool (int)> biggies = [](int n) { return n > 990; };
      CHECK(myList.filter(biggies) ==
        "998,999,1000,994,997,993,999");
    }
}
