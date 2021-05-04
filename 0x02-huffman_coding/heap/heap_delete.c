#include "heap.h"
void binary_tree_delete(binary_tree_node_t *node, void (*free_data)(void *));

/**
 * heap_delete - deallocates a heap
 *
 * @heap: a pointer to the heap to delete
 *
 * @free_data: a pointer to a function that free the content of a node
 * Return: nothing
 */
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
/**
 * binary_tree_delete - deallocate a binary tree
 *
 * @node: pointer to the root node
 * @free_data: a pointer to a function that free the content of a node
 *
 * Return: Difference between the two strings
 */
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
