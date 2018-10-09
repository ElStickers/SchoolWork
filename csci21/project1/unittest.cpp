// Project 1 -- ramen ratings database
// unittest.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Ramenator.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("Ramenator functionality") {

    Ramenator ramen;

    SECTION("check defaults") {
      CHECK(ramen.load("nofile.txt") == false);

      RamenRating dummy;
      RamenRating test;
      test.brand = "Ramenator Brand";

      CHECK(ramen.getSize() == 2500);
      CHECK(ramen.getRating(0) == dummy);
      CHECK(ramen.getRating(2499) == dummy);
      CHECK(ramen.replaceRating(0, test) == true);
      CHECK(ramen.getRating(0) == test);
      CHECK(ramen.replaceRating(2500, dummy) == false);
    }

    SECTION("large file of ratings") {
      CHECK(ramen.load("ramen-ratings.csv") == true);

      RamenRating first;
      first.reviewNumber = 2500;
      first.brand =  "The Ramen Rater Select";
      first.variety = "Supreme Creamy Tom Yum Noodle";
      first.style = "Box";
      first.country = "Malaysia";
      first.stars = 5;

      RamenRating last;
      last.reviewNumber = 1;
      last.brand = "Westbrae";
      last.variety = "Miso Ramen";
      last.style = "Pack";
      last.country = "USA";
      last.stars = 0.5;

      CHECK(ramen.getRating(0) == first);
      CHECK(ramen.getRating(2499) == last);

      ramen.sortBy(RamenSort::BRAND);
      CHECK(ramen.toString(2498, 2499) == 
        "#418:iNoodle:Udon Noodle Soup Oriental:Pack:Taiwan:3.75\n"
        "#445:iNoodle:Taiwan Style Chow Mein:Pack:Taiwan:2.25\n"
      );

      ramen.sortBy(RamenSort::VARIETY);
      CHECK(ramen.toString(2498, 2499) ==
        "#1001:Paldo:ДОШИРАК (Dosirac) Beef Flavor:Pack:South Korea:3.5\n"
        "#1250:Samyang Foods:三養라면 (Samyang Ramyun) (South Korean Version):Bowl:South Korea:3.75\n"
      );

      ramen.sortBy(RamenSort::STYLE);
      CHECK(ramen.toString(2498, 2499) ==
        "#197:Rhee Bros Assi:Rice Noodle With Spicy Flavored Soup:Tray:South Korea:2.25\n"
        "#903:Han's South Korea:Rice Noodle With Seafood Flavored Soup:Tray:South Korea:3.5\n"
      );

      ramen.sortBy(RamenSort::COUNTRY);
      CHECK(ramen.toString(2498, 2499) ==
        "#1013:Vina Acecook:Oh! Ricey Hủ Tiếu Sườn Heo (Pork Spareribs Flavour):Pack:Vietnam:3.5\n"
        "#588:Vifon:Tu Quy Pork:Pack:Vietnam:2.75\n"
      );

      ramen.sortBy(RamenSort::STARS);
      CHECK(ramen.toString(2498, 2499) ==
        "#1693:Mama:Instant Noodles coconut Milk Flavour:Cup:Myanmar:5\n"
        "#1902:MAMA:Seafood Tom Yum Sichek Flavour:Pack:Myanmar:5\n"
      );

        function<bool (RamenRating)> mexico = [](RamenRating r)
        {
          return r.country == "Mexico" &&
                 r.style == "Cup" &&
                 r.stars >= 4;
        };
        CHECK(ramen.filter(mexico) ==
          "#2333:Nissin:Maxi Sopa Nissin Cuchareable Sabor A Pollo:Cup:Mexico:4\n"
          "#2343:Nissin:Maxi Sopa Nissin Cuchareable Sabor A Jugo De Carne:Cup:Mexico:4\n"
          "#2341:Nissin:Cup Noodles Sopa Nissin Sabor A Carne De Res:Cup:Mexico:4\n"
          "#2340:Nissin:RapiFideo Sabor A Tomate Y Pollo:Cup:Mexico:4\n"
          "#2331:Nissin:Cup Noodles Sopa Nissin Hot Sauce Sabor A Pollo:Cup:Mexico:4\n"
          "#2344:Nissin:Cup Noodles Sopa Nissin Sabor A Pollo:Cup:Mexico:4\n"
          "#2335:Nissin:Cup Noodles Gourmet Sabor A Caldo De Camaron:Cup:Mexico:5\n"
      );
    }
}
