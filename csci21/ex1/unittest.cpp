// Exercise 1 -- ShoppingList and std::array
// unittest.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ShoppingList.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("ShoppingList functionality") {

    ShoppingList myList;

    SECTION("defaults and empty list") {

        CHECK(myList.getSize() == 10);
        CHECK(myList.getItem(0) == "");
        CHECK(myList.getItem(10) == "");
        CHECK(myList.toString() == ",,,,,,,,,");
    }

    SECTION("list with one item") {

        CHECK(myList.replaceItem(0, "apples") == true);
        CHECK(myList.replaceItem(10, "oranges") == false);
        CHECK(myList.getItem(0) == "apples");
        CHECK(myList.toString() == "apples,,,,,,,,,");
    }

    SECTION("list with ten items") {

        for (unsigned int i=0; i<myList.getSize(); i+=2) {
          myList.replaceItem(i, "apples");
        }
        for (unsigned int i=1; i<myList.getSize(); i+=2) {
          myList.replaceItem(i, "oranges");
        }

        CHECK(myList.getItem(0) == "apples");
        CHECK(myList.getItem(1) == "oranges");
        CHECK(myList.toString() ==
          "apples,oranges,apples,oranges,apples,oranges,apples,oranges,apples,oranges"
        );
    }
}