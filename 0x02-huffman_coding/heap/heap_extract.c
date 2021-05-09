#include "heap.h"
#include <stdio.h>

int reorder(binary_tree_node_t *current, heap_t *heap);

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: a pointer to the heap
 * Return:  a pointer to the data
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *current;
	int *n_path;
	void *data;

	if (!heap)
		return (NULL);

	if (heap->size == 1)
	{
		data = heap->root->data;
		heap->root->data = NULL;
		free(heap->root);
		heap->root = NULL;
		heap->size -= 1;
		return (data);
	}

	current = heap->root;
	n_path = path(heap->size);
	get_current_node(&current, n_path);

	if (current->left)
		current = current->left;
	data = heap->root->data;
	heap->root->data = current->data;

	if (current->parent->right == current)
		current->parent->right = NULL;
	else
		current->parent->left = NULL;
	free(current);
	free(n_path);
	heap->size -= 1;

	current = heap->root;

	reorder(current, heap);
	return (data);
}

/**
 * reorder - reorder a Min Binary Heap
 * @heap: a pointer to the heap
 * @current: a pointer to current node
 * Return:  a pointer to the data
 */
int reorder(binary_tree_node_t *current, heap_t *heap)
{
	while (current->left || current->right)
	{
	if (!current->right ||
		heap->data_cmp(current->left->data, current->right->data) < 0)
		current = current->left;
		else
			current = current->right;
		if (heap->data_cmp(current->parent->data, current->data) > 0)
			swap(&current);
	}
	return (0);
}
