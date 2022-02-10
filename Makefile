SHELL := /bin/bash
CC = i386-elf-gcc
ASM = nasm -f elf32
LINKER = i386-elf-ld

.PHONY: image kernel emulate emulate-iso clean

image:
	@echo "Trying to build an ISO file"
	make kernel
	cp ./build/kernel/kernel.bin ./build/iso/boot/iso/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o ./build/iso/boot/iso/kernel.iso ./build/iso

kernel:
	@echo "Trying to build Kernel"
	@echo "Make sure all the Dependencies are installed!"
	make clean
	nasm -f elf32 ./kernel/header.asm -o ./build/files/header.o
	nasm -f elf32 ./kernel/kernel.asm -o ./build/files/k-asm.o
	gcc -m32 -c ./kernel/kernel.c -o ./build/files/k-c.o
	ld -m elf_i386 -T ./kernel/linker.ld -o ./build/kernel/kernel.bin ./build/files/header.o ./build/files/k-asm.o ./build/files/k-c.o

emulate:
	@echo "If you installed QEMU it should be running now"
	qemu-system-i386 -kernel ./build/kernel/kernel.bin

emulate-iso:
	@echo "If you installed QEMU it should be running now"
	qemu-system-i386 -cdrom ./build/iso/boot/iso/kernel.iso

clean:
	rm -rvf ./build/files/*
	rm -rvf ./build/kernel/*
	rm -rvf ./build/iso/boot/iso/*
	@echo "All files removed!"