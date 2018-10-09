// Exercise 2 -- std::array loaded from file
// NumberList.h

#include <array>
#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <iostream>
using std::array;
using std::function;
using std::ifstream;
using std::ostringstream;
using std::string;

class NumberList {
    public:

        /*
         * Get the size of this NumberList.
         * @return an unsigned integer containing size of
         *         this NumberList
         */
        unsigned int getSize ();

        /*
         * Retrieve the number at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the number to be retrieved
         * @return the number at the specified index; if the index is
         *         invalid, returns 0
         */
        int getNumber (unsigned int index);

        /*
         * Replace the number at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the number to be replaced
         * @param newNumber the replacement
         * @return true if the index is valid and the item is replaced,
         *         else returns false
         */
        bool replaceNumber (unsigned int index, int newNumber);

         /*
          * Load a set of numbers from a file.
          * @return true if the file contents are loaded
          *         into the array (up to a maximum of 1000
          *         numbers)
          */
         bool load (string filename);

         /*
          * Filter the array using the function f. Returned string
          * will contain the values from array for which function for
          * which function f returned true, separated by commas.
          * @param a function that takes an int and returns bool
          * @return a string containing values from array for which
          *         function f returned true
          */
         string filter(function<bool (int)>& f);

    private:

        array <int, 1000> numbers;
};
