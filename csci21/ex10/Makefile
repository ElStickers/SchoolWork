CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

# uncomment for Linux
#CC = g++
#RM = rm -f

# uncomment for Mac OS X
#CC = g++
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
#CC = c:\mingw\bin\g++
#RM = del # cmd.exe
#RM = rm -fo # PowerShell

unittest.exe: SList.o unittest.cpp
	$(CC) $(CPP_FLAGS) SList.o unittest.cpp -o unittest.exe

experiments.exe: SList.o experiments.cpp
	$(CC) $(CPP_FLAGS) SList.o experiments.cpp -o experiments.exe

SList.o: SList.h SList.cpp
	$(CC) $(CPP_FLAGS) -c SList.cpp -o SList.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
