 # Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler
# rule, as we use nasm instead of GNU as.

SOURCES=src/boot.o src/main.o
SOURCE_ASM=src/boot.s
SOURCES_GCC=src/main.c

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -march=i386
LDFLAGS=-Tlink.ld
ASFLAGS=-felf32

all: build asm link $(SOURCES)

clean:
	-rm src/*.o kernel


link:
	ld $(LDFLAGS) -o kernel $(SOURCES)


asm:
	nasm $(ASFLAGS) $(SOURCE_ASM) $<

debug:
	ls

build:
	gcc -c $(CFLAGS) -o src/main.o $(SOURCES_GCC)
