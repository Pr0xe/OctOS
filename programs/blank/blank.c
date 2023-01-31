#include "octos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
	char words[] = "Hello im alex papadov";
	const char *token = strtok(words, " ");
	while (token) {
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	while (1) {
	}
	return 0;
}