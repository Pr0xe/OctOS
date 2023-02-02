#include "octos.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char **argv)
{
	struct process_arguments arguments;
	octos_process_get_arguments(&arguments);

	main(arguments.argc, arguments.argv);
	while (1) {
	}
	return 0;
}