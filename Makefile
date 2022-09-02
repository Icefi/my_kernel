CC = gcc -Wall -Wextra -O2
ASM = as
CFLAGS = -m32 -ffreestanding
IFLAGS = -I src
ASFLAGS = --32

.PHONY: all clean run

OBJS_BOOT = build/boot/loader.o
OBJS_COMMON = build/common/io.o
OBJS_VGA = build/vga/vga.o
OBJS_KEYBOARD = build/keyboard/keyboard.o

OBJS = $(OBJS_BOOT) $(OBJS_COMMON) $(OBJS_VGA) $(OBJS_KEYBOARD) build/kmain.o

all: bin/kernel.iso

clean:
	rm -f bin/* $(OBJ) isodir/boot/kernel.bin

run: bin/kernel.iso
	qemu-system-x86_64 -cdrom $^


# BOOT #

build/boot/loader.o: src/boot/loader.S
	$(ASM) $(ASFLAGS) $^ -o $@


# COMMON #

build/common/io.o: src/common/io.c src/common/io.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IFLAGS)



# VGA #

build/vga/vga.o: src/vga/vga.c src/vga/vga.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IFLAGS)


# KEYBOARD #

build/keyboard/keyboard.o: src/keyboard/keyboard.c src/keyboard/keyboard.h
	$(CC) -c $< -o $@ $(CFLAGS) $(IFLAGS)

# KMAIN #

build/kmain.o: src/kmain.c
	$(CC) -c $^ -o $@ $(CFLAGS) $(IFLAGS)


# KERNEL BINARY #

isodir/boot/kernel.bin: $(OBJS)
	ld -m elf_i386 -T linker.ld $^ -o $@ -nostdlib


# KERNEL ISO #

bin/kernel.iso: isodir/boot/kernel.bin isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir
