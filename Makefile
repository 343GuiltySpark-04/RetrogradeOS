 # Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler
# rule, as we use nasm instead of GNU as.



all: build asm link test

clean:
	-rm src/*.o src/*.bin


link:
	i686-elf-gcc -T src/linker.ld -o src/guidance.bin -ffreestanding -O2 -nostdlib src/boot.o src/kernel.o -lgcc


asm:
	i686-elf-as src/boot.s -o src/boot.o $<


build:
	i686-elf-gcc -c src/kernel.c -o src/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra


test:
	./test.sh
