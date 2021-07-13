#include "nary_trees.h"

size_t nary_tree_depth(nary_tree_t *root);
size_t max(size_t a, size_t b);
/**
 * nary_tree_diameter - function that computes the diameter of an N-ary tree
 * @root: a pointer to the root node of the tree to compute the diameter of
 * Return: he diameter of the tree
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{

	size_t max_depth = 0;
	size_t max_depth_2 = 0;
	size_t tmp_depth = 0;
	nary_tree_t *tmp_node;


	if (!root)
		return (0);

	for (tmp_node  = root->children; tmp_node; tmp_node = tmp_node->next)
	{
		tmp_depth = nary_tree_depth(tmp_node);
		if (tmp_depth > max_depth)
		{
			max_depth_2 = max_depth;
			max_depth = tmp_depth;
		}
		else if (tmp_depth > max_depth_2)
		{
			max_depth_2 = tmp_depth;
		}
	}

	return (max_depth + max_depth_2 + 1);

}
/**
 * nary_tree_depth - function that return the depth of a N-ary tree
 * @root: a pointer to the root node of the tree to traverse
 * Return: the depth of the tree pointed to by root
 */
size_t nary_tree_depth(nary_tree_t *root)
{
	size_t max_depth = 0, tmp_depth;
	nary_tree_t *tmp_node;

	if (!root)
		return (0);

	for (tmp_node = root->children; tmp_node; tmp_node = tmp_node->next)
	{
		tmp_depth = nary_tree_depth(tmp_node);
		max_depth = max(tmp_depth, max_depth);

	}

	return (max_depth + 1);
}
/**
 * max - function that goes through an N-ary tree, node by node
 * @a: ...
 * @b: ...
 * Return: the biggest
 */
size_t max(size_t a, size_t b)
{
	return (a > b ? a : b);
}
