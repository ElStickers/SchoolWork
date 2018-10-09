// Project 1 -- ramen ratings database
// Ramenator.cpp
//Author	: Juan Palos

#include "Ramenator.h"

// RamenRating comparison functions -- implementations
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
unsigned int Ramenator::getSize () {
	return ratings.size();
}

RamenRating Ramenator::getRating (unsigned int index) {
	RamenRating temp_rating;
	if(index < ratings.size()) {
		return ratings.at(index);
	}
	else {
		return temp_rating;
	}
}

bool Ramenator::replaceRating (unsigned int index, RamenRating newRating) {
	if(index < ratings.size()) {
		ratings.at(index) = newRating;
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

bool Ramenator::load (string filename) {
	if(filename.find("data/") != std::string::npos) {
		filename.erase(0,5);
	}
	ifstream inputfile(filename);
	RamenRating temp_rating;
	for(RamenRating &n : ratings) {
		n = temp_rating;
	}
	string input_str;
	unsigned int i = 0;
	if(inputfile.is_open()) {
		while(getline(inputfile, input_str)) {
			if(input_str.find('#') != std::string::npos)	{
				input_str.clear();
			}
			else	{
				ratings.at(i++) = makeRating(input_str); 	
			}
		}
		inputfile.close();
		return true;
	}
	else {
		return false;
	}
}


string Ramenator::filter (function<bool (RamenRating)>& f, unsigned int limit) {
	ostringstream oss;
	unsigned int i = 0;
	for(RamenRating n : ratings) {
		if(f(n) == true && limit == 0) {
			oss << n << "\n";
		}
		else if(f(n) == true && i <= limit) {
			oss << n << "\n";
			i++;
		}
	}
	return oss.str();
}

void Ramenator::sortBy (RamenSort field) {
	if(field == RamenSort::BRAND) {
		sort(ratings.begin(), ratings.end(), compar eBrands);
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

string Ramenator::toString (unsigned int start, unsigned int end) {
	ostringstream oss;
	while(start <= end) {
		oss << ratings.at(start++) << "\n";
	}
	return oss.str();
}

RamenRating Ramenator::makeRating (string input) {
	RamenRating temp_rating;
	stringstream ss(input);
	stringstream ss_2;
	string token;
	int i = 0;
	while (getline(ss, token, ','))	{
		switch(i)	{
			case 0:
				ss_2 << token;
				ss_2 >> temp_rating.reviewNumber;
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
				istringstream iss(token);
				iss >> temp_rating.stars;
				break;
		}
		i++;
	}
	return temp_rating;
}
