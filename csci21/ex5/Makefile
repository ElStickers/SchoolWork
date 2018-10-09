CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

# uncomment for Linux
#CC = g++
#RM = rm -f

# uncomment for Mac OS X
#CC = g++
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

unittest.exe: WordList.o unittest.cpp
	$(CC) $(CPP_FLAGS) WordList.o unittest.cpp -o unittest.exe

experiments.exe: WordList.o experiments.cpp
	$(CC) $(CPP_FLAGS) WordList.o experiments.cpp -o experiments.exe

WordList.o: WordList.h WordList.cpp
	$(CC) $(CPP_FLAGS) -c WordList.cpp -o WordList.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
