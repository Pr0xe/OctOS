#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

int strlen(const char *ptr);
int strnlen(const char *ptr, int max);
bool isdigit(char c);
int tonumericdigit(char c);
char *strcpy(char *s, const char *ct);
int strncmp(const char *cs, const char *ct, int n);
int istrncmp(const char *cs, const char *ct, int n);
int strnlen_terminator(const char *str, int max, char terminator);
char tolower(char s1);

#endif