#include "huffman.h"
#include "heap.h"
#include <stdio.h>
void binary_tree_print(
	const binary_tree_node_t *heap, int (*print_data)(char *, void *));
int nested_print(char *buffer, void *data);

/**
 * int_cmp2 - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two
 */
int int_cmp2(void *p1, void *p2)
{
	binary_tree_node_t *node1, *node2;
	symbol_t *s1, *s2;

	node1 = (binary_tree_node_t *)p1;
	node2 = (binary_tree_node_t *)p2;
	s1 = (symbol_t *)node1->data;
	s2 = (symbol_t *)node2->data;
	if (s1->freq != s2->freq)
		return (s1->freq - s2->freq);	
	if (s1->data == -1)
		return s2->data;
	if (s2->data == -1)
		return s1->data;
	return (s1->data - s2->data);
}

/**
 * huffman_priority_queue - creates a priority queue for the Huffman algorithm
 *
 * @data: an array of characters
 * @freq: an array containing the associated frequencies
 * @size: size of both arrays
 * Return: a pointer to the created min heap
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	size_t i;
	binary_tree_node_t *node;

	heap = heap_create(int_cmp2);
	for (i = 0; i < size; ++i)
	{
		symbol_t *symbol = symbol_create(data[i], freq[i]);

		node = binary_tree_node(NULL, symbol);
		heap_insert(heap, node);
	}
	return (heap);
}
