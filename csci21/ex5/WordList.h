// Exercise 5 -- WordList and std::vector
// WordList.h

#include <string>
#include <sstream>
#include <vector>
using std::ostringstream;
using std::string;
using std::vector;

class WordList {
	public:

		/*
		 * Add a word to the list.
		 * @param word the word to be added
		 */
		void addWord (string word);

		/*
		 * Remove a word from the list.
		 * @param word the word to be removed
		 * @return true if the word is present and removed, else false
		 */
		bool removeWord (string word);

		/*
		 * Check to see if a word is in the list.
		 * @param word the word to check for
		 * @return true if the word is present, else false
		 */
		bool hasWord (string word);

		/*
		 * Return the number of words in the list.
		 * @return an unsigned integer containing the number of words in the list
		 */
		unsigned int getWordCount ();

		/*
		 * Clear all of the contents of the list.
		 */
		void clear ();

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
		string toString ();

	private:
		vector<string> words;
};
