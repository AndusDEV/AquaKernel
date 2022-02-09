cd ../kernel
nasm -f elf32 kernel.asm -o k-asm.o
gcc -m32 -c kernel.c -o k-c.o
ld -m elf_i386 -T linker.ld -o kernel k-asm.o k-c.o
