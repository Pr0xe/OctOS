#include "octos.h"

int main(int argc, char **argv)
{
	print("Hello this is test\n");
	while (1) {
		if (getkey() != 0) {
			print("key was pressed\n");
		}
	}
	return 0;
}