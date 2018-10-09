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

# uncomment for Windows (make sure MINGW is installed!)
CC = gcc
CO = $(CC)
FORMAT = win32#
#RM = del # cmd.exe
RM = rm -f # PowerShell

c_program.exe: ex1b.c
	$(CC) ex1b.c -o c_program.exe

asm_program.exe: ex1b.obj
	$(CO) ex1b.obj -o asm_program.exe

ex1b.obj: ex1b.asm
	nasm -f $(FORMAT) ex1b.asm -o ex1b.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe