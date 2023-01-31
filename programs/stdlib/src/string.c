#include "string.h"

char tolower(char s1)
{
	if (s1 >= 65 && s1 <= 90) {
		s1 += 32;
	}
	return s1;
}
int strlen(const char *ptr)
{
	const char *ptrc;
	for (ptrc = ptr; *ptrc != '\0'; ++ptrc)
		;
	return ptrc - ptr;
}

int strnlen(const char *s, int count)
{
	const char *sc;

	for (sc = s; count-- && *sc != '\0'; ++sc)
		/* nothing */;
	return sc - s;
}

int strnlen_terminator(const char *str, int max, char terminator)
{
	int i = 0;
	for (i = 0; i < max; i++) {
		if (str[i] == '\0' || str[i] == terminator)
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
char *strncpy(char *s, const char *ct, int n)
{
	char *tmp = s;

	while (n) {
		if ((*tmp = *ct) != 0)
			ct++;
		tmp++;
		n--;
	}
	return s;
}

int istrncmp(const char *cs, const char *ct, int n)
{
	unsigned char c1, c2;
	while (n-- > 0) {
		c1 = (unsigned char)*cs++;
		c2 = (unsigned char)*ct++;
		if (c1 != c2 && tolower(c1) != tolower(c2))
			return c1 - c2;
		if (c1 == '\0')
			return 0;
	}
	return 0;
}

int strncmp(const char *cs, const char *ct, int n)
{
	unsigned char c1, c2;

	/* Checking char per char loop = n times*/
	while (n) {
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			/**if @c2 is bigger than @c1
			 * return -1, else 1  	*/
			return c1 < c2 ? -1 : 1;
		if (!c1)
			break;
		n--;
	}
	return 0;
}

bool isdigit(char c)
{
	return c >= 48 && c <= 57;
}

int tonumericdigit(char c)
{
	return c - 48;
}

char *sp = 0;
char *strtok(char *str, const char *delims)
{
	int i = 0;
	int len = strlen(delims);
	if (!str && !sp)
		return 0;
	if (str && !sp) {
		sp = str;
	}

	char *p_start = sp;
	while (1) {
		for (i = 0; i < len; i++) {
			if (*p_start == delims[i]) {
				p_start++;
				break;
			}
		}
		if (i == len) {
			sp = p_start;
			break;
		}
	}

	if (*sp == '\0') {
		sp = 0;
		return sp;
	}

	//Find end of substring
	while (*sp != '\0') {
		for (i = 0; i < len; i++) {
			if (*sp == delims[i]) {
				*sp = '\0';
				break;
			}
		}
		sp++;
		if (i < len)
			break;
	}
	return p_start;
}