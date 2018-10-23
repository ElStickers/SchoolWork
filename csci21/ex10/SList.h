// Exercise 10 -- Singly-linked list class
// SList.h

#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;

class SList {
	public:
		/*
		 * Default constructor.
		 * Initializes head to nullptr, size to 0.
		 */
		SList ();

		/*
		 * Destructor.
		 * Invokes clear to free the memory associated with all
		 * nodes in the list.
		 */
		virtual ~SList ();

		/*
		 * Create a new Node to contain value and insert the Node
		 * at the head of this SList. Increases the size by 1.
		 */
		void pushFront (int value);

		/*
		 * Remove the head Node.
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		void popFront () noexcept(false);

		/*
		 * Return the value stored in the head Node.
		 * @return the value in the head Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int front () noexcept(false);

		/*
		 * Return the size (number of Nodes in) of this SList.
		 * @return the size of this SList
		 */
		unsigned int getSize () const;

		/*
		 * Check to see if this SList is empty.
		 * @return true if this SList is empty, else false
		 */
		bool empty () const;

		/*
		 * Free the memory associated with all nodes in the list.
		 * Resets head to nullptr and size to 0.
		 */
		void clear ();

		/*
		 * Return a string representation of this SList.
		 * Displays the values (starting from head) of each
		 * node in the list, separated by comma.
 		 *
 		 * EXAMPLE: "13,-1,0,99,-47"
 		 *
		 * @return a string representation of this SList
		 */
		string toString () const;

	private:
		unsigned int size;
		struct Node {
			Node *next;
			int value;

			Node (int newValue) {
				next = nullptr;
				value = newValue;
			}
		} *head;
};
