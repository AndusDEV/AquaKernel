SHELL := /bin/bash
CC = i386-elf-gcc
ASM = nasm -f elf32
LINKER = i386-elf-ld

.PHONY: image kernel emulate clean

image:
	@echo "Not working now :/"

kernel:
	@echo "Trying to build Kernel"
	@echo "Make sure all the Dependencies are installed!"
	nasm -f elf32 ./kernel/kernel.asm -o ./build/files/k-asm.o
	gcc -m32 -c ./kernel/kernel.c -o ./build/files/k-c.o
	ld -m elf_i386 -T ./kernel/linker.ld -o ./build/files/kernel ./build/files/k-asm.o ./build/files/k-c.o

emulate:
	@echo "If you installed QEMU it should be running now"
	qemu-system-i386 -kernel ./build/files/kernel

clean:
	rm -rvf ./build/files/*
	@echo "All files removed!"