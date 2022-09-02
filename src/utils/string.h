#ifndef UTILS_STRING_H
#define UTILS_STRING_H

#include "common/types.h"

size_t strlen(const int8 *str)
{
	size_t i = 0;

	while (str[i]) {
		i++;
	}

	return i;
}

char* strrev(int8 *str)
{
	int8 tmp;
	int8 *src;
	int8 *dest;

	size_t len;

	if (str != NULL) {
		len = strlen(str);

		if (len > 1) {
			src = str;
			dest = src + len - 1;

			while (src < dest) {
				tmp = *src;
				*src++ = *dest;
				*dest-- = tmp;
			}
		}
	}

	return str;
}

void itoa(int32 num, int8 *str)
{
	int32 sign;
	int32 i = 0;

	if ((sign = num) < 0) {
		num = -num;
	}

	do {
		str[i++] = num % 10 + '0';
	} while ((num /= 10) > 0);

	if (sign < 0) {
		str[i++] = '-';
	}

	str = strrev(str);

	str[i] = '\0';
}

int32 atoi(int8 *str)
{
	int32 num = 0;
	int32 factor = 1;

	if (*str == '-') {
		factor = -1;
		str++;
	}

	while ((*str >= '0') && (*str <= '9')) {
		num *= 10;
		num += *str - 48;
		str++;
	}

	return factor * num;
}

#endif
