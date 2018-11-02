CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

program.exe: dllist.o program.cpp
	$(CC) $(CPP_FLAGS) dllist.o program.cpp -o program.exe

dllist.o: dllist.hpp
	$(CC) $(CPP_FLAGS) -c dllist.hpp -o dllist.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
