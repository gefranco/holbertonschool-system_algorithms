#include "heap.h"
#include <stdio.h>


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
		heap->root = NULL;
		heap->size -= 1;
		free(heap->root);
		return data;
		
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

	heap->size -= 1;

	current = heap->root;

	while (current->left || current->right)
	{
		int data_left;
		int data_right;
		
		data_left = 0;
		data_right = 0;
		if (current->left)
			data_left = *((int *)current->left->data);
		if (current->right)
			data_right = *((int *)current->right->data);
		if (!current->right || data_left < data_right)
			current = current->left;
		else
			current = current->right;

		if (heap->data_cmp(current->parent->data, current->data) > 0)
			swap(&current);

	}
	return (data);
}

