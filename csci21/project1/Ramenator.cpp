// Project 1 -- ramen ratings database
// Class		: CSCI 21 TTH
// File			: Ramenator.cpp
// Programmer	: Juan L Palos-Nava
// Description	: Contains function implementations for class Ramenator 
// 				  and comparison function implementations of RamenSort

#include "Ramenator.h"

// RamenRating comparison functions -- implementations

//RamenSort functions to allow comparison of struct members
bool compareBrands (RamenRating l, RamenRating r) {
	return (l.brand < r.brand);
}

bool compareVarieties (RamenRating l, RamenRating r) {
	return (l.variety < r.variety);
}

bool compareStyles (RamenRating l, RamenRating r) {
	return (l.style < r.style);
}

bool compareCountries (RamenRating l, RamenRating r) {
	return (l.country < r.country);
}

bool compareStars (RamenRating l, RamenRating r) {
	return (l.stars < r.stars);
}

// Ramenator member functions -- implementations

//Grabs the and the returns the size of the ratings array
unsigned int Ramenator::getSize () {
	return ratings.size();
}

//Grabs and returns the rating at the passed in index
RamenRating Ramenator::getRating (unsigned int index) {
	RamenRating temp_rating;
	//checks to make sure index is withing legit range of array size
	if(index < ratings.size()) {
		return ratings.at(index);
	}
	else {
		return temp_rating;
	}
}

//replaces the rating located at the passed in index with the new 
//passed in rating
bool Ramenator::replaceRating (unsigned int index, RamenRating newRating) {
	//checks to make sure index is withing legit range of array size
	//if index is within range function continues othwerwise return false
	if(index < ratings.size()) {
		ratings.at(index) = newRating;
		//safety check to see if rating was replaced
		// if true we return true otherwise return false
		if(ratings.at(index) == newRating) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

//opens and parses in info from passed in filename string
bool Ramenator::load (string filename) {
	//checks for data/ part of path in filename and removes if found
	if(filename.find("data/") != std::string::npos) {
		filename.erase(0,5);
	}
	ifstream inputfile(filename);
	RamenRating temp_rating;
	//fills entire array with dummy "empty" RamenRating's
	for(RamenRating &n : ratings) {
		n = temp_rating;
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
				ratings.at(i++) = makeRating(input_str); 	
			}
		}
		return true;
	}
	else {
		return false;
	}
}

//function to filter the array and only return matching Ratings in string form
string Ramenator::filter (function<bool (RamenRating)>& f, unsigned int limit) {
	ostringstream oss;
	unsigned int i = 0;
	//a loop to go through and check every entry in the array
	for(RamenRating n : ratings) {
		//if @param limit is zero it returns all ratings that match filter
		if(f(n) == true && limit == 0) {
			oss << n << "\n";
		}
		//if @para limit != 0 it only returns the limit amount of filtered ratings 
		else if(f(n) == true && i <= limit) {
			oss << n << "\n";
			i++;
		}
	}
	return oss.str();
}

//function that sorts the array according to what field is set to
void Ramenator::sortBy (RamenSort field) {
	if(field == RamenSort::BRAND) {
		sort(ratings.begin(), ratings.end(), compareBrands);
	}
	else if(field == RamenSort::VARIETY) {
		sort(ratings.begin(), ratings.end(), compareVarieties);
	}
	else if(field == RamenSort::STYLE) {
		sort(ratings.begin(), ratings.end(), compareStyles);
	}
	else if(field == RamenSort::COUNTRY) {
		 sort(ratings.begin(), ratings.end(), compareCountries);
	}
	else if(field == RamenSort::STARS) {
		sort(ratings.begin(), ratings.end(), compareStars);
	}
}

RamenRating Ramenator::locateFirstMatch (RamenSort field, RamenRating matcher) {
	RamenRating temp_rating;
	if(field == RamenSort::BRAND) {
		for(RamenRating n : ratings) {
			if(matcher.brand == n.brand) {
				return n;
			}
			else {
				return temp_rating;
			}
		}
	}
	else if(field == RamenSort::VARIETY) {
		for(RamenRating n : ratings) {
			if(matcher.variety == n.variety) {
				return n;
			}
			else {
				return temp_rating;
			}
		}
	}
	else if(field == RamenSort::STYLE) {
		for(RamenRating n : ratings) {
			if(matcher.style == n.style) { 
				return n;
			}
			else {
				return temp_rating;
			}
		}
	}
	else if(field == RamenSort::COUNTRY) {
		for(RamenRating n : ratings) {
			if(matcher.country == n.country) {
				return n;
			}
			else {
				return temp_rating;
			}
		}
	}   
	else if(field == RamenSort::STARS) {
		for(RamenRating n : ratings) {
			if(matcher.stars == n.stars) {
				return n;
			}
			else {
				return temp_rating;
			}
		}
	}
	return temp_rating;
}

//function to get ratings begining at the value passed in for @param start 
//and an ending once we reach the value passed in for @param end
//once those ratings are passed into the stringstream returns as string
string Ramenator::toString (unsigned int start, unsigned int end) {
	ostringstream oss;
	while(start <= end) {
		oss << ratings.at(start++) << "\n";
	}
	return oss.str();
}

//function that makes @param input, tokenizes it and puts it 
//into an object of RamenRating struct
RamenRating Ramenator::makeRating (string input) {
	RamenRating temp_rating;
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
				ss << token;
				ss >> temp_rating.reviewNumber;
				break;
			case 1:
				temp_rating.brand = token;
				break;
			case 2:
				temp_rating.variety = token;
				break;
			case 3:
				temp_rating.style = token;
				break;
			case 4:
				temp_rating.country = token;
				break;
			case 5:
				istringstream iss_2(token);
				iss_2 >> temp_rating.stars;
				break;
		}
		i++;
	}
	return temp_rating;
}