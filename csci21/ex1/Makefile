CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

# uncomment for Linux
#CC = g++
#RM = rm -f

# uncomment for Mac OS X
#CC = g++
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
CC = c:\mingw\bin\g++
RM = del # cmd.exe
RM = rm -fo # PowerShell

unittest.exe: ShoppingList.o unittest.cpp
	$(CC) $(CPP_FLAGS) ShoppingList.o unittest.cpp -o unittest.exe

ShoppingList.o: ShoppingList.h ShoppingList.cpp
	$(CC) $(CPP_FLAGS) -c ShoppingList.cpp -o ShoppingList.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe