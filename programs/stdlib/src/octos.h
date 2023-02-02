#ifndef OCTOS_H
#define OCTOS_H

#include <stddef.h>
#include <stdbool.h>

struct command_argument {
	char argument[512];
	struct command_argument *next;
};

void print(const char *filename);
int octos_getkey();

void *octos_malloc(size_t size);
void octos_free(void *ptr);
void octos_putchar(char c);
int octos_getkeyblock();
void octos_terminal_readline(char *out, int max, bool output_while_typing);
void octos_process_load_start(const char *filename);
struct command_argument *octos_parse_command(const char *command, int max);
#endif