#ifndef _HUFFMAN_
#define _HUFFMAN_
#include <stdlib.h>
#include "heap.h"
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
#endif
