string Machine::decisionTree(unsigned int input)	{
	ostringstream oss;
	unsigned int i = input - 1;
	switch(i)	{
		case 0:	{
			if(items[i].stock > 0)	{
				oss << "You have selected: " << items[i].name << " at "
				<< '$' << fixed << setprecision(2) << items[i].price << " ea.";
				history.push_back(items[i]);
			}
			else if(items[i].stock == 0)	{
				oss << "Sorry we appear to be out of " << items[i].name;
			}
			break;
		}
	}
	return oss.str();
}

dud.printMenu();
	unsigned int input;
	cin >> input;
	if(input != 0 && input >= 1 && input <= 6)	{
		cout << dud.decisionTree(input) << endl;	
	}
	cout << "Would you like to select another item?(y/n)" << endl;
	char choice;
	cin >> choice;
	while(toupper(choice) == 'Y')	{
		dud.printMenu();
		cout << "Would you like to select another item?(y/n)" << endl;
		cin >> choice;
	}

	string Machine::decisionTree(unsigned int input)	{
	ostringstream oss;
	unsigned int i = input - 1;
	switch(i)	{
		case 0:	{
			if(items[i].stock > 0)	{
				oss << "You have selected: " << items[i].name << " at "
				<< '$' << fixed << setprecision(2) << items[i].price << " ea.";
				history.push_back(items[i]);
			}
			else if(items[i].stock == 0)	{
				oss << "Sorry we appear to be out of " << items[i].name;
			}
			break;
		}
	}
	return oss.str();
}

void Machine::printMenu()	{
	unsigned int i = 0;
	Machine dud;
	dud.topLine();
	cout << setfill(' ');
	while(i < items.size())	{
		cout << "|" << items[i].itemNum << ") || ";
		cout.width(15); cout << left << fixed << setprecision(2) << items[i].name << "|| ";
		cout << "$";
		cout.width(13); cout << left << items[i].price << "|| ";
		cout.width(15); cout << left << items[i].stock << "|";
		if(i < 5)	{
			cout << endl;
		}
		i++;
	}
	cout << setfill('-') << setw(59) << "\n" << endl;
	dud.bottomLine();
	cout << "Please select # of item you would like to buy or enter 0 to exit." << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//Filename		: Machine.cpp

#include "machine.h"

void Machine::welcome()	{
	Machine dud;
	ifstream begin("welcome.txt");
	string out;
	if(begin.is_open())	{
		while(getline(begin, out))	{
			cout << out << endl;
		}
	}
	dud.menu();
}

void Machine::menu()	{
	Machine dud;
	cout << "\n";
	cout << items.size() << endl;
	dud.printMenu();
	cout << items.size() << endl;
	unsigned int input;
	cin >> input;
	cout << decisionTree(input) << endl;
}

void Machine::printMenu()	{
	unsigned int i = 0;
	Machine dud;
	dud.topLine();
	cout << setfill(' ');
	while(i < items.size())	{
		cout << "|" << items[i].itemNum << ") || ";
		cout.width(15); cout << left << fixed << setprecision(2) << items[i].name << "|| ";
		cout << "$";
		cout.width(13); cout << left << items[i].price << "|| ";
		cout.width(15); cout << left << items[i].stock << "|";
		if(i < 5)	{
			cout << endl;
		}
		i++;
	}
	cout << setfill('-') << setw(59) << "\n" << endl;
	dud.bottomLine();
	cout << "Please select the # of item " << itemCount++ << " you would like to buy or enter 0 to exit." << endl;
	cout << items.size() << endl;
}

void Machine::topLine()	{
	cout << setfill('=');
	cout << setw(31) << right << "MENU" << setw(28) << "\n";
	cout << setfill(' ');
	cout << "|" << "#"<< "  || ";
		cout.width(15); cout << left << "Item" << "|| ";
		cout.width(14); cout << left << "Price" << "|| ";
		cout.width(15); cout << left << "Stock" << "|";
		cout << setfill('-') << setw(59) << "\n" << endl;
}

void Machine::bottomLine()	{
	cout << setfill(' ');
	cout << "|" << "0)"<< " || ";
		cout.width(15); cout << left << "Exit" << "|| ";
		cout.width(14); cout << left << " " << "|| ";
		cout.width(15); cout << left << " " << "|";
		cout << setfill('-') << setw(59) << "\n" << endl;
}

string Machine::decisionTree(unsigned int input)	{
	ostringstream oss;
	unsigned int i = input - 1;
	switch(i)	{
		case 0:	{
			if(items[i].stock > 0)	{
				oss << "You have selected: " << items[i].name << " at "
				<< '$' << fixed << setprecision(2) << items[i].price << " ea.";
				history.push_back(items[i]);
			}
			else if(items[i].stock == 0)	{
				oss << "Sorry we appear to be out of " << items[i].name;
			}
			break;
		}
	}
	return oss.str();
}

bool Machine::load (string filename)	{
	ifstream inputfile(filename);
	string input_str;
	Item dud;
	bool loaded = false;
	if(inputfile.is_open()) {
		while(getline(inputfile, input_str)) {
			if(input_str.find('#') != std::string::npos)	{
				input_str.clear();
			}
			else	{
				dud = makeItem(input_str);
				items.push_back(dud);
				loaded = true;
			}
		}
	}
	return loaded;
}

Item Machine::makeItem(string input) {
	Item dud;
	istringstream iss(input);
	string token;
	int i = 0;
	while (getline(iss, token, ','))	{
		switch(i)	{
			case 0:	{
				stringstream ss(token);
				ss >> dud.itemNum;
				break;
			}
			case 1:	{
				dud.name = token;
				break;
			}
			case 2:	{
				istringstream iss2(token);
				iss2 >> dud.price;
				break;
			}
			case 3:	{
				stringstream ss2(token);
				ss2 >> dud.stock;
				break;
			}
		}
		i++;
	}
	return dud;
}

		temp.name = items[i].name;
		temp.price = items[i].price;
		temp.qty = amount;
		history.push_back(temp);
		cout << dud.history[0].qty << endl;
		
		
		people.push_back({"Luke", 33});
		
void load()	{
	machine.push_back({"Aquafina", 31, 5});
	machine.push_back({"Aquafina", 31, 5});
	machine.push_back({"Aquafina", 31, 5});
	machine.push_back({"Aquafina", 31, 5});
}

