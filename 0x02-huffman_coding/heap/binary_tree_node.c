#include "heap.h"
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	if (!parent)
	{
		parent = malloc(sizeof(binary_tree_node_t));
		parent->left = NULL;
		parent->right = NULL;
		parent->parent = NULL;
		parent->data = data;
		return (parent);
	}

	node = malloc(sizeof(binary_tree_node_t));
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return (node);
}
