#include "keyboard/keyboard.h"

#include "vga/vga.h"
#include "common/io.h"

/*
uint8 inb(uint16 port)
{
	uint8 ret;

	asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));

	return ret;
}


void outb(uint16 port, uint8 data)
{
	asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}
*/

char get_input_keycode()
{
	char code = 0;

	while ((code = inb(KEYBOARD_PORT)) != 0) {
		if (code > 0) {
			return code;
		}
	}

	return code;
}


void wait_for_io(uint32 timer_count)
{
	while (1) {
		asm volatile("nop");

		timer_count--;

		if (timer_count <= 0)
			break;
		}
}


void sleep(uint32 timer_count)
{
	wait_for_io(timer_count);
}


int8 get_ascii_char(int8 ch)
{
	switch (ch) {
	case KEY_A: return 'a';
	case KEY_B: return 'b';
	case KEY_C: return 'c';
	case KEY_D: return 'd';
	case KEY_E: return 'e';
	case KEY_F: return 'f';
	case KEY_G: return 'g';
	case KEY_H: return 'h';
	case KEY_I: return 'i';
	case KEY_J: return 'j';
	case KEY_K: return 'k';
	case KEY_L: return 'l';
	case KEY_M: return 'm';
	case KEY_N: return 'n';
	case KEY_O: return 'o';
	case KEY_P: return 'p';
	case KEY_Q: return 'q';
	case KEY_R: return 'r';
	case KEY_S: return 's';
	case KEY_T: return 't';
	case KEY_U: return 'u';
	case KEY_V: return 'v';
	case KEY_W: return 'w';
	case KEY_X: return 'x';
	case KEY_Y: return 'y';
	case KEY_Z: return 'z';

	case KEY_0: return '0';
	case KEY_1: return '1';
	case KEY_2: return '2';
	case KEY_3: return '3';
	case KEY_4: return '4';
	case KEY_5: return '5';
	case KEY_6: return '6';
	case KEY_7: return '7';
	case KEY_8: return '8';
	case KEY_9: return '9';

	case KEY_MINUS: return '-';
	case KEY_EQUAL: return '=';
	case KEY_SBL: return '[';
	case KEY_SBR: return ']';
	case KEY_SEMI: return ';';
	case KEY_BSLASH: return '\\';
	case KEY_FSLASH: return '/';
	case KEY_COMMA: return ',';
	case KEY_DOT: return '.';

	default: return 0;
	}
}

void test_input()
{
	char ch = 0;
	char keycode = 0;

	do {
		keycode = get_input_keycode();

		if (keycode == KEY_ENTER) {
			vga_nl();
		} else {
			ch = get_ascii_char(keycode);
			vga_putc(ch);
		}

    		sleep(0x02FFFFFF);
	} while (ch > 0);
}
