#include <stdlib.h>
#include "nary_trees.h"
#include <string.h>

/**
 * nary_tree_insert - function that inserts a node in a N-ary tree
 * @parent: a pointer to the parent node
 * @str: the string to be stored in the created node
 * Return: a pointer to the created node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *node, *tmp;

	node = malloc(sizeof(nary_tree_t));

	if (!node)
		return (NULL);
	node->content = strdup(str);

	if (!parent)
	{
		parent = node;
		parent->parent = NULL;
		parent->nb_children = 0;
		parent->children = NULL;
		parent->next = NULL;
		return (parent);
	}

	node->parent = parent;
	node->nb_children = 0;
	node->children = NULL;
	tmp = parent->children;

	parent->children = node;
	node->next = tmp;
	parent->nb_children += 1;

	return (node);
}
