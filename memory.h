#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stddef.h>

int
memory_init(void* memoryArea, size_t size);

void*
memory_malloc(size_t size);

void
memory_free(void* memory);

void
memory_print();

#endif
