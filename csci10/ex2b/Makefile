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

c_program.exe: ex2b.c
	$(CC) ex2b.c -o c_program.exe

asm_program.exe: ex2b.obj
	$(CO) ex2b.obj -o asm_program.exe

ex2b.obj: ex2b.asm
	nasm -f $(FORMAT) ex2b.asm -o ex2b.obj
	
hello_asm.exe: hello.obj
	$(CO) hello.obj -o hello_asm.exe
	
hello.obj: hello.asm
	nasm -f $(FORMAT) hello.asm -o hello.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
