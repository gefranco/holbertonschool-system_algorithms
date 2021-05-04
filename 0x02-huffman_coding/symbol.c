#include "huffman.h"
/**
 * symbol_create - creates a symbol_t data structure
 * @data: data to be stored in the structure
 * @freq:  frequency og the data
 * Return: EXIT_SUCCESS
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol;

	symbol = malloc(sizeof(symbol_t));
	if (!symbol)
		return (NULL);
	symbol->data = data;
	symbol->freq = freq;
	return (symbol);
}
