// Exercise 1 -- ShoppingList and std::array
// ShoppingList.cpp

#include "ShoppingList.h"

unsigned int ShoppingList::getSize ()
{
	unsigned int size = 100;
	
	size = items.size();
	
	return size;
}

string ShoppingList::getItem (unsigned int index)
{
	string item = "";
	if(index < items.size())
	{
		item = items.at(index);
	}
	else
	{
		item = "";
		}
	return item;
}

bool ShoppingList::replaceItem (unsigned int index, string newItem)
{
	bool done;
	if(index < items.size())
	{
		items.at(index) = newItem;
		done = true;
	}
	else 
	{
		done = false;
	}
	
	
	return done;
}

string ShoppingList::toString ()
{
	string list;
	
	ostringstream oss;
	
	int size =  items.size();
	
	for(int i = 0; i < size - 1; i++)
	{
		oss << items.at(i) << ",";
	}
	oss << items.at(9);
	
	list = oss.str();
	
	return list;
}