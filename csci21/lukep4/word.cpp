#include "word.h"



		/*
		 * Default constructor.
		 * Initializes count to 0.
		 */
Word::Word()//just like pc16
	:count(0){}

		/*
		 * Overloaded constructor.
		 * Initializes word to newWord and count to 1. Uses upper to ensure 
		 * words is all uppercase.
		 */
Word::Word(string newWord)
	:word(upper(newWord)),count(1) {}

		/*
		 * Destructor.
		 * Included for completeness. Does nothing.
		 */
Word::~Word(){}	
		/*
		 * Set this Word object's word.
		 * @param newWord a new value for this Word object's word. Uses upper 
		 * to ensure words is all uppercase.
		 */

void Word::setWord(string newWord){
	word = (upper(newWord));
}
		/*
		 * Get this Word object's word.
		 * @return the value of this Word object's word.
		 */

string Word::getWord() const{
	return word;
}
		/*
		 * Get this Word object's count.
		 * @return this Word object's count.
		 */

unsigned int Word::getCount() const { 
	return count;
}
		/*
		 * Increment this Word object's count (i.e., increase count by 1).
		 */
void Word::incrementCount(){
	count++;
	
}

		/*
		 * Compare this Word object with another Word object to see if their word values 
		 */
bool Word::operator == (const Word& word) {
	return (word.getWord() == this->getWord());
}
		/*
		 * Compare this Word object with another Word object to see if this Word object's 
		 *
		 */
bool Word::operator > (const Word& word) {
	 return (word.getWord() > this->getWord());
}
		/*
		 * Compare this Word object with another Word object to see if this Word object's 
		 *
		 */
bool Word::operator <(const Word& otherWord){
	return (otherWord.getWord() < this->getWord());
}
		/*
		 * Print this Word object on an output stream.
		 * Displays the word value, followed by a space, followed by the count..
 		 *
 		 * EXAMPLE: "APPLE 2"
 		 *
		 * @return the output stream with this Word object's data inserted
		 */

ostream& operator<<(ostream& outs, const Word& src){
	outs << src.getWord() << " " << src.getCount();
	return outs;
}	

