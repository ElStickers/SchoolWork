// Exercise 2 -- std::array loaded from file
// NumberList.cpp

#include "NumberList.h"


unsigned int NumberList::getSize ()
{
	return numbers.size();
}

int NumberList::getNumber (unsigned int index)
{
	if(numbers.size() > index)
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
	ifstream myfile;
	
	myfile.open(filename);
	
	int nextint;
	
	unsigned int i = 0;
	
	for(int &n : numbers)
	{
		n = 0;
	}
	
	if(myfile.is_open())
	{
		while(myfile >> nextint && i < numbers.size())
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
		oss << n << ",";	
	}
	
	output = oss.str();
	
	output.pop_back();
	
	return output;
}


