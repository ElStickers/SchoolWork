// Exercise 1 -- ShoppingList and std::array
// ShoppingList.h

#include <array>
#include <sstream>
#include <string>
using std::array;
using std::ostringstream;
using std::string;

class ShoppingList {
    public:

        /*
         * Get the size of this ShoppingList.
         * @return an unsigned integer containing the size of
         *         this ShoppingList
         */
        unsigned int getSize ();

        /*
         * Retrieve the value of the item at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be retrieved
         * @return the value of the string at the specified index; returns
         *         empty string if index is invalid
         */
        string getItem (unsigned int index);

        /*
         * Replace the item at a specified index in the array.
         * @param index an unsigned integer containing the zero-based index
         *        of the item to be replaced
         * @param newItem the replacement
         * @return true if the index is valid and the item is replaced,
         *         else returns false
         */
        bool replaceItem (unsigned int index, string newItem);

        /*
         * Return a string representation of this ShoppingList.
         * @return a string containing each item in the list, separated by
         *         commas.
         *
         * EXAMPLE: apple,orange,lemon,grape,persimmon
         */
         string toString ();

    private:

        array<string, 10> items;
};