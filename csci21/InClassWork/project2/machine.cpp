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
	dud.prinMenu();
}

void Machine::printMenu()	{
	Machine dud;
	cout << "\n";
	cout << std::setfill('=') << std::setw(22) << "MENU" << std::setfill('=') << std::setw(20) << "\n";
	dud.load("vending_machine_items.csv");
}

bool Machine::load (string filename)
	ifstream inputfile(filename
	if(!items.empty())	{
		items.clear();
	}
	string input_str;
	unsigned int i = 0;
	//checks to make sure file opened correctly
	//if true function continues otherwise
	//returns false
	if(inputfile.is_open()) {
		//loop to grab complete lines from file until no line is available
		while(getline(inputfile, input_str)) {
			//if a pound sign is found it discards those commented lines
			//if it doesnt find a pound sign in continues and passes
			//the string into the makeRating array
			if(input_str.find('#') != std::string::npos)	{
				input_str.clear();
			}
			else	{
				items.push_back(fillMachine(input_str));
			}
		}
		return true;
	}
	else {
		return false;
	}
}

Item Machine::fillMachine(string input) {
	Item dud;
	istringstream iss(input);
	stringstream ss;
	string token;
	//counter to check what variable of the object to store it in
	int i = 0;
	//grabs the line and stores the "tokens" into @param token
	//separates line into tokens with the ',' delimiter
	while (getline(iss, token, ','))	{
		switch(i)	{
			case 0:
				dud.name = token;
				break;
			case 1:
				istringstream iss_2(token);
				iss_2 >> dud.price;
				break;
			case 2:
				ss << token;
				ss >> temp_rating.reviewNumber;
				break;
			default:
				break;				
		}
		i++;
	}
	return temp_rating;
}
