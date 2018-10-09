//Author		: Juan Palos-Nava
//Filename		: project2.cpp
//Description	:

#include "machine.h"

int main()	{
	try	{
		Machine begin;
		begin.display();
	}
	catch(const exception&)	{
		return EXIT_SUCCESS;
	}
return 0;
}