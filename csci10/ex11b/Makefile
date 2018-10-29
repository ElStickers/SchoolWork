# uncomment for Linux
#CC = gcc
#CO = gcc -m32
#FORMAT = elf32
#RM = rm -f

# uncomment for Mac OS X
#CC = gcc
#CO = ld -lc -macosx_version_min 10.13
#FORMAT = macho32
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
CC = c:\mingw\bin\gcc
CO = $(CC)
FORMAT = win32
#RM = del # cmd.exe
RM = rm -fo # PowerShell

c_program.exe: ex11b.c
	$(CC) ex11b.c -o c_program.exe

asm_program.exe: ex11b.obj
	$(CO) ex11b.obj -o asm_program.exe

ex11b.obj: ex11b.asm
	nasm -f $(FORMAT) ex11b.asm -o ex11b.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
