// Exercise 14 -- binary search tree
// bstree.hpp

#pragma once

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class BSTree
{
	public:

		BSTree ()
		: size(0), root(nullptr)
		{}

		virtual ~BSTree () {
			// ??
		}

		unsigned int getSize () {
			// ??
		}

		void clear () {
			// ??
		}

		bool insert (T newData) {
			// ??
		}

		void printInOrder () {
			// ??
		}

	private:

		unsigned int size;
		struct Node {
			T data;
			Node* leftChild;
			Node* rightChild;

			Node(T newData)
			: data(newData), leftChild(nullptr), rightChild(nullptr)
			{}
		} *root;

		void clear (Node*& troot) {
			// ??
		}

		bool insert (T newData, Node*& troot) {
			// ??
		}

		void printInOrder (Node* troot) {
			// ??
		}
};
