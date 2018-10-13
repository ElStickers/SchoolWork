//Author:		Juan Palos
//Project 2 -- vending machine
//machine.h
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
//struct and constructor to hold item properties
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
//overloaded << operator
//to allow the ouput of sturct Item
	friend ostream& operator<< (ostream& outs, const Item& r) {
	outs << "|" << r.itemNum << ") || ";
		cout.width(15); cout << left << r.name << "|| ";
		cout << "$";
		cout.width(13); cout << left << fixed << setprecision(2) << r.price << "|| ";
		cout.width(15); cout << left << r.stock << "|";
	return outs;
	}
};

//struct and constructor to hold pruchase properties for purchase history
struct Purchases {
	string name;
	float price;
	unsigned int qty;

	Purchases()	{
		name = "";
		price = 0.00;
		qty = 0;
	}

//overloaded << operator
//to allow the output of the Purchases struct
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

//Machine class header
class Machine	{
	public:
		/*
		 *Gets the size of the purchase vector
		 *@return unsigned integer containing size of
		 *						purchase vector
		 */
		unsigned int purchaseSize();

		/*
		 *Prints ascii art
		 *Loads ascii art from a file and outputs it
		 */
		void welcome();

		/*
		 *Main function
		 *Controls the flow of the program
		 */
		void display();

		/*
		 *prints the menu display
		 *@param counter controls the output of a prompt
		 */
		void printMenu(unsigned int counter);

		/*
		 *Prints out all items in the cart for checkout if the purchase vector is not empty
		 *if empty the exit() is called to exit program
		 *if not empty will call payment()
		 */
		void finalizePurchase();

		/*
		 *Promts user to input Payment
		 *Has a check to make sure user pays enough to @param total
		 *if user input is equal or greater than @param total it will calculate
		 *change due and call makeChange()
		 *places what makeChange() returns and into oss
		 *returns contents of oss
		 */
		string payment(float total);

		/*
		 *@param change holds what is due as change
		 *takes @param change and does arithmetic to display how much of each coin
		 *ie. dollars, quarters, dimes, etc.
		 *will be returned to user
		 *places output oss and return oss contents
		 */
		string makeChange(unsigned int change);

		/*
		 *throws exception so program can stop
		 */
		void exit();

		/*
		 *Prints the topline of the MENU
		 */
		void topLine();

		/*
		 *Prints the bottom line of the menu
		 */
		void bottomLine();

		/*
		 *takes @param input and makes sure the item has Stock
		 *also gives option so select multiples of @param input if available
		 *if purchase vector is not empty will call finalizePurchase()
		 *if it is empty it will call exit()
		 */
		string decisionTree(unsigned int input);

		/*
		 *prints items in your cart after one item has been selected
		 *asks user for their next item choice and returns their input
		 */
		unsigned int printCart();

		/*
		 *Loads in item information from a @param filename
		 *returns true if successfull, false if not
		 */
		bool load(string filename);

		/*
		 *makes customer purchase information into struct
		 *pushes struct into purchases vector
		 */
		bool addPurchase(unsigned int item, unsigned int amount);

		/*
		 *clears the screen
		 */
		void clearScreen();

	private:
		vector<Item>items;
		vector<Purchases>purchase;
		vector<unsigned int>selections;

		/*
		 *takes @param items and makes a strcut
		 *returns struct to be pushed into vector 
		 */
		Item makeItem(string items);
};
