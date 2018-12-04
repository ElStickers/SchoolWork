/*
*	NAME: LUKE PHILIPS
* 	DATE: MAY 15th 2018
*	PURPOSE: BINARY SEARCH TREE - TRAVERSES, MANIPULATES, AND SORTS DATA IN TREE FORM
*/
#include <iostream>
#include <string>

template <typename T>
class BSTree{
	public:
	   /*
		* Constructor. Initializes root to nullptr; size to 0;
		*/
		BSTree(){
			root = nullptr;
			size = 0;
		}
	   /*
		* Destructor. Frees the memory; Deletes all the nodes;
	    */
		virtual ~BSTree(){
			clear();
		}
	   /*
		* Get the amount of Nodes in the Tree
		* @return size, the number of nodes
	    */
		int getSize(){
			return size;
		}
	   /*
		* Calls the recursive clear function
		* 
	    */
		void clear(){
			clear(root);
		}
	   /*
		* Calls the recursive insert function
		* @param newData the data to be inserted
		* @return calls insert with param of data and link to root
	    */
		bool insert(T newData){
			return insert(newData, root);
		}
	   /*
		* Calls the recursive find function
		* @param target the data to be found
		* @return calls find with param the data to be found and link to root
	    */
		bool find(T target){
			return find(target, root);
		}
		/*
		* Calls the recursive remove function
		* @param target the data to be removed
		* @return calls find with param of data to be removed and link to root
	    */
		bool remove (T target){
			return remove(target, root);
		}
	   /*
		* Calls the recursive get function
		* @param target the data to be removed
		* @return calls find with param of data to be removed and link to root
	    */
		T* get (T target){
			return get(target, root);
		}
       /*
		* Calls the recursive printInOrder function
	    */
		void printInOrder (){
				printInOrder(root);
		}
	   /*
		* Calls the recursive printInOrder function
	    */
		void printReverseOrder (){
				printReverseOrder(root);
		}

	private:
		int size;
		struct Node {
			T data;
			Node* leftChild;
			Node* rightChild;

			Node(T newData)
			: data(newData), leftChild(nullptr), rightChild(nullptr)
			{}
		} *root;
	   
	   /*
		* Clears the tree of all data
		* @param troot a link to the BSTree
		* 
	    */
	void clear(Node*& troot){
		if(troot == nullptr){
		}
		else{
			clear(troot->leftChild);
			clear(troot->rightChild);
			delete troot;
			size = 0;
			troot = nullptr;
		}
	}
	   /*
		* Looks for empty node in tree to insert data, checks for duplicates
		* @param newData the data to be inserted
		* @param troot a link to the BSTree
		* @returns true if data is inserted, false if not
	    */
	bool insert(T newData, Node*& troot){ 
		if(troot == nullptr){
			troot = new Node(newData);
			size++;
			return true;
		}
		else if(newData > troot->data){
			return insert(newData, troot->rightChild);
		} 
		else if(newData < troot->data){
			return insert(newData, troot->leftChild);
		}
		else{
			return false;
		}
	}
		/*
		* Looks for the target data in tree
		* @param target the data to be found
		* @param troot a link to the BSTree
		* @returns true if data is found, false if not
	    */
	bool find(T target ,Node*& troot){
		if(troot == nullptr){
			return false;
		}
		else if(target < troot->data){
			return find(target, troot->leftChild);
		}
		else if(target > troot->data){
			return find(target, troot->rightChild);
		}
		else{
			return true;
		}
	}
	
	   /*
		* Removes targeted data from tree with recursive removeMax call to traverse the higher values
		* @param target the data to be removed
		* @param troot a link to the BSTree
		* @returns true if data is removed, false if not
	    */
	bool remove (T target, Node*& troot){
		if(troot == nullptr){
			return false;
		}
		else if(target < troot->data){
			return remove(target, troot->leftChild);
		}
		else if(target > troot->data){
			return remove(target, troot->rightChild);
		}
		else{
			if(troot->leftChild == nullptr){
				Node* oldroot = troot;
				troot = troot->rightChild;
				delete oldroot;
			}
			else{
				removeMax(troot->data, troot->leftChild);
			}
			size--;
			return true;
		}
	}
	   /*
		* Removes targeted data from right side of tree
		* @param removed the data to be removed
		* @param troot a link to the BSTree
	    */
	void removeMax (T& removed, Node*& troot){
		if(troot->rightChild == nullptr){
			removed = troot->data;
			troot = troot->leftChild;
			delete troot;
		}
		else{
			removeMax(removed, troot->rightChild);
		}
	}
	   /*
		* Retrieves data from target node
		* @param target the data to get got
		* @param troot a link to the BSTree
		* @return a reference to the data of troot
	    */
	T* get (T target, Node* troot){
		if(troot == nullptr){
			return nullptr;
		}
		else if(target < troot->data){
			return get(target, troot->leftChild);
		}
		else if(target > troot->data){
			return get(target, troot->rightChild);
		}
		else{
			return &(troot->data);
		}
	}
	   /*
		* Prints the tree lexographically
		* @param troot a link to the BSTree
	    */
	void printInOrder (Node* troot){
		if(troot != nullptr){
				printInOrder(troot->rightChild);
				std::cout<<troot->data<<std::endl;
				printInOrder(troot->leftChild);
			}
	}
	   /*
		* Prints the tree anti-lexographically
		* @param troot a link to the BSTree
	    */
	void printReverseOrder (Node* troot){
		if(troot != nullptr){
			printReverseOrder(troot->leftChild);
			std::cout<<troot->data<<std::endl;
			printReverseOrder(troot->rightChild);
		}
	}
	
};
