#include "nary_trees.h"
#include <string.h>

/**
 * path_exists - function that checks if a path exists in an N-ary tree
 * @root: a pointer to the root
 * @path: is a NULL terminated array of strings. T
 * Return: 1 if all the elements of path are present in the tree
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t const *n = NULL;

	if (!root)
		return (0);

	if (*path == NULL)
		return (1);

	n = root;
	printf("%s - %s\n", *path, n->content);

	while (n)
	{
		if (strcmp(*path, n->content) == 0)
			if (path_exists(n->children, path + 1) == 1)
				return (1);
		n = n->next;
	}

	return (0);
}
