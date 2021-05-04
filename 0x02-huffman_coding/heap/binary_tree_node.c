#include "heap.h"
/**
 * binary_tree_node - create a generic Binary Tree node
 *
 * @parent: pointer to a parent's node
 * @data: data to be stored in the node
 *
 * Return: Pointer to the vreated node
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	if (!parent)
	{
		parent = malloc(sizeof(binary_tree_node_t));
		if (!parent)
			return (NULL);
		parent->left = NULL;
		parent->right = NULL;
		parent->parent = NULL;
		parent->data = data;
		return (parent);
	}

	node = malloc(sizeof(binary_tree_node_t));
		if (!node)
			return (NULL);
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return (node);
}
