#include "stdlib.h"
#include "octos.h"

void *malloc(size_t size)
{
	return octos_malloc(size);
}

void free(void *ptr)
{
}