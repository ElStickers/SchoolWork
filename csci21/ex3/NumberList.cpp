// Exercise 3 -- searching and sorting
// NumberList.cpp

#include "NumberList.h"

unsigned int NumberList::getSize ()
{
	return numbers.size();
}

int NumberList::getNumber (unsigned int index)
{
	if(index < numbers.size())
	{
		return numbers.at(index);
	}
	else
	{
		return 0;
	}
}

bool NumberList::replaceNumber (unsigned int index, int newNumber)
{
	if(index < numbers.size())
	{
		numbers.at(index) = newNumber;
		
		if(numbers.at(index) == newNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool NumberList::load (string filename)
{
	ifstream inputfile;
	
	inputfile.open(filename);
	
	int nextint;
	
	unsigned int i = 0;
	
	for(int &n : numbers)
	{
		n = 0;
	}
	
	if(inputfile.is_open())
	{
		while(inputfile >> nextint && i < numbers.size())
		{
			numbers.at(i++) = nextint;
		}
		
		return true;
	}
	else 
	{
		return false;
	}
}

string NumberList::filter(function<bool (int)>& f)
{
	ostringstream oss;
	
	string output;
	
	for(int n : numbers)
	{
		if(f(n) == true)
		{
			oss << n << ",";
		}
	}
	
	output = oss.str();
	
	output.pop_back();
	
	return output;
}

string NumberList::toString ()
{
	ostringstream oss;
	
	string output;
	
	for(int n : numbers)
	{
		oss << n << ",";
	}
	
	output = oss.str();
	
	output.pop_back();
	
	return output;
	
}

void NumberList::bubbleSort ()
{
	
}

bool NumberList::linearSearch (int value)
{
	for(unsigned int i = 0; i < numbers.size(); i++)
	{
		if(value == numbers.at(i))
		{
			return true;
		}
	}
	
	return false;
}