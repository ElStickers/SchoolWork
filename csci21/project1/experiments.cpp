#include "Ramenator.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {
	RamenRating dummy;
	string input = "67,Maruchan,Ramen Noodle Soup Lime Chili Shrimp,Pack,USA,2";
	istringstream iss(input);
	string token;
	int i = 1;
	while(getline(iss, token, ',')) {
		if(i == 1)	{
			dummy.reviewNumber = stoul(token);
		}
		else if(i == 2)	{
			dummy.brand = token;
		}
		else if(i == 3)	{
			dummy.variety = token;
		}
		else if(i == 4)	{
			dummy.style = token;
		}
		else if(i == 5)	{
			dummy.country = token;
		}
		else if(i ==6)	{
			dummy.stars = stof(token);
		}
		i++;
	}
	cout << "reviewNumber: " << dummy.reviewNumber << endl;
	cout << "brand: " << dummy.brand << endl;
	cout << "variety: " << dummy.variety << endl;
	cout << "style: " << dummy.style << endl;
	cout << "country: " << dummy.country << endl;
	cout << "stars: " << dummy.stars << endl;
	
	

  return 0;
}
