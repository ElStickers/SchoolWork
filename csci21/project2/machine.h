#pragma once

#include "CinReader.h"

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
#include <windows.h>
using std::array;
using std::cin;
using std::cout;
using std::exception;
using std::endl;
using std::fixed;
using std::function;
using std::ifstream;
using std::istringstream;
using std::left;
using std::ostream;
using std::ostringstream;
using std::right;
using std::setfill;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;

struct Item	{
	unsigned int itemNum;
	string name;
	float price;
	unsigned int stock;

	Item()	{
		itemNum = 0;
		name = "";
		price = 0.00;
		stock = 0;
	}

	friend ostream& operator<< (ostream& outs, const Item& r) {
	outs << "|" << r.itemNum << ") || ";
		cout.width(15); cout << left << r.name << "|| ";
		cout << "$";
		cout.width(13); cout << left << fixed << setprecision(2) << r.price << "|| ";
		cout.width(15); cout << left << r.stock << "|";
	return outs;
	}
};

struct Purchases {
	string name;
	float price;
	unsigned int qty;

	Purchases()	{
		name = "";
		price = 0.00;
		qty = 0;
	}

	friend ostream& operator<< (ostream& outs, const Purchases& r) {
	outs << "| ";
			cout.width(11); cout << left << r.name << "|| ";
			cout << "$";
			cout.width(10); cout << left << fixed << setprecision(2) << r.price << "|| ";
			cout.width(13); cout << left << r.qty << "|| ";
			cout << "$";
			cout.width(11); cout << left << fixed << setprecision(2) << r.price * r.qty << "|";;
	return outs;
	}
};

class Machine	{
	public:
		unsigned int purchaseSize();
		void welcome();
		void display();
		void printMenu(unsigned int counter);
		void finalizePurchase();
		string payment(char choice, float total);
		string makeChange(unsigned int change);
		void exit();
		void topLine();
		void bottomLine();
		string decisionTree(unsigned int input);
		unsigned int printCart(unsigned int counter);
		bool load(string filename);
		bool addPurchase(unsigned int item, unsigned int amount);
		void clearScreen();

	private:
		vector<Item>items;
		vector<Purchases>purchase;
		vector<unsigned int>selections;
		Item makeItem(string items);
};
