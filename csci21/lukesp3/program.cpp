#include "dllist.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using std::string;
using std::ifstream;
using namespace std;


void doCommand(string cmd, DLList*&list);



/* Loads an input file.
 *
 * @param filename the name of file to be loaded
 * @param DLList a pointer/reference to the DLList class
 * @return true if file is successfully loaded.
 */

bool loadFile(string filename, DLList *&list){
	string data;
	stringstream ssin;
	ifstream inFile(filename.c_str());
	if(inFile.is_open()){
		while(getline(inFile, data)){
			if(data[0] == '#'){
			}
			else{
				doCommand(data, list);
			}
		}
		return true;
	}
	else{
		return false;
	}
}
/* Takes command from the input file and manipulates list.
 *
 * @param cmd the command to be exectued
 * @param DLList a pointer/reference to the DLList class
 */
void doCommand(string cmd, DLList *&list){//get line of list

	switch(toupper(cmd[0])){
		case 'A':
		{
		if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
		}
		else{
			if(list->empty()){
				cout<<"LIST EMPTY"<<endl;
			}
			else{
				cout<<"VALUE "<<list->front()<<" AT HEAD"<<endl;
			}
		}
			break;
	}
		case 'B':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				string mine = cmd.substr(2);
				uint32_t rip = atoi(mine.c_str());
				list->pushBack(rip);
				cout<<"VALUE "<<rip<<" ADDED TO TAIL"<<endl;
			}
				break;
		}
		case 'C':
		{
			if(list != nullptr){
				delete list;
			}
			list = new DLList;
			cout<<"LIST CREATED"<<endl;
			break;
		}
		case 'D':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				if(list == nullptr){
					cout<<"MUST CREATE LIST INSTANCE"<<endl;
				}
				else{
					list->clear();
					cout<<"LIST DELETED"<<endl;
					//list == nullptr;
				}
			}
				break;
		}
		case 'E':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				string mine = cmd.substr(2);
				int rip = atoi(mine.c_str());
				if(list->findValue(rip)){
					list->removeAll(rip);
					cout<<"VALUE "<<rip<<" ELIMINATED"<<endl;
				}
				else{
					cout<<"VALUE "<<rip<<" NOT FOUND"<<endl;
				}
			}
			break;
		}
		case 'F':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				string mine = cmd.substr(2);
				int rip = atoi(mine.c_str());
				list->pushFront(rip);
				cout<<"VALUE "<<rip<<" ADDED TO HEAD"<<endl;
				break;
			}
		}
		case 'G':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				string mine = cmd.substr(2);
				int rip = atoi(mine.c_str());
				if(list->findValue(rip)){
					cout<<"VALUE "<<rip<< " FOUND"<<endl;
				}
				else{
					cout<<"VALUE "<<rip<< " NOT FOUND"<<endl;
				}
			}
			break;
		}
		case 'I':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				string mine = cmd.substr(2);
				int rip = atoi(mine.c_str());
				list->insert(rip);
				cout<<"VALUE "<<rip<< " INSERTED"<<endl;
			}
			break;
		}

		case 'K':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				if(list != nullptr){
					try{
					list->popBack();
					cout<<"REMOVED TAIL"<<endl;
						}
					catch(logic_error E){
						cout<<"LIST EMPTY"<<endl;
					}
				}
				else{
					cout<<"LIST EMPTY"<<endl;
				}
			}
			break;
		}
		case 'N':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				cout<<"LIST SIZE IS " << list->getSize() <<endl;
			}
			break;
		}
		case 'P':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				if(list->empty()){
					cout<<"LIST EMPTY"<<endl;
				}
				else{
					cout<<list->toString()<<endl;
				}
			}
			break;
		}
		case 'R':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				string mine = cmd.substr(2);
				int rip = atoi(mine.c_str());
				if(list->findValue(rip)){
					list->removeOne(rip);
					cout<<"VALUE " <<rip <<" REMOVED"<<endl;
				}
				else{
					cout<<"VALUE "<<rip<<" NOT FOUND"<<endl;
				}
			}
			break;
		}
		case 'T':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				if(list != nullptr){
					try{
					list->popFront();
					cout<<"REMOVED HEAD"<<endl;
						}
					catch(logic_error E){
						cout<<"LIST EMPTY"<<endl;
					}
				}
				else{
					cout<<"LIST EMPTY"<<endl;
				}
			}
			break;
		}
		case 'X':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				list->clear();
				cout<<"LIST CLEARED"<<endl;
			}
			break;
		}
		case 'Z':
		{
			if(list == nullptr){
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else{
				if(list->empty()){
					cout<<"LIST EMPTY"<<endl;
				}
				else{
					cout<<"VALUE "<<list->back()<<" AT TAIL"<<endl;
				}
			}
			break;
		}
	}
}
//main - ensures 2 arguments are provided
int main(int argc, char* argv[]){
	if( argc == 2){
		DLList *list = nullptr;
		if (loadFile(argv[1], list)){
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
