#include "string.h"

int strlen(const char *ptr)
{
	const char *ptrc;
	for (ptrc = ptr; *ptrc != '\0'; ++ptrc)
		;
	return ptrc - ptr;
}

int strnlen(const char *ptr, int max)
{
	int i = 0;
	for (i = 0; i < max; i++) {
		if (ptr[i] == 0)
			break;
	}
	return i;
}

bool isdigit(char c)
{
	return c >= 48 && c <= 57;
}

int tonumericdigit(char c)
{
	return c - 48;
}