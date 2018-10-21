
//Author		: Juan Palos-Nava
//Filename		: project2.cpp
//Description	: Starts the program

#include "machine.h"

int main()	{
	try	{
		Machine begin;
		//function call to start program
		begin.display();
	}
	//catches exception that is thrown so program can quit
	catch(const exception&)	{
		return EXIT_SUCCESS;
	}
return 0;
}
