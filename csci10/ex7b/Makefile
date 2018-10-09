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

c_program.exe: ex7b.c
	$(CC) ex7b.c -o c_program.exe
	
class_prgm.exe: oct3notes.obj
	$(CO) oct3notes.obj -o class_prgm.exe
	
oct3notes.obj: oct3notes.asm
	nasm -f $(FORMAT) oct3notes.asm -o oct3notes.obj

asm_program.exe: ex7b.obj
	$(CO) ex7b.obj -o asm_program.exe

ex7b.obj: ex7b.asm
	nasm -f $(FORMAT) ex7b.asm -o ex7b.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
