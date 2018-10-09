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

vend.exe: vend.c
	$(CC) vend.c -o vend.exe

asm_vend.exe: asm_vend.obj
	$(CO) asm_vend.obj -o asm_vend.exe

asm_vend.obj: asm_vend.asm
	nasm -f $(FORMAT) asm_vend.asm -o asm_vend.obj

clean:
	$(RM) *.obj

cleanall: clean
	$(RM) *.exe
