#include <stdlib.h>
#include "rb_trees.h"
#include <stdio.h>

#define LEFT_LEFT	1
#define RIGHT_RIGHT	2
#define LEFT_RIGHT	3
#define RIGHT_LEFT	4
/*
* RED-BLACK TREES
* - if tree is empty create new node as new node with color black
* - if tree is not empty create new node as left or right node with color red
* - if parent of new node is black then exit
* - if parent of new node is red, then check the color of uncle's new node
*	- if color is black or null then do suitable rotation and recolor
*	- if color is red then recolor & check if parent's parent of new node
	is not root,
	if yes recolor & recheck
*/
int check(rb_tree_t *node, rb_tree_t **tree);
rb_tree_t *check_reds(rb_tree_t *node);
int rotate(int rot_case, rb_tree_t *node, rb_tree_t **tree);
int get_config(rb_tree_t *node);
rb_tree_t *get_uncle(rb_tree_t *node);
int recolor(int rot_cas, rb_tree_t *node);
rb_tree_t *insert_left_node(rb_tree_t *tree, int value);
rb_tree_t *insert_right_node(rb_tree_t *tree, int value);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *node;

	if (!*tree)
	{
		*tree = rb_tree_node(NULL, value, BLACK);
		return (*tree);
	}

	if (value < (*tree)->n)
		node = insert_left_node(*tree, value);
	else
		node = insert_right_node(*tree, value);

	if (!node)
		return (NULL);

	check(node, tree);

	if (check_reds(node))
	{
		check(check_reds(node), tree);
	}
	return (node);
}
int check(rb_tree_t *node, rb_tree_t **tree)
{
	if (node->parent->parent != NULL && node->parent->color == RED)
	{
		if (get_uncle(node) == NULL)
		{
			rotate(get_config(node), node, &*tree);

		}
		else if (get_uncle(node) != NULL && get_uncle(node)->color == BLACK)
		{
			rotate(get_config(node), node, &*tree);

		} else
		{
			recolor(2, node);
		}
	}
	return (0);
}
int rotate(int rot_case, rb_tree_t *node, rb_tree_t **tree)
{
	rb_tree_t *nr, *ln, *root;

	if (rot_case == LEFT_LEFT)
	{

		rb_tree_t *t3;

		root = node->parent->parent->parent;
		t3 = node->parent->left;
		recolor(1, node);
		ln = node->parent->parent;
		nr = node->parent;

		ln->parent = nr;

		ln->right = t3;
		if (t3)
			t3->parent = ln;

		nr->left = ln;
		nr->parent = root;

		if (root == NULL)
			*tree = nr;
		else
			root->right = nr;

		return (1);
	}
	if (rot_case == LEFT_RIGHT)
	{
		rb_tree_t *x, *p, *t3, *t1, *t2;

		t3 = node->parent->left;
		t1 = node->left;
		t2 = node->right;

		x = node;
		p = node->parent;

		p->left = t1;
		p->right = t2;
		x->left = p;
		x->right = t3;
		x->parent = x->parent->parent;
		p->parent = x;
		x->parent->left = x;

		rotate(get_config(p), p, &*tree);

		return (1);
	}
	if (rot_case == RIGHT_RIGHT)
	{
		rb_tree_t *p, *t3;

		recolor(1, node);

		p = node->parent;
		t3 = p->right;

		p->right = p->parent;
		p->parent = p->parent->parent;

		p->right->parent = p;

		p->right->left = t3;

		if (p->parent == NULL)
			*tree = p;
		else
			if (p->parent->left == p->right)
				p->parent->left = p;
			else
				p->parent->right = p;

		return (1);

	}

	if (rot_case == RIGHT_LEFT)
	{
		rb_tree_t *x, *p, *t3, *t5, *t4;

		t3 = node->left;
		t5 = node->parent->right;
		t4 = node->right;

		x = node;
		p = node->parent;

		p->left = t4;
		p->right = t5;
		x->left = t3;
		x->right = p;
		x->parent = x->parent->parent;
		p->parent = x;
		x->parent->right = x;

		rotate(get_config(p), p, &*tree);

		return (1);
	}

	return (1);
}

int get_config(rb_tree_t *node)
{
	if (node->parent->left != NULL && node->parent->left == node)
	{
		if (node->parent->parent->left != NULL &&
			node->parent->parent->left == node->parent)
			return (RIGHT_RIGHT);
		if (node->parent->parent->right != NULL &&
			node->parent->parent->right == node->parent)
		{
			return (RIGHT_LEFT);
		}
	}
	if (node->parent->right != NULL && node->parent->right == node)
		if (node->parent->parent->left != NULL &&
			node->parent->parent->left == node->parent)
			return (LEFT_RIGHT);

	return (LEFT_LEFT);
}
rb_tree_t *insert_left_node(rb_tree_t *tree, int value)
{
	while (tree->left && value <= tree->n)
	{
		if (value == tree->n)
			return (NULL);
		tree = tree->left;
	}
	if (value < tree->n)
	{
		tree->left = rb_tree_node(tree, value, RED);
		return (tree->left);
	}
	else if (value > tree->n && !tree->right)
	{
		tree->right = rb_tree_node(tree, value, RED);
		return (tree->right);
	}
	else if (value > tree->n)
	{
		/*tree->right->right = rb_tree_node(tree, value, RED);*/
		return (insert_right_node(tree, value));
	}
		return (NULL);
}

rb_tree_t *insert_right_node(rb_tree_t *tree, int value)
{
	while (tree->right && value >= tree->n)
	{
		if (value == tree->n)
			return (NULL);
		tree = tree->right;
	}
	if (value > tree->n)
	{
		tree->right = rb_tree_node(tree, value, RED);
		return (tree->right);
	}
	else if (value < tree->n && !tree->left)
	{
		tree->left = rb_tree_node(tree, value, RED);
		return (tree->left);
	}
	else if (value < tree->n)
		return (insert_left_node(tree, value));
	return (NULL);
}

int recolor(int recolor, rb_tree_t *node)
{
	if (recolor == 1)
	{
		node->parent->color = BLACK;
		node->parent->parent->color = RED;
	}
	if (recolor == 2)
	{
		node->parent->color = BLACK;
		get_uncle(node)->color = BLACK;

		if (node->parent->parent->parent != NULL)
			node->parent->parent->color = RED;
	}
	return (1);
}

rb_tree_t *get_uncle(rb_tree_t *node)
{
	rb_tree_t *uncle;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	uncle =	node->parent->parent->right;

	if (uncle && uncle == node->parent)
	{
		if (node->parent->parent->left == NULL)
			return (NULL);
		else
			return (node->parent->parent->left);
	}
	return (uncle);
}

rb_tree_t *check_reds(rb_tree_t *node)
{
	while (node->parent)
	{
		if (node->color == RED && node->parent->color == RED)
			return (node);
		node = node->parent;
	}
	return (NULL);
}
