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
CC = gcc
CO = $(CC)
FORMAT = win32
#RM = del # cmd.exe
RM = rm -f # PowerShell

c_program.exe: list_v1.c
	$(CC) list_v1.c -o c_program.exe

asm_program.exe: list_v1.obj
	$(CO) list_v1.obj -o asm_program.exe

list_v1.obj: list_v1.asm
	nasm -f $(FORMAT) list_v1.asm -o list_v1.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
