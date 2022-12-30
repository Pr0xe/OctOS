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
char *strcpy(char *s, const char *ct)
{
	char *tmp = s;

	while ((*s++ = *ct++) != '\0')
		/* nothing*/;

	*s = 0x00;

	return tmp;
}

bool isdigit(char c)
{
	return c >= 48 && c <= 57;
}

int tonumericdigit(char c)
{
	return c - 48;
}