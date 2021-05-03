#ifndef _HUFFMAN_
#define _HUFFMAN_
#include <stdlib.h>
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

symbol_t *symbol_create(char data, size_t freq);
#endif
