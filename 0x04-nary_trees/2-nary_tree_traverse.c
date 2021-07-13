#include "nary_trees.h"

/**
 * get_depth_nary - function that get the depth ob a N-ary tree
 * @root: a pointer to the parent node
 * @d: ...
 * @action: ...
 * Return: the depth
 */
size_t get_depth_nary(nary_tree_t const *root, size_t d,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	nary_tree_t *children = NULL;
	size_t max_d = 0, cd = 0;

	action(root, d);
	children = root->children;
	max_d = d;

	while (children)
	{
		cd = get_depth_nary(children, d + 1, action);
		if (cd > max_d)
			max_d = cd;

		children = children->next;
	}
	return (max_d);
}
/**
 * nary_tree_traverse - function that goes through an N-ary tree, node by node
 * @root: a pointer to the root node of the tree to traverse
 * @action: a pointer to a function to execute for each node being traversed
 * Return: the biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
				void (*action)(nary_tree_t const *node, size_t depth))
{


	if (!root)
		return (0);

	return (get_depth_nary(root, 0, action));

}

