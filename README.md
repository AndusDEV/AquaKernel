# Aqua Kernel

## Building Instructions:
### With build Script:
Go to `Using Scripts` 
### Manually:
`$ cd kernel`
`$ nasm -f elf32 kernel.asm -o k-asm.o`</br>
`$ gcc -m32 -c kernel.c -o k-c.o`</br>
`$ ld -m elf_i386 -T linker.ld -o kernel k-asm.o k-c.o`

## Using Scripts:
### Cleaning Script:
`$ cd scripts`</br>
`$ chmod 755 cleanup.sh`</br>
`$ ./cleanup.sh`
### Building Script (32-bit):
`$ cd scripts`</br>
`$ chmod 755 build-32.sh`</br>
`$ ./build-32.sh`

## Running:
### Qemu:
`$ qemu-system-i386 -kernel kernel`
### Real Hardware:
(Not planned for now)
Flash to USB with for e.x. <a href="https://www.balena.io/etcher/">BalenaEtcher</a>