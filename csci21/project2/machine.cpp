// Project 2 -- vending machine
// Class		: CSCI 21 TTH
// File			: machine.cpp
// Programmer	: Juan L Palos-Nava
// Description	: Contains function implementations for class Machine

#include "machine.h"
#include "CinReader.cpp"

//grabs and retuns size of purchase vector
unsigned int Machine::purchaseSize()	{
	return purchase.size();
}

//loads ascii art in from file and outputs
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

//displays MENU
void Machine::display()	{
	CinReader reader;
	Machine dud;
	unsigned int count = 1;
	unsigned int empty_check = 0;
	dud.load("vending_machine_items.csv");
	bool run = true;
	unsigned int input = 0;
	//main loop that keeps program running until user decides to exit or pays
	while(run == true)	{
		//checks to see if vending machine is out of stock
		for(unsigned int i = 0; i < dud.items.size(); i++)	{
			if(dud.items[i].stock == 0)	{
				empty_check++;
			}
		}
		//if vedning machine is out of stock will jump to checkout
		if(empty_check == 7)	{
			cout << "Wow! You've bought all my stock!" << endl;
			cout << "Press enter to checkout." << endl;
			cin.ignore();
			dud.finalizePurchase();
		}
		dud.clearScreen();
		//prints menu
		dud.printMenu(count);
		if(count == 1)	{
			input = reader.readInt(0, dud.items.size());
			count++;
		}
		//if count is bigger than one will printCart()
		else if(count > 1)	{
			input = dud.printCart();
		}
		//checks input to make sure its within range of vector
		if(input > 0 && input <= dud.items.size())	{
			cout << dud.decisionTree(input) << endl;
		}
		//jumps to checkout if input is 0
		else if(input == 0)	{
			dud.finalizePurchase();
		}
		bool tryAgain = false;
		//loop to ask user if they would like to try again
		while(tryAgain == false)	{
			cout << "Would you like to select another item?(y/n)" << endl;
			char choice;
			choice = reader.readChar("ny");
			if(toupper(choice) == 'Y')	{
				tryAgain = true;
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
	//loop to print out all items
	while(i < items.size())	{
		cout << items[i];
		if(i < items.size()-1)	{
			cout << endl;
		}
		i++;
	}
	//prints line of '-' to make a nice menu
	cout << setfill('-') << setw(59) << "\n" << endl;
	dud.bottomLine();
	if(counter == 1)	{
		cout << "Please enter the number of item you would like to buy or 0 to exit." << endl;
	}
}

void Machine::finalizePurchase()	{
	CinReader reader;
	Machine dud;
	dud.clearScreen();
	dud.welcome();
	float total = 0;
	if(!purchase.empty())	{
		//lines 115 - 123 are for cart display setup
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
		//loop to print out all of purchase vector
		for(unsigned int i = 0; i < purchase.size(); i++)	{
			if(i > 0)	{
				cout << endl;
			}
			cout << purchase[i];
		}
		//more menu display lines
		cout << setfill('-') << setw(60) << "\n" << endl;
		cout << setfill(' ');
		//calculates the total amount due by looping through vector and multiplying
		//the amount of items purchased to its price
		for(unsigned int i = 0; i < purchase.size(); i++)	{
			total = total + (purchase[i].qty * purchase[i].price);
		}
		//lines 141-146 more display setup prints
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
	cout << dud.payment(total);
	dud.exit();
	throw exception();
}

string Machine::payment(float total)	{
	CinReader reader;
	Machine dud;
	ostringstream oss;
	unsigned int due;
	cout << "Please enter the amount of money you would like to pay with.(max $100)" << endl;
	due = (total*100);
	bool loop = true;;
	unsigned int payment;
	//loop that runs until @param payment is bigger than @param due
	while(loop == true)	{
		cout << "Payment: $";
		payment = reader.readInt(0,100);
		payment = payment*100;
		if(payment < due)	{
			cout << "Sorry that wasn't enough to cover your total" << endl;
		}
		else	{
			loop = false;
		}
	}
	//if @parma payment is more or equal to due will call makeChange()
	if(payment >= due)	{
		due = payment - due;
		oss << dud.makeChange(due);
	}
	return oss.str();
}

string Machine::makeChange(unsigned int change)	{
	ostringstream oss;
	float returned;
	unsigned int tens;
	unsigned int fives;
	unsigned int dollars;
	unsigned int quarters;
	unsigned int dimes;
	unsigned int nickels;
	unsigned int pennies;
	//math to calculate how much of each currency will be given as change
	tens = (change / 1000);
	fives = (change % 1000) / 500;
	dollars = ((change % 1000) % 500) / 100;
	quarters = (((change % 1000) % 500) % 100) / 25;
  dimes = ((((change % 1000) % 500) % 100) % 25) / 10;
  nickels = (((((change % 1000) % 500) % 100) % 25) % 10) / 5;
  pennies = ((((((change % 1000) % 500) % 100) % 25) % 10) % 5);
	returned = (float)change/100;

	oss << "This is your Change:\n"
			<< "Tens: " << tens << "\n"
			<< "Fives: " << fives << "\n"
			<< "Dollars: "	<< dollars	<< "\n"
			<< "Quarters: " << quarters << "\n"
			<< "Dimes: " << dimes << "\n"
			<< "Nickels: " << nickels << "\n"
			<< "Pennies: " << pennies << "\n"
			<< "Total change: $" << returned << endl;
	return oss.str();
}

void Machine::exit()	{
	//simple exit prompt
	cout << setfill('-') << setw(59) << "\n" << endl;
	cout << "Thanks for shopping! See you next time. Goodbye!" << endl;
	throw exception();
}

//top line of menu display print
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

//bottoms line of menu display print
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
	//chekcs stock of item  is equal to 0
	if(items[i].stock == 0)	{
		 oss << "Sorry we appear to be out of " << items[i].name << endl;
		 return oss.str();
	}
	//loop that runs until an amount of items that are available is entered
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
	//if input is 0 will exit or go to checkout depending on purchase vector size
	if(amount == 0)	{
		if(!purchase.empty())	{
			dud.finalizePurchase();
		}
		else {
			dud.exit();
		}
	}
	cout << endl;
	//displays the amount of items that have been added to cart if stock is available
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

unsigned int Machine::printCart(){
	Machine dud;
	CinReader reader;
	//lines 296-301 are for cart display
	cout << setfill(' ') << left << "|Cart: ";
	cout.width(15); cout << left << "Item" << "|| ";
	cout.width(14); cout << left << "Price" << "|| ";
	cout.width(15); cout << left << "Qty" << "|";
	cout << setfill('-') << setw(59) << "\n";
	cout << setfill(' ') << setw(1) << "\n";
	//loops through entire purchase vector and prints it
	for(unsigned int i = 0; i < purchase.size(); i++)	{
		if(i > 0)	{
			cout << endl;
		}
		//lines 307-313 are cart display formating
		cout << setfill('-') << setw(7) << right << " ";
		cout << setfill(' ');
		cout.width(15); cout << left << purchase[i].name << right << "|| ";
		cout << "$";
		cout.width(13); cout << left << fixed << setprecision(2) << purchase[i].price << "|| ";
		cout.width(15); cout << left << purchase[i].qty << "|";
	}
	cout << setfill('-') << setw(59) << "\n" << endl;
	cout << "Please enter the number of the next item you would like to buy or 0 to exit." << endl;
	unsigned int input = reader.readInt(0, items.size());
	return input;
}

bool Machine::addPurchase(unsigned int item, unsigned int amount)	{
	Purchases temp;
	temp.name = items[item].name;
	temp.price = items[item].price;
	temp.qty = amount;
	bool found = false;
	int counter = 0;
	//loops through pruchase vector to see if current item is already inside
	//if it is then only the Quantity will Change
	//this way there are no double entries into the vector
	for(unsigned int i = 0; i < purchase.size(); i++)	{
		if(items[item].name == purchase[i].name)	{
			found = true;
			break;
		}
		counter++;
	}
	//if item hasnt been found will do a fresh push
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
	//opens @param filname
	if(inputfile.is_open()) {
		//takes in lines and passes them to makeItem()
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

//clear screen function found on stack overflow
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

//tokenized @param input and makes a struct
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
