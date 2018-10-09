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

c_project2.exe: c_project2.c
	$(CC) c_project2.c -o c_project2.exe

asm_project2.exe: asm_project2.obj
	$(CO) asm_project2.obj -o asm_project2.exe

asm_project2.obj: asm_p2.asm
	nasm -f $(FORMAT) asm_p2.asm -o asm_project2.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
