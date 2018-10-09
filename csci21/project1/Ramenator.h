// Project 1 -- ramen ratings database
// Ramenator.h

#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
using std::array;
using std::function;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::ostringstream;
using std::sort;
using std::string;
using std::stringstream;

enum class RamenSort {BRAND, VARIETY, STYLE, COUNTRY, STARS};

struct RamenRating {
  unsigned int reviewNumber;
  string brand;
  string variety;
  string style;
  string country;
  float stars;

  // Default contructor
  // Allows creation of "dummy" RamenRatings.
  RamenRating () {
    reviewNumber = 0;
    brand ="Ramenator Brand";
    variety = "Ramen";
    style = "Cup";
    country = "None";
    stars = 0.0;
  }

  // Overloaded operator==
  // Allows comparison of two RamenRatings
  bool operator== (const RamenRating& r) const {
    return (
      reviewNumber == r.reviewNumber &&
      brand == r.brand &&
      variety == r.variety &&
      style == r.style &&
      country == r.country &&
      stars == r.stars
    );
  }

  // Overloaded operator<<
  // Allows convenient stream output of RamenRatings
  friend ostream& operator<< (ostream& outs, const RamenRating& r) {
    outs << "#" << r.reviewNumber << ':'
         << r.brand << ':'
         << r.variety << ':'
         << r.style << ':'
         << r.country << ':'
         << r.stars;
    return outs;
  }
};

// RamenRating comparison functions -- headers
bool compareBrands (RamenRating l, RamenRating r);
bool compareVarieties (RamenRating l, RamenRating r);
bool compareStyles (RamenRating l, RamenRating r);
bool compareCountries (RamenRating l, RamenRating r);
bool compareStars (RamenRating l, RamenRating r);

// Ramenator class header
class Ramenator {
    public:

        /*
         * Get the size of this Ramenator.
         * @return an unsigned integer containing size of
         *         this Ramenator
         */
        unsigned int getSize ();

        /*
         * Retrieve the RamenRating at a specified index.
         * @param index an unsigned integer containing the zero-based index
         *        of the RamenRating to be retrieved
         * @return the RamenRating at the specified index; if the index is
         *         invalid, returns a "dummy" RamenRating
         */
        RamenRating getRating (unsigned int index);

        /*
         * Replace the RamenRating at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the RamenRating to be replaced
         * @param newRating the replacement
         * @return true if the index is valid and the RamenRating is replaced,
         *         else returns false
         */
        bool replaceRating (unsigned int index, RamenRating newRating);

         /*
          * Load a set of RamenRatings from a file.
          * @return true if the file contents are loaded
          *         into the array (up to a maximum of 2500
          *         (array size) RamenRatings)
          */
         bool load (string filename);

         /*  
          * Filter the array using the function f. Returned string
          * will contain the RamenRatings from array for which function for
          * which function f returned true, separated by newlines.
          * @ param a function that takes a RamenRating and returns bool
          * @param limit if 0, all matches will be returned; if not 0, filter
          *        will stop at limit matches
          * @return a string containing RamenRatings from array for which
          *         function f returned true, separated by newlines
          */
         string filter (function<bool (RamenRating)>& f, unsigned int limit=0);

         /*
          * Sort the array.
          * @param field the field to sort by (all sorts will be ascending)
          */
          void sortBy (RamenSort field);

          /*
           * Locate the first RamenRating in the array matching the value of
           * field in matcher.
           * @param field the field to match by
           * @param matcher a RamenRating set to have a field with the desired
           *        value
           * @return first RamenRating that matches matcher on field, or
           *         a dummy RamenRating on failed search
           */
          RamenRating locateFirstMatch (RamenSort field, RamenRating matcher);

          /*
           * Return a string representation of a portion of the ratings
           * in the array.
           * @param start the index from which to start
           * @param end the index at which to end
           * @return a string (one rating per line) containing the RamenRatings
           *         from start to end indexes in the array
           */
           string toString (unsigned int start, unsigned int end);

    private:

        array<RamenRating, 2500> ratings;

        /*
         * Tokenize the input and use it to populated the fields
         * of a RamenRating.
         * @param input an input line from a file of ramen ratings
         * @return a RamenRating containing the data from the input line
         *
         * EXAMPLE INPUT:
         *   2496,Nissin,Soba Thai,Pack,Germany,4.5
         *   reviewNumber,brand,variety,style,country,stars
         */
        RamenRating makeRating (string input);
};
