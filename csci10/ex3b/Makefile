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

c_program.exe: ex3b.c
	$(CC) ex3b.c -o c_program.exe

asm_program.exe: ex3b.obj
	$(CO) ex3b.obj -o asm_program.exe

ex3b.obj: ex3b.asm
	nasm -f $(FORMAT) ex3b.asm -o ex3b.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
