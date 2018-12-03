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

template <class T>
class DLList  {
public:
  /*
		 * Default constructor.
		 * Initializes head and tail to nullptr, size to 0.
		 */
		DLList ()  {
      size = 0;
      head = nullptr;
      tail = nullptr;
    }

    ~DLList()  {
			clear();
    }

		void clear () {
			while (head != nullptr) {
				popFront();
			}
		}

		bool empty () const {
      if(head == nullptr)	{
				return true;
			}
			return false;
    }

		bool findValue (T value) {
			Node *marker = head;
			while(marker != nullptr) {
				if(marker->value == value) {
					return true;
				}
				marker = marker->next;
			}
			return false;
		}

		T front () noexcept(false) {
			return head->value;
		}


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

		void kill (DLList<int> *&list) {
			clear();
			delete head;
			delete tail;
			list = nullptr;
		}

		void popBack() {
			if(tail == head) {
				delete tail;
				head = nullptr;
				tail = nullptr;
			} else {
				Node *marker = tail;
				tail = marker->prev;
				tail->next = nullptr;
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
				head->prev = nullptr;
				delete marker;
			}
			size--;
		}

		void pushBack (T value) {
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


		void pushFront (T value) {
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

		void removeAll (T value) {
			while(removeFirst(value));
		}

		bool removeFirst (T value) {
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
					delete marker;
					size--;
					return true;
				}
			}
			return false;
		}

		int tailVal () noexcept(false) {
			return tail->value;
		}

		string toString () const {
			Node *marker = head;
			stringstream ss;
			while(marker != nullptr) {
				if(marker->next == nullptr){
					ss << marker->value;
				} else {
					ss << marker->value;
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
			T value;
			Node (int newValue) {
				next = nullptr;
				prev = nullptr;
				value = newValue;
			}
		} *head, *tail;
};
