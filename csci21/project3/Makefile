CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

project3.exe: DLList.hpp project3.cpp
	$(CC) $(CPP_FLAGS) DLList.hpp project3.cpp -o project3.exe

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
