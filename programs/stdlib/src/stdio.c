#include "stdio.h"
#include "octos.h"

int putchar(int c)
{
	octos_putchar((char)c);
	return 0;
}