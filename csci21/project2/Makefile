CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

project2.exe: machine.o project2.cpp
	$(CC) $(CPP_FLAGS) machine.o project2.cpp -o project2.exe

machine.o: machine.h machine.cpp
	$(CC) $(CPP_FLAGS) -c machine.cpp -o machine.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
