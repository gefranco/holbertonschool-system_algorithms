#include <stdio.h>
#include "rb_trees.h"

/**
 * array_to_rb_tree - build a R-B tree from an array
 * @array: the array
 * @size: the array's size
 * Return: pointer to the root's tree
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{

	size_t i;
	rb_tree_t *root;
	(void)array;
	(void)size;


	root = NULL;
	for (i = 0; i < size; i++)
	{
		rb_tree_insert(&root, array[i]);
	}

	return (root);
}
