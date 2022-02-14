# Aqua Kernel
Version 0.0.1

## Building Instructions:
### Requirements:
- NASM
- gcc
- GRUB
- Make (For automatization)
- Qemu (For running as VM)

### Manually:
`$ cd kernel`</br>
`$ nasm -f elf32 ./kernel/kernel.asm -o ./build/files/k-asm.o`</br>
`$ nasm -f elf32 ./kernel/header.asm -o ./build/files/header.o`</br>
`$ gcc -m32 -c ./kernel/kernel.c -o ./build/files/k-c.o`</br>
`$ ld -m elf_i386 -T ./kernel/linker.ld -o ./build/kernel/kernel.bin ./build/files/header.o ./build/files/k-asm.o ./build/files/k-c.o`

### With Make:
(You must be in Root Directory)

Build:</br>
- Kernel: `$ make kernel`
- Image (ISO): `$ make image`

Clean: `$ make clean`

Emulate: `$ make emulate`

### With build Script:
Go to <a href="#using-scripts">Using Scripts</a>

## Using Scripts:
### Cleaning Script:
`$ cd scripts`</br>
`$ chmod 755 cleanup.sh` (only once)</br>
`$ ./cleanup.sh`
### Building Script (32-bit):
`$ cd scripts`</br>
`$ chmod 755 build-32.sh` (only once)</br>
`$ ./build-32.sh`

## Running:
### Qemu:
#### Kernel:
`$ qemu-system-i386 -kernel ./build/files/kernel.bin` or `$ make emulate`
#### ISO:
`$ qemu-system-i386 -cdrom ./build/files/kernel.iso` or `$ make emulate-iso`
### Real Hardware:
(Not planned for now)
Flash to USB with for e.x. <a href="https://www.balena.io/etcher/">BalenaEtcher</a>
