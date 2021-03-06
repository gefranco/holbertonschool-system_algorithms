#include "rb_trees.h"
#include <stdio.h>
/*
* 1. self-balancing BST(Binary search tree)left node => less
*   right node=>greater
* 2. root is always black
* 3. if node is red their childrens are black
* 4. every path from a node to any of its descendendents NIL node
*  has the same No of Black nodes
*/

int depth_blacks(const rb_tree_t *node);
int is_bst(const rb_tree_t *tree);

/**
 * rb_tree_is_valid - Validate if a R-B tree is valid
 * @tree: the tree to validate
 * Return: 1 if valid 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	(void) tree;
	if (tree->color == RED)
		return (0);

	if (!is_bst(tree))
		return (0);

	if (depth_blacks(tree) < 0)
		return (0);
	return (1);/*valid*/
}
/**
 * is_bst - Validate if a tree is valid binary tree search
 * @node: the tree-node to validate
 * Return: 1 if valid 0 otherwise
 */
int is_bst(const rb_tree_t *node)
{
	if (node == NULL)
		return (1);
	if (node->left != NULL && node->left->n > node->n)
		return (0);
	if (node->right != NULL && node->right->n < node->n)
		return (0);
	if (node->color == RED)
	{
		if (node->left != NULL && node->left->color == RED)
			return (0);
		if (node->right != NULL && node->right->color == RED)
			return (0);
	}
	if (!is_bst(node->left) || !is_bst(node->right))
		return (0);
	return (1);
}
/**
 * depth_blacks - Calculate the depth of black nodes in B-R trees
 * @node: the node-tree to calculate
 * Return: the depth of black nodes -1 if is not valid
 */
int depth_blacks(const rb_tree_t *node)
{
	int leftH;
	int rightH;
	int add;

	if (node == NULL)
		return (0);
	leftH = depth_blacks(node->left);
	rightH = depth_blacks(node->right);
	add = node->color == BLACK ? 1 : 0;
	if (leftH != rightH)
		return (-1);
	else
		return (leftH + add);
}

