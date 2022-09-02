#ifndef UTILS_MATH_H
#define UTILS_MATH_H

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define DIV(x, y) (x < 0 ? ((x - y + 1) / y) : (x / y))
#define MOD(x, y) ((x % y + y) % y)

#endif
