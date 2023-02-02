#include "shell.h"
#include "stdio.h"
#include "stdlib.h"
#include "octos.h"

int main(int argc, char **argv)
{
	print("OctOS Terminal\n");
	while (1) {
		print("->");
		char buf[1024];
		octos_terminal_readline(buf, sizeof(buf), true);
		print("\n");
		octos_system_run(buf);
		print("\n");
	}
	return 0;
}