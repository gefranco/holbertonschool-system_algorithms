#include "huffman.h"
#include "heap.h"
#include <stdio.h>

/**
 * huffman_extract_and_insert -  extracts two nodes and insert a new one
 * @priority_queue: pointer to the priority queue
 * Return: 1 on success or 0 otherwise
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node_1, *node_2, *new_node;
	symbol_t *symbol;

	node_1 = heap_extract(priority_queue);
	node_2 = heap_extract(priority_queue);

	symbol = symbol_create(-1, ((symbol_t *)node_1->data)->freq +
					 ((symbol_t *)node_2->data)->freq
				);

	new_node = binary_tree_node(NULL, symbol);
	heap_insert(priority_queue, new_node);

	return (1);
}
