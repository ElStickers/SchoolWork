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
RM = rm -fo # PowerShell

unittest.exe: NumberList.o unittest.cpp
	$(CC) $(CPP_FLAGS) NumberList.o unittest.cpp -o unittest.exe

experiments.exe: NumberList.o experiments.cpp
	$(CC) $(CPP_FLAGS) NumberList.o experiments.cpp -o experiments.exe

NumberList.o: NumberList.h NumberList.cpp
	$(CC) $(CPP_FLAGS) -c NumberList.cpp -o NumberList.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
