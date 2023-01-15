#ifndef OCTOS_H
#define OCTOS_H

#include <stddef.h>

void print(const char *filename);
int getkey();

void *octos_malloc(size_t size);
void octos_free(void *ptr);
void octos_putchar(char c);

#endif