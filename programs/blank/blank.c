#include "octos.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	print("Hello this is test\n");

	print(itoa(8763));

	putchar('Z');

	void *ptr = malloc(512);
	free(ptr);
	if (ptr) {
	}
	while (1) {
		if (getkey() != 0) {
			print("key was pressed\n");
		}
	}
	return 0;
}