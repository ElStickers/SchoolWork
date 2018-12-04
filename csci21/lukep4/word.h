#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using std::string;
using std::ostream;

class Word{ 
	public:
		Word();
		Word(string newWord);
		virtual ~Word();
		void setWord(string newWord);
		string getWord() const; 
		unsigned int getCount() const; 
		void incrementCount();
		bool operator == (const Word& word);
		bool operator > (const Word& word);
		bool operator <(const Word& otherWord);
		friend ostream& operator<<(ostream& outs, const Word& p);
	
	private:
		unsigned int count; 
		string word;
		
		string upper(string s){
			transform(s.begin(), s.end(), s.begin(),::toupper);
			return s;
		}	
};

