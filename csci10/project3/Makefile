# uncomment for Linux
#CC = gcc
#CO = gcc -m32
#FORMAT = elf32
#RM = rm -f

# uncomment for Mac OS X
#CC = gcc
#CO = gcc -m32 -fno-pie
#FORMAT = macho32
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
CC = c:\mingw\bin\gcc
CO = $(CC)
FORMAT = win32
#RM = del # cmd.exe
RM = rm -f # PowerShell

project3.exe: project3.obj
	$(CO) project3.obj -o project3.exe

project3.obj: project3.asm
	nasm -f $(FORMAT) project3.asm -o project3.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
