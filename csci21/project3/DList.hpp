//Author:       Juan Palos
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using std::cout;
using std::endl;
using std::logic_error;
using std::ostringstream;
using std::string;

class DList  {
public:
  /*
		 * Default constructor.
		 * Initializes head and tail to nullptr, size to 0.
		 */
		DList ()  {
      size = 0;
      head = nullptr;
      tail = nullptr;
    }

    ~DList()  {
      clear();
    }

		/*
		 * Create a new Node to contain value and insert the Node
		 * at the head of this DList. Increases the size by 1.
		 */
		void pushFront (int value)  {
      if(empty()) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      }
    }

		/*
		 * Create a new Node to contain value and insert the Node
		 * at the tail of this DList. Increases the size by 1.
		 */
		void pushBack (int value);

		/*
		 * Return the value stored in the head Node.
		 * @return the value in the head Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int front () noexcept(false);

		/*
		 * Return the value stored in the tail Node.
		 * @return the value in the tail Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int back () noexcept(false);

		/*
		 * Return the size (number of Nodes in) of this DList.
		 * @return the size of this DList
		 */
		unsigned int getSize () const;

		/*
		 * Check to see if this DList is empty.
		 * @return true if this DList is empty, else false
		 */
		bool empty () const {
      return (head == nullptr);
    }

    /*
		 * Free the memory associated with all nodes in the list.
		 * Resets head to nullptr and size to 0.
		 */
    void clear ()

		/*
		 * Return a string representation of this DList.
		 * Displays the values (starting from head) of each
		 * node in the list, separated by comma.
 		 *
 		 * EXAMPLE: "13,-1,0,99,-47"
 		 *
		 * @return a string representation of this DList
		 */
		string toString () const;
private:
  unsigned int size;
		struct Node {
			Node *next;
			Node *prev;
			int value;
			Node (int newValue) {
				next = nullptr;
				prev = nullptr;
				value = newValue;
			}
		} *head, *tail;
}
