#include "octos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
	char str[] = "Hello Alex";
	struct command_argument *root_command =
		octos_parse_command(str, sizeof(str));
	printf("%s\n", root_command->argument);
	printf("%s\n", root_command->next->argument);

	while (1) {
	}
	return 0;
}