#include "rb_trees.h"
#include <stdlib.h>

/**
 * rb_tree_node - create a red-black node 
 * @parent: the parent of the node to crate
 * @value: the value of the new node
 * @color: the color of the new node: BLACK or RED
 * Return: A pointer to the created node
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{

	rb_tree_t *node;

	if (!parent)
	{
		parent = malloc(sizeof(rb_tree_t));
		if (parent == NULL)
			return (NULL);
		parent->parent = NULL;
		parent->color = color;
		parent->n = value;
		parent->left = NULL;
		parent->right = NULL;
		return (parent);
	}

	node = malloc(sizeof(rb_tree_t));
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->color = color;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
