//Author:       Juan Palos
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using std::cout;
using std::endl;
using std::logic_error;
using std::stringstream;
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
    }

		/*
		 * Return the value stored in the tail Node.
		 * @return the value in the tail Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int back () noexcept(false) {
			return tail->value;
		}

		/*
		 * Free the memory associated with all nodes in the list.
		 * Resets head to nullptr and size to 0.
		 */
		void clear ();

		/*
		 * Check to see if this DList is empty.
		 * @return true if this DList is empty, else false
		 */
		bool empty () const {
      if(head == nullptr)	{
				return true;
			}
			return false;
    }

		bool findValue (int value) {
			Node *marker = head;
			while(marker != nullptr) {
				if(marker->value == value) {
					return true;
				}
				marker = marker->next;
			}
			return false;
		}

		/*
		* Return the value stored in the head Node.
		* @return the value in the head Node
		* @throw std::logic_error("EMPTY LIST") when list is empty
		*/
		int front () noexcept(false) {
			return head->value;
		}

		/*
		 * Return the size (number of Nodes in) of this DList.
		 * @return the size of this DList
		 */
		unsigned int getSize () const	{
			return size;
		}

		void insert (int value) {
			Node *marker = head;
			while(marker != nullptr && marker->value <= value) {
				marker = marker->next;
			}
			if (marker == nullptr) 	{
				pushBack(value);
			} else if (marker == head) {
				pushFront(value);
			} else {
				Node *n = new Node(value);
				n->prev = marker->prev;
				n->next = marker;
				marker->prev = n;
				n->prev->next = n;
				size++;
			}
		}

		void popBack() {
			if(tail == head) {
				delete tail;
				head = nullptr;
				tail = nullptr;
			} else {
				Node *marker = tail;
				tail = marker->prev;
				delete marker;
			}
			size--;
		}

		void popFront() {
			if(head == tail) {
				delete head;
				head = nullptr;
				tail = nullptr;
			} else {
				Node *marker = head;
				head = marker->next;
			}
			size--;
		}

		/*
		 * Create a new Node to contain value and insert the Node
		 * at the tail of this DList. Increases the size by 1.
		 */
		void pushBack (int value) {
			Node *n1 = new Node(value);
			if(tail == nullptr) {
				tail = n1;
				head = tail;
			} else {
				tail->next = n1;
				n1->prev = tail;
				tail = n1;
			}
			n1 = nullptr;
			delete n1;
			size++;
		}

		/*
		* Create a new Node to contain value and insert the Node
		* at the head of this DList. Increases the size by 1.
		*/
		void pushFront (int value) {
			Node *n1 = new Node(value);
			if(head == nullptr) {
				head = n1;
				tail = head;
			} else {
				head->prev = n1;
				n1->next = head;
				head = n1;
			}
			n1 = nullptr;
			delete n1;
			size++;
		}

		void removeAll (int value) {
			while(removeFirst(value));
		}

		bool removeFirst (int value) {
			if(findValue(value)) {
				Node *marker = head;
				while(marker != nullptr && marker->value !=value) {
					marker = marker->next;
				}
			  if(marker == tail)	{
					popBack();
					return true;
				} else if(marker == head) {
					popFront();
					return true;
				} else {
					marker->prev->next = marker->next;
					marker->next->prev = marker->prev;
					size--;
					return true;
				}
			}
			return false;
		}

		/*
		 * Return a string representation of this DList.
		 * Displays the values (starting from head) of each
		 * node in the list, separated by comma.
 		 *
 		 * EXAMPLE: "-13,-1,0,99,147"
 		 *
		 * @return a string representation of this DList
		 */
		string toString () const {
			Node *marker = head;
			stringstream ss;
			while(marker != nullptr) {
				ss << marker->value;
				if(marker->next != nullptr) {
					ss << ",";
				}
				marker = marker->next;
			}
			return ss.str();
		}

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
};
