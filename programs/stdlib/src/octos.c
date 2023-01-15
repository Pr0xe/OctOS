#include "octos.h"

int octos_getkeyblock()
{
	int val = 0;
	do {
		val = octos_getkey();
	} while (val == 0);
	return val;
}

void octos_terminal_readline(char *out, int max, bool output_while_typing)
{
	int i = 0;
	for (i = 0; i < max - 1; i++) {
		char key = octos_getkeyblock();
		//return key
		if (key == 13) {
			break;
		}
		if (output_while_typing) {
			octos_putchar(key);
		}
		//Backspace
		if (key == 0x08 && i >= 1) {
			out[i - 1] = 0x00;
			//-2 because we +1 the go to continue
			i -= 2;
			continue;
		}
		out[i] = key;
	}
	//add null terminator
	out[i] = 0x00;
}