#include "vga/vga.h"
#include "utils/string.h"

uint16* vga_buffer = (uint16*)VGA_ADDRESS;

int16 cursor_x = 0;
int16 cursor_y = 0;

color_t bg_color = COLOR_BLACK;
color_t fg_color = COLOR_WHITE;


/* Returns a correct character code with all attributes */
uint16 vga_entry(unsigned char sym) 
{
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = bg_color;
  ah <<= 4;
  ah |= fg_color;
  ax = ah;
  ax <<= 8;
  al = sym;
  ax |= al;

  return ax;
}


/* Clears the screen */
void vga_clear()
{
    for (int i = 0; i < VGA_SIZE; i++) {
        vga_buffer[i] = vga_entry(0);
    }
}

/* Puts a symbol in the vga buffer by current position */
void vga_putc(char sym)
{
    vga_buffer[cursor_y * 80 + cursor_x] = vga_entry(sym);

    cursor_x++;

    if (cursor_x > 80) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y > 24) {
        cursor_y = 24;
        cursor_x = 75;
    }
}

/* Puts a string in the vga buffer according to the current position */
void vga_puts(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        vga_putc(str[i]);
    }
}


/* Puts a decimal number in the vga buffer */
void vga_putd(int32 dec)
{
    char str[64] = "";

    itoa(dec, str);

    vga_puts(str);
}

/* Changes cursor by increasing X position */
void vga_nl()
{
    cursor_x = 0;
    cursor_y++;

    if (cursor_y > 24) {
        cursor_y = 24;
    }
}

