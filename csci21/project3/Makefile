CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

CC = c:\mingw\bin\g++
#RM = del # cmd.exe
RM = rm -f # PowerShell

project3.exe: driver.o project3.cpp
	$(CC) $(CPP_FLAGS) driver.o project3.cpp -o project3.exe

driver.o: driver.h driver.cpp
	$(CC) $(CPP_FLAGS) -c driver.cpp -o driver.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
