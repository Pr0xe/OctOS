#ifndef OCTOS_STRING_H
#define OCTOS_STRING_H

#include <stdbool.h>

char tolower(char s1);
int strlen(const char *ptr);
int strnlen(const char *s, int count);
int strnlen_terminator(const char *str, int max, char terminator);
char *strcpy(char *s, const char *ct);
char *strncpy(char *s, const char *ct, int n);
int istrncmp(const char *cs, const char *ct, int n);
int strncmp(const char *cs, const char *ct, int n);
bool isdigit(char c);
int tonumericdigit(char c);
char *strtok(char *str, const char *delims);

#endif