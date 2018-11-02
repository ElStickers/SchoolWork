#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <string>
using std::logic_error;
using std::ostringstream;
using std::string;
using std::stringstream;

class DLList{
	public:
	   /*
		* Constructor. Initializes head/tail to nullptr; size to 0;
		*/
		DLList()
		:size(0), head(nullptr), tail(nullptr)
		{}
		unsigned int getSize(){
			return size;
		}
	   /*
		* Destructor. Frees the memory; Deletes all the nodes;
	    */
		~DLList(){
			clear();
		}
	   	/*
		 * Check to see if this DLList is empty.
		 * @return true if this DLList is empty, else false
		 */
		bool empty () const{//no head node = no list
			if(head == nullptr){
				return true;
			}
			else{
				return false;
			}
		}


	   /* Creates a Node to contain value and inserts the Node
	    * at the head of DLList. Increase size by 1;
		* @param the value to be inserted
		*/

		void pushFront (int32_t value){ //setting up head node to have a previous and next;
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
	   /* Creates a Node to contain value and inserts the Node
	    * at the tail of DLList. Increase sizel
		* @param the value to be inserted
		*/
		void pushBack (int32_t value){  //currently crashing whole thing
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


	   /* Displays the contents of the DLList
		*
		*/
		string toString () const{
			Node *marker = head;
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
	   /* Removes the head node
		* @throw std::logic_error("EMPTY LIST") if the list is empty
		*/
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
				Node *newHead = head->next;
				delete head;
				head = newHead;
				head->prev = nullptr;
				size--;
			}
		}

		/*
		 * Removes the tail node
		 * @throw std::logic_error("EMPTY LIST") if the list is empty
		 */
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
				Node *marker = head;
				while(marker->next != nullptr){
					marker = marker->next;
				}
				Node *newTail = nullptr;
				newTail = marker;
				tail = newTail->prev;//new tail is previous node
				tail->next = nullptr;//next tail is nulled
				delete newTail; // delete
				size--;
			}
			}


		/*
		 * Return the value stored in the head Node.
		 * @return the value in the head Node
		 * @throw std::logic_error("EMPTY LIST") when list is empty
		 */
		int32_t front () throw (logic_error){
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
		int32_t back () throw (logic_error){
			if(empty()){
				throw std::logic_error("LIST EMPTY");
			}
			else{
				return tail->value;
			}
		}

		/*
		 * Free the memory associated with all nodes in the list.
		 * Resets head to nullptr and size to 0.
		 */
		 void clear (){
			while(head != nullptr){
				popFront();
			}
			 head = tail = nullptr;
			 size = 0;
		 }

		 /*
		 *Finds the value in the list.
		 *
		 *@param the value to be found
		 */
		 bool findValue(int32_t find){
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


		 /*
		 *Removes value from node.
		 *
		 *@param the value to be removed
		 */
		bool removeOne(int32_t value){ //put value into node
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
		 /*
		 *Removes all instances of a value from the nodes.
		 *
		 *@param the value to be removed
		 */
		bool removeAll(int32_t value){
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
		 /*
		 *Inserts a new value into the DLL.
		 *
		 *@param the value to be inserted
		 */
		void insert(int32_t value){
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
		struct Node{
				int32_t value;
				Node *next, *prev, *mine;
				DLList *list;
				Node(int32_t newValue)
				: value(newValue), next(nullptr), prev(nullptr)
				{}
			} *head, *tail;
};
