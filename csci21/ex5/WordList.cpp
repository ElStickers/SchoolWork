// Exercise 5 -- WordList and std::vector
// WordList.cpp

#include "WordList.h"

/*
* Add a word to the list.
* @param word the word to be added
*/
void WordList::addWord (string word)	{
	words.push_back(word);
}

/*
* Remove a word from the list.
* @param word the word to be removed
* @return true if the word is present and removed, else false
*/
bool WordList::removeWord (string word)	{
	bool remove = false;
	for(vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)	{
		if(*iter == word)	{
			words.erase(iter);
			iter--;
			remove = true;
		}
	}
	return remove;
}

/*
* Check to see if a word is in the list.
* @param word the word to check for
* @return true if the word is present, else false
*/
bool WordList::hasWord (string word)	{
	bool has = false;
	for(string n : words)	{
		if(n == word)	{
			has = true;
		}
	}
	return has;
}

/*
* Return the number of words in the list.
* @return an unsigned integer containing the number of words in the list
*/
unsigned int WordList::getWordCount ()	{
	return words.size();
}

/*
* Clear all of the contents of the list.
*/
void WordList::clear ()	{
	words.clear();
}

/*
* Return a string representation of the word list. String will contain
* a numbered list, one word per line.
*
* EXAMPLE:
*
* [1] apple
* [2] grapefruit
* [3] orange
*
* @return a string representation of the word list
*/
string WordList::toString ()	{
	int i = 1;
	ostringstream oss;
	for(string n : words)	{
		oss << "[" << i << "] " << n << "\n";
		i++;
	}
	return oss.str();
}













