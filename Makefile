
.PHONY: all clean run

all: bin/kernel.iso

clean:
	rm -f bin/* build/* isodir/boot/kernel.bin

run: bin/kernel.iso
	qemu-system-x86_64 -cdrom $^

build/boot.o: src/boot.S
	as --32 $^ -o $@
	
build/kernel.o: src/kernel.c
	gcc -m32 -c $^ -o $@ -ffreestanding -O2 -Wall -Wextra
	
isodir/boot/kernel.bin: linker.ld build/kernel.o build/boot.o
	ld -m elf_i386 -T $^ -o $@
	
bin/kernel.iso: isodir/boot/kernel.bin isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir
