CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

CC = c:\mingw\bin\g++
RM = rm -f # PowerShell

project2.exe: project2.o
	$(CC) $(CPP_FLAGS) project2.o -o project2.exe

project2.o: machine.h machine.cpp
	$(CC) $(CPP_FLAGS) -c machine.cpp -o project2.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
