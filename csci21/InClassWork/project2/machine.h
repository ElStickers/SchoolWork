#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::ostringstream;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;

struct Item	{
	string name;
	float price;
	unsigned int stock;

	Item()	{
		name = "";
		price = 0.00;
		stock = 0;
	}

	friend ostream& operator<< (ostream& outs, const Item& r) {
	outs << r.name << ':'
			 << r.price << ':'
			 << r.stock;
	return outs;
	}
};

class Machine{
	public:
		void welcome();
		void printMenu();
		bool load();

	private:
		vector<Item>items;
		Item fillMachine();
};
