SHELL := /bin/bash
CC = i386-elf-gcc
ASM = nasm -f elf32
LINKER = i386-elf-ld

#image:\
	@echo "Not working now :/"

#kernel:\
	@echo "Trying to build Kernel"\
	@echo "Make sure all the Dependencies are installed!"\
	cd ../kernel\
	nasm -f elf32 kernel.asm -o k-asm.o\
	gcc -m32 -c kernel.c -o k-c.o\
	ld -m elf_i386 -T linker.ld -o kernel k-asm.o k-c.o

#emulate:\
	@echo "If you installed QEMU it should be running now"\
	qemu-system-i386 -kernel ../kernel/kernel

#clean:\
	cd ../kernel\
	rm -rvf *.o\
	@echo "All object files removed!"