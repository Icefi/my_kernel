#ifndef MONITOR_H
#define MONITOR_H

#include "common/common.h"

#define VGA_SIZE 2200
#define VGA_ADDRESS 0xB8000

typedef uint8 color_t;

#define COLOR_BLACK     0
#define COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_CYAN      3
#define COLOR_RED       4
#define COLOR_FUCHSINE  5
#define COLOR_BROWN     6
#define COLOR_WHITE     7

#define COLOR_LIGHT_BLACK     8
#define COLOR_LIGHT_BLUE      9
#define COLOR_LIGHT_GREEN     10
#define COLOR_LIGHT_CYAN      11
#define COLOR_LIGHT_RED       12
#define COLOR_LIGHT_FUCHSINE  13
#define COLOR_LIGHT_BROWN     14
#define COLOR_LIGHT_WHITE     15

void vga_clear();

void vga_putc(char sym);
void vga_puts(char *str);
void vga_putd(int32 dec);
void vga_nl();

#endif
