#include "heap.h"
void binary_tree_delete(binary_tree_node_t *node, void (*free_data)(void *));


void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	binary_tree_node_t *node;
	(void) heap;
	(void) free_data;

	if (!heap->root)
		return;
	node = heap->root;

	binary_tree_delete(node, free_data);
	free(heap);

}

void binary_tree_delete(binary_tree_node_t *node, void (*free_data)(void *))
{

	if (node == NULL)
		return;

	binary_tree_delete(node->left, free_data);
	binary_tree_delete(node->right, free_data);
	if (free_data)
		free_data(node->data);
	free(node);


}
