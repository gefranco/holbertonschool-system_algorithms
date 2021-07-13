#include "nary_trees.h"
#include <stdlib.h>

/**
 * nary_tree_delete - function that deallocates an entire N-ary tree
 * @tree: a pointer to the parent node
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *children, *sibling;

	if (!tree)
		return;

	for (children = tree->children; children; children = sibling)
	{
		sibling = children->next;
		nary_tree_delete(children);
	}

	free(tree->content);
	free(tree);

}
