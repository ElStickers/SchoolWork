CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

# uncomment for Windows (make sure MinGW/MSYS are installed!)
CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

unittest.exe: unittest.cpp bstree.hpp
	$(CC) $(CPP_FLAGS) unittest.cpp -o unittest.exe

experiments.exe: experiments.cpp bstree.hpp
	$(CC) $(CPP_FLAGS) experiments.cpp -o experiments.exe

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
