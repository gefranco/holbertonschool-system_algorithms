#include "rb_trees.h"
#include <stdio.h>

rb_tree_t *node_sibling(rb_tree_t *node);
rb_tree_t *node_in_order_succesor(rb_tree_t *node);
int node_is_leaf(const rb_tree_t *node);
int delete_node(rb_tree_t *node);
rb_tree_t *search_left_node(rb_tree_t *tree, int value);
rb_tree_t *search_right_node(rb_tree_t *tree, int value);
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *node = NULL;


	if (n < root->n)
		node = search_left_node(root, n);
	if (n > root->n)
		node = search_right_node(root, n);

	if (node)
	{
		delete_node(node);
	}
	return (root);
}

int delete_node(rb_tree_t *node)
{
	if (node->parent == NULL && node->color == DOUBLE_BLACK)
	{
		node->color = BLACK;
		return (1);
	}

	if ((node->color == RED) && !node->right && !node->left)
	{
		if (node->parent->right == node)
		{
			node->parent->right = NULL;
			return (0);
		}
		else
		{
			node->parent->left = NULL;
			return (0);
		}
	}

	if (node_is_leaf(node))
	{
		rb_tree_t *parent;

		if (node->color == BLACK)
		{
			node->color = DOUBLE_BLACK;
			node->n = -1;
			delete_node(node);
			return (1);
		}
		if (node_sibling(node)->color == RED && node->parent->left == node)
		{
			node_sibling(node)->color = BLACK;
			node->parent->color = RED;

			node->parent->parent->right = node->parent->right;
			node->parent->parent = node->parent->right;
			node->parent->right = node->parent->parent->left;
			node->parent->parent->left = node->parent;
			delete_node(node);
			return (1);
		}

		if (node_sibling(node)->color == BLACK)
		{
			if (node->parent->left == node)
				node->parent->left = NULL;
			if (node->parent->color == RED)
			{
				node->parent->color = BLACK;
				node_sibling(node)->color = RED;
				return (1);
			}
			if (node->parent->color == BLACK)
			{
				node->parent->color = DOUBLE_BLACK;
				delete_node(node->parent);
				return (1);
			}
			return (1);
		}

		node->color = DOUBLE_BLACK;
		node_sibling(node)->color = RED;
		node->n = -1;
		node->parent->color = DOUBLE_BLACK;
		parent = node->parent;
		delete_node(node);
		delete_node(parent);
		return (1);
	}
	if (!node_is_leaf(node) && node->color == DOUBLE_BLACK)
	{
		/*!red_childrens(node_sibling(node))*/
		if (node_sibling(node)->color == BLACK &&
		 !((node->left && node->left->color == RED) ||
			(node->right && node->right->color == RED)))
		{
			node->parent->color = DOUBLE_BLACK;
			node_sibling(node)->color = RED;
			delete_node(node->parent);

		}

		return (1);
	}

	else
	{
		if (node_in_order_succesor(node))
			node->n = node_in_order_succesor(node)->n;
		if (node_in_order_succesor(node)->parent->left
			&& node_in_order_succesor(node)->parent->left
			== node_in_order_succesor(node))
			if (node_in_order_succesor(node)->color == RED)
				node_in_order_succesor(node)->parent->left = NULL;
			else
				node_in_order_succesor(node)->color = DOUBLE_BLACK;
		else
			if (node_in_order_succesor(node)->color == RED)
				node_in_order_succesor(node)->parent->right = NULL;
			else
			{
				node_in_order_succesor(node)->color =
				DOUBLE_BLACK;
				node_in_order_succesor(node)->n = -1;
			}
	}
	if (node_in_order_succesor(node) &&
		node_in_order_succesor(node)->color == DOUBLE_BLACK)
	{
		if (node_sibling(node_in_order_succesor(node))->color == BLACK
			&& node_is_leaf(node_sibling(node)))
		{
			node_in_order_succesor(node)->parent->color = BLACK;
			node_sibling(node_in_order_succesor(node))->color = RED;
			delete_node(node_in_order_succesor(node));
		}
		return (1);
	}

	return (1);
}

/**
*int red_childrens(rb_tree_t *node)
*{
*	if ((node->left && node->left->color == RED) ||
*		(node->right && node->right->color == RED))
*		return (1);
*	return (0);
*}
*/
rb_tree_t *node_in_order_succesor(rb_tree_t *node)
{
	rb_tree_t *left;

	left = node->right;
	while (left->left)
		left = left->left;

	return (left);
}

/**
 * search_left_node - search a node in a R-B tree
 * @tree: the node to insert
 * @value: the vlue of the node
 * Return: pointer to the node inserted
 */
rb_tree_t *search_left_node(rb_tree_t *tree, int value)
{
	while (tree->left && value <= tree->n)
	{
		if (value == tree->n)
			return (tree);
		tree = tree->left;
	}
	if (tree->n == value)
		return (tree);
	if (tree->right && value > tree->n)
	{
		/*tree->right->right = rb_tree_node(tree, value, RED);*/
		return (search_right_node(tree, value));
	}
		return (NULL);
}

/**
 * search_right_node - search a node in a R-B tree
 * @tree: the node to insert
 * @value: the value of the node
 * Return: pointer to the node inserted
 */
rb_tree_t *search_right_node(rb_tree_t *tree, int value)
{
	while (tree->right && value >= tree->n)
	{
		if (value == tree->n)
			return (tree);
		tree = tree->right;
	}
	if (tree->n == value)
		return (tree);
	if (tree->left && value < tree->n)
		return (search_left_node(tree, value));

	return (NULL);
}

int node_is_leaf(const rb_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (!node->left && !node->right)
		return (1);
	else
		return (0);

}

rb_tree_t *node_sibling(rb_tree_t *node)
{


	rb_tree_t *sibling;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	sibling = node->parent->right;

	if (sibling && sibling == node)
	{
		if (node->parent->left == NULL)
			return (NULL);
		else
			return (node->parent->left);

	}
	return (sibling);

}
