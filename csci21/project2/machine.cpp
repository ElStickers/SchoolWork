//Filename		: Machine.cpp

#include "machine.h"
#include "CinReader.cpp"

unsigned int Machine::purchaseSize()	{
	return purchase.size();
}

void Machine::welcome()	{
	Machine dud;
	ifstream begin("welcome.txt");
	string out;
	if(begin.is_open())	{
		while(getline(begin, out))	{
			cout << out << endl;
		}
	}
}

void Machine::display()	{
	CinReader reader;
	Machine dud;
	unsigned int count = 0;
	dud.load("vending_machine_items.csv");
	bool run = true;
	unsigned int input;
	while(run == true)	{
		dud.clearScreen();
		dud.printMenu(count);
		if(count == 0)	{
			input = reader.readInt(0, 6);
			count++;
		}
		else if(count > 1)	{
			input = dud.printCart(count);
		}
		if(input > 0 && input <= dud.items.size())	{
			cout << dud.decisionTree(input) << endl;
			if(dud.items[input - 1].stock == 0)	{
				count--;
				}
		}
		else if(input == 0)	{
			dud.exit();
		}
		bool tryAgain = false;
		while(tryAgain == false)	{
			cout << "Would you like to select another item?(y/n)" << endl;
			char choice;
			choice = reader.readChar("ny");
			if(toupper(choice) == 'Y')	{
				tryAgain = true;
				count++;
			}
			else if(toupper(choice) == 'N')	{
				run = false;
				break;
			}
		}
	}
	dud.finalizePurchase();
}

void Machine::printMenu(unsigned int counter)	{
	CinReader reader;
	unsigned int i = 0;
	Machine dud;
	dud.welcome();
	dud.topLine();
	cout << setfill(' ');
	while(i < items.size())	{
		cout << items[i];
		if(i < 5)	{
			cout << endl;
		}
		i++;
	}
	cout << setfill('-') << setw(59) << "\n" << endl;
	dud.bottomLine();
	if(counter == 0)	{
		cout << "Please select the # of item you would like to buy or enter 0 to exit." << endl;
	}	
}

void Machine::finalizePurchase()	{
	Machine dud;
	dud.clearScreen();
	dud.welcome();
	float total = 0;
	if(!purchase.empty())	{
		cout << setfill('=');
		cout << setw(32) << right << "Cart Total" << setw(28) << "\n";
		cout << setfill(' ');
		cout << "| ";
		cout.width(11); cout << left << "Item" << "|| ";
		cout.width(11); cout << left << "Price" << "|| ";
		cout.width(13); cout << left << "Quantity" << "|| ";
		cout.width(12); cout << left << "Total" << "|";
		cout << setfill('-') << setw(60) << "\n" << endl;
		cout << setfill(' ');
		for(unsigned int i = 0; i < purchase.size(); i++)	{
			if(i > 0)	{
				cout << endl;
			}
			cout << purchase[i];
		}
		cout << setfill('-') << setw(60) << "\n" << endl;
		cout << setfill(' ');
		for(unsigned int i = 0; i < purchase.size(); i++)	{
			total = total + (purchase[i].qty * purchase[i].price);
		}
		cout << "| ";
		cout.width(11); cout << left << "SubTotal" << "||";
		cout.width(31); cout << right << "|| ";
		cout << "$";
		cout.width(11); cout << left << fixed << setprecision(2) << total << "|";
		cout << setfill('-') << setw(60) << "\n" << endl;
	}
	else	{
		dud.exit();
	}
	cout << "How would you like to pay?(Cash(C), Debit(D)" << endl;
	char choice;
	cin >> choice;
	cout << dud.payment(choice, total);
	cout << "Goodbye!" << endl;
	throw exception();
}

string Machine::payment(char choice, float total)	{
	ostringstream oss;
	oss << choice << fixed << setprecision(2) << total << " lmao" << endl;
	return oss.str();
}

void Machine::exit()	{
	cout << "Goodbye" << endl;
	throw exception();
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
		cout.width(50); cout << left << "Exit" << "|";
		cout << setfill('-') << setw(59) << "\n" << endl;
}

string Machine::decisionTree(unsigned int input)	{
	CinReader reader;
	Machine dud;
	Purchases temp;
	ostringstream oss;
	unsigned int i = input - 1;
	bool loop = true;
	unsigned int amount;
	if(items[i].stock == 0)	{
		 oss << "Sorry we appear to be out of " << items[i].name << endl;
		 return oss.str();
	}
	while(loop == true)	{
		cout << "How many would you like?(1 - " << items[i].stock << ")(0 to exit)" << endl;
		amount = reader.readInt(0, 25);
		if(amount <= items[i].stock)	{
			loop = false;
		}
		else	{
			cout << "Sorry but we don't have enough of the item that you've selected." << endl;
		}
	}
	if(amount == 0)	{
		if(!purchase.empty())	{
			dud.finalizePurchase();
		}
		else {
			dud.exit();
		}
	}
	cout << endl;
	if(items[i].stock > 0)	{
		oss << amount << " "<< items[i].name << " at "
			<< '$' << fixed << setprecision(2) << items[i].price << " ea"
			<< " has been added to your cart." << endl;
		items[i].stock = items[i].stock - amount;
		addPurchase(i, amount);
	}
	else if(items[i].stock == 0)	{
		oss << "Sorry we appear to be out of " << items[i].name << endl;
	}
	return oss.str();
}

unsigned int Machine::printCart(unsigned int counter){
	//ask boyd if you can double overload an operator for the same struct
	Machine dud;
	CinReader reader;
	cout << setfill(' ') << left << "|Cart: ";
	cout.width(15); cout << left << "Item" << "|| ";
	cout.width(14); cout << left << "Price" << "|| ";
	cout.width(15); cout << left << "Qty" << "|";
	cout << setfill('-') << setw(59) << "\n";
	cout << setfill(' ') << setw(1) << "\n";
	for(unsigned int i = 0; i < purchase.size(); i++)	{
		if(i > 0)	{
			cout << endl;
		}
		cout << setfill('-') << setw(7) << right << " ";
		cout << setfill(' ');
		cout.width(15); cout << left << purchase[i].name << right << "|| ";
		cout << "$";
		cout.width(13); cout << left << fixed << setprecision(2) << purchase[i].price << "|| ";
		cout.width(15); cout << left << purchase[i].qty << "|";
	}
	cout << setfill('-') << setw(59) << "\n" << endl;
	cout << "Please select the # of item " << counter << " you would like to buy or enter 0 to exit." << endl;
	unsigned int input = reader.readInt(0, 6);
	return input;
}

bool Machine::addPurchase(unsigned int item, unsigned int amount)	{
	Purchases temp;
	temp.name = items[item].name;
	temp.price = items[item].price;
	temp.qty = amount;
	bool found = false;
	int counter = 0;
	for(unsigned int i = 0; i < purchase.size(); i++)	{
		if(items[item].name == purchase[i].name)	{
			found = true;
			break;
		}
		counter++;
	}
	if(found == false)	{
		purchase.push_back(temp);
	}
	else if(found == true)	{
		purchase[counter].qty = purchase[counter].qty + amount;
	}
	return true;
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

void Machine::clearScreen()	{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
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


