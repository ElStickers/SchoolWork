#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cstdint>
#include <iostream>

using std::istringstream;
using std::cout;
using std::endl;
using std::ifstream;
using std::logic_error;
using std::stringstream;
using std::ostringstream;
using std::string;

template <class T>
class DList {
	public:
		/*
		 * Default constructor.
		 * Initializes head and tail two nullptr, size to 0.
		 */
    DList()
 		:size(0), head(nullptr), tail(nullptr)
 		{}
 		unsigned int getSize(){
 			return size;
 		}
		~DList(){
		 clear();
		}

		/*
		 * Create a new Node to contain value and insert the Node
		 * at the head of this DList. Increases the size by 1.
		 */
		void pushFront (T value){
			Node *n1 = new Node(value);
			if(head == nullptr){
				head = n1;
				tail = head;
			}
			else{
				n1->next = head;
				head->prev = n1;
				head = n1;
			}
			size++;
		}

		/*
		 * Create a new Node to contain value and insert the Node
		 * at the tail of this DList. Increases the size by 1.
		 */
		void pushBack (T value) {
			Node *n2 = new Node(value);
			if(head == nullptr){
				head = n2;
				tail = head;
			}
			else{
				n2->prev = tail;
				tail->next = n2;
				tail = n2;
			}
				size++;
		}

		/*
		 * Return the value stored in the head Node.
		 * @return the value in the head Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int front () throw (logic_error){
			if(empty()){
				throw std::logic_error("LIST EMPTY");
			}
			else{
				return head->value;
			}
		}

		/*
		 * Return the value stored in the tail Node.
		 * @return the value in the tail Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int back () throw (logic_error) {
			if(empty()){
				throw std::logic_error("LIST EMPTY");
			}
			else {
				return tail->value;
			}
		}

		/*
		 * Return the size (number of Nodes in) of this DList.
		 * @return the size of this DList
		 */
		unsigned int getSize () const {
			return size;
		}

		/*
		 * Check to see if this DList is empty.
		 * @return true if this DList is empty, else false
		 */
		bool empty () const {
			if(head == nullptr){
				return true;
			}
			else{
				return false;
			}
		}

		/*
		 * Return a string representation of this DList.
		 * Displays the values (starting from head) of each
		 * node in the list, separated by comma.
 		 *
 		 * EXAMPLE: "13,-1,0,99,-47"
 		 *
		 * @return a string representation of this DList
		 */
		string toString () const {
			Node* marker = head;
			stringstream ss;
			while(marker != nullptr ){
				if( marker->next == nullptr ){
					ss << marker->value;
				}
				else{
					ss << marker->value<<",";
				}
				marker = marker->next;
			}
			return ss.str();
		}

		void popFront () throw (logic_error){
			if(empty()){
				throw std::logic_error("EMPTY LIST");
			}
			else if(head == tail){
				delete head;
				head = tail = nullptr;
				size--;
			}
			else{
				Node* newHead = head->next;
				delete head;
				head = newHead;
				head->prev = nullptr;
				size--;
			}
		}

		bool removeOne(T value){ //put value into node
			if(head == nullptr){
				return false;
			}
			else if(head->value == value){
				popFront();
				return true;
			}
			else if(tail->value == value){
				popBack();
				return true;
			}
			else{
				Node *marker = head;
				while(marker != nullptr && marker->value != value){
					marker = marker->next;
				}
				if(marker == nullptr){
					return false;
				}
			marker->prev->next = marker->next;
			marker->next->prev = marker->prev;
			delete marker;
			size--;
			return true;
			}
		}

		bool removeAll(T value){
			int counter = 0;
			while(findValue(value)){
				removeOne(value);
				counter++;
			}
			if(counter > 0 ){
				return true;
			}
			return false;
		}

		void popBack (){
			if(empty()){
				throw std::logic_error("EMPTY LIST");
			 }
			else if(tail == head){
				delete tail;
				head = tail = nullptr;
				size--;
			}
			else{
				Node* marker = head;
				while(marker->next != nullptr){
					marker = marker->next;
				}
				Node* newTail = nullptr;
				newTail = marker;
				tail = newTail->prev;//new tail is previous node
				tail->next = nullptr;//next tail is nulled
				delete newTail; // delete
				size--;
			}
			}
	void clear() {
		/*while(head != nullptr) {
			popFront();
		}*/
			head = nullptr;
			tail = nullptr;
			size = 0;
	}

	bool findValue(T find){
		Node *marker = head;
		if(marker == nullptr){
			return false;
		}
		while(marker != nullptr){ //marker != nullptr;
			if(marker->value == find){
				return true;
			}
			marker = marker->next;
		}
		return false;//value not found
	}

	void insert(T value){
		if (head == nullptr || value <= head->value){ //because ascending order;
			pushFront(value);
		}
		else if (value >= tail->value){
			pushBack(value);
		}
		else{
			Node* marker = head;
			while(marker->value <= value ){
				marker = marker->next;
			}
			Node *n = new Node(value);
			n->next = marker;
			n->prev = marker->prev;
			n->prev->next = n;
			marker->prev = n;

			size++;
		}
	}


	private:
		unsigned int size;

		struct Node {
			Node* next;
			Node* prev;
			T value; //changed

			Node (T newValue) { // changed
				next = nullptr;
				prev = nullptr;
				value = newValue;
			}
		} *head, *tail;
};
