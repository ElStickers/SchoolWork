#include "template.hpp"

template <class T>
void doCommand(string input, T*& list){//get line of list
  istringstream iss(input);
  stringstream ss;
  string token;
  char cmd;
  int value = 0;
  int i = 0;
  while (getline(iss, token, ' ')) {
    if (i == 0) {
      ss << token;
      ss >> cmd;
    } else if (i == 1) {
      ss << token;
      ss >> value;
    }
    i++;
  }
	switch(toupper(cmd)) {
		case 'A':
		{
		if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
		}
		else {
			if(list->empty()) {
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
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				list->pushBack(value);
				cout<<"VALUE "<<value<<" ADDED TO TAIL"<<endl;
			}
				break;
		}
		case 'C':
		{
			if(list != nullptr) {
				delete list;
			}
			list = new T;
			cout<<"LIST CREATED"<<endl;
			break;
		}
		case 'D':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list == nullptr) {
					cout<<"MUST CREATE LIST INSTANCE"<<endl;
				}
				else {
					list->clear();
					cout<<"LIST DELETED"<<endl;
				}
			}
				break;
		}
		case 'E':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list->findValue(value)) {
					list->removeAll(value);
					cout<<"VALUE "<<value<<" ELIMINATED"<<endl;
				}
				else {
					cout<<"VALUE "<<value<<" NOT FOUND"<<endl;
				}
			}
			break;
		}
		case 'F':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				list->pushFront(value);
				cout<<"VALUE "<<value<<" ADDED TO HEAD"<<endl;
				break;
			}
		}
		case 'G':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list->findValue(value)) {
					cout<<"VALUE "<<value<< " FOUND"<<endl;
				}
				else {
					cout<<"VALUE "<<value<< " NOT FOUND"<<endl;
				}
			}
			break;
		}
		case 'I':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				list->insert(value);
				cout<<"VALUE "<<value<< " INSERTED"<<endl;
			}
			break;
		}

		case 'K':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list != nullptr) {
					try {
					list->popBack();
					cout<<"REMOVED TAIL"<<endl;
						}
					catch(logic_error E) {
						cout<<"LIST EMPTY"<<endl;
					}
				}
				else {
					cout<<"LIST EMPTY"<<endl;
				}
			}
			break;
		}
		case 'N':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				cout<<"LIST SIZE IS " << list->getSize() <<endl;
			}
			break;
		}
		case 'P':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list->empty()) {
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
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list->findValue(value)) {
					list->removeOne(value);
					cout<<"VALUE " <<value <<" REMOVED"<<endl;
				}
				else {
					cout<<"VALUE "<<value<<" NOT FOUND"<<endl;
				}
			}
			break;
		}
		case 'T':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list != nullptr) {
					try{
					list->popFront();
					cout<<"REMOVED HEAD"<<endl;
						}
					catch(logic_error E) {
						cout<<"LIST EMPTY"<<endl;
					}
				}
				else {
					cout<<"LIST EMPTY"<<endl;
				}
			}
			break;
		}
		case 'X':
		{
			if(list->empty()) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				list->clear();
				cout<<"LIST CLEARED"<<endl;
			}
			break;
		}
		case 'Z':
		{
			if(list == nullptr) {
				cout<<"MUST CREATE LIST INSTANCE"<<endl;
			}
			else {
				if(list->empty()) {
					cout<<"LIST EMPTY"<<endl;
				}
				else {
					cout<<"VALUE "<<list->back()<<" AT TAIL"<<endl;
				}
			}
			break;
		}
	}
}
template <class T>
void load(string fileName, T*& list) {
  ifstream inputfile(fileName);
  string input;
  if(inputfile.is_open()) {
    while(getline(inputfile, input)) {
      if(input[0] != '#') {
        doCommand(input, list);
      }
    }
    inputfile.close();
  }
  else {
    throw char('M');
  }
}

int main(int argc, char const *argv[]) {
  try {
    DList<int>* list = nullptr;
    if(argc > 2) {

      throw char('T');
    } else if (argc == 1) {
      throw char('F');
    }
    load(argv[1], list);
  } catch (const char& Me) {
    if (Me == 'M')  {
      cout << "File not uploaded!" << endl;
    }
  }
  return 0;
}
