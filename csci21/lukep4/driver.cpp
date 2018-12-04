/*
*	NAME: LUKE PHILIPS
* 	DATE: MAY 15th 2018
*	PURPOSE: DRIVER FOR BINARY SEARCH TREE. LOADS FILES, CHECKS COMMAND, CALLS BSTREE.hpp TO TRAVERSE TREE
*/

#include "bstree.hpp"
#include "word.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

void doCommand(string cmd, BSTree<Word>*& tree, string theWord);
bool loadFile(string filename, BSTree<Word>*& tree);

/* Takes command from the input file and manipulates list.
 * 
 * @param cmd the command to be exectued
 * @param BSTree a pointer/reference to the BSTree class
 */
void doCommand(string cmd, BSTree<Word>*& tree, string theWord, Word& create){
	create.setWord(theWord);
	if (cmd[0] == '#'){
		return;
	}
	else if(tree == nullptr && cmd[0] != 'C'){
		cout<<"MUST CREATE TREE INSTANCE"<<endl;
		return;
	}
	
	switch(toupper(cmd[0])){
		//create
		case 'C':
		{
			if(tree != nullptr){
				delete tree;
			}
			tree = new BSTree<Word>;
			cout<<"TREE CREATED"<<endl;
			break;
		}	
			//clear
		case 'D':
		{
			delete tree;
			cout<<"TREE DELETED"<<endl;
			tree = nullptr;
			break;
			
		}
			//print reverse
		case 'E':
		{
			if(tree->getSize() == 0){
				cout<<"TREE EMPTY"<<endl;
			}
			else{
				tree->printReverseOrder();
			}
			break;
		}
			//find
		case 'F':
		{
			if(tree->getSize() == 0){
				cout<<"TREE EMPTY"<<endl;
			}
			else if(tree->find(theWord) == true){
				cout<<"FOUND "<< theWord <<endl; 
			}
			else{
				cout<<theWord<<" NOT FOUND"<<endl;
			}
			break;
		}
			//get
		case 'G': 
		{
			if(tree->getSize() == 0){
				cout<<"TREE EMPTY"<<endl;
			}
			else if(tree->get(theWord) && create.getCount() > 0){ 
				cout<<"GOT " <<  *tree->get(theWord) <<endl;
			}
			else{
				cout<< theWord   <<" NOT FOUND" <<endl;
			}
			break;
		}
			//insert
		case 'I': //have to increment here
		{
			if(!tree->find(theWord)){
				tree->insert(Word(theWord));
				cout<<"WORD "<<theWord<<" INSERTED"<<endl;
			}
			else{
				cout<<"WORD " <<theWord<<" INCREMENTED"<<endl;
				tree->get(theWord)->incrementCount();
			}
			break;
		}
			//tree size
		case 'N':
		{
			cout<<"TREE SIZE IS "<<tree->getSize()<<endl;//check whitespace here.
			break;
		}
		case 'R':
		{
			if(tree->getSize() == 0){
				cout<<"TREE EMPTY"<<endl;
			}
			else if(tree->find(theWord)){
				tree->remove(theWord);
				cout<<"REMOVED "<<theWord<<endl;
			}
			else{
				cout<<theWord<<" NOT FOUND"<<endl;
			}
			break;
		}
		case 'O':
		{
			if(tree->getSize() == 0){
				cout<<"TREE EMPTY"<<endl;
			}
			else{
				tree->printInOrder();
			}
			break;
		}
		case'X':
		{
			tree->clear();
			cout<<"TREE CLEARED"<<endl;
			break;
		}
		default:
		{
			break;
		}
	}
	
}
/* Loads an input file.
 * 
 * @param filename the name of file to be loaded
 * @param BSTree a pointer/reference to the BSTree class
 * @return true if file is successfully loaded.
 */
bool loadFile(string filename,BSTree<Word>*& tree){
	string data;
	string theWord;
	ifstream inFile(filename.c_str());
	if(inFile.is_open()){
		while(getline(inFile, data)){
			if(data[0] == '#'){
			}
			else{
				if(data.size() > 1){
					theWord = data.substr(2);
				}
				else{
					theWord == "";
				}
				Word create(theWord);
				doCommand(data, tree, theWord, create);
			}
		}
		return true;
	}
	else{
		return false;
	}
	inFile.close();
}

int main(int argc, char* argv[]){ 
	BSTree<Word> *tree = nullptr;
	if( argc == 2){
		if (loadFile(argv[1], tree)){
		}
		else{
			cout<<"INVALID FILE"<<endl;
			return 0;
		}
	}
	else{
		cout<<"Usage: args.exe FILENAME"<<endl;
		return 0;
	}
	return 0;
}