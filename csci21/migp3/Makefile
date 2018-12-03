CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

project3.exe: template.hpp main.cpp
	$(CC) $(CPP_FLAGS) template.hpp main.cpp -o main.exe

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
