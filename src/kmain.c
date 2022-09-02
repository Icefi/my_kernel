#include "vga/vga.h"
#include "keyboard/keyboard.h"

void kmain()
{
	vga_clear();

	vga_puts("Welcome to the kernel, type below.");
	vga_nl();
	vga_puts("kernel $ ");

	test_input();
}
