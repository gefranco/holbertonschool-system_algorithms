#include "heap.h"
#include "huffman.h"

/**
 * huffman_tree - Entry point
 * @data: an array of characters
 * @freq: an array containing the associated frequencies
 * @size: the arrays size
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{

	heap_t *priority_queue;

	priority_queue = huffman_priority_queue(data, freq, size);

	if (!priority_queue)
		return (NULL);

	while (priority_queue->size > 1)
		huffman_extract_and_insert(priority_queue);

	return (priority_queue->root->data);
}

