#include "heap.h"
#include <stdio.h>

int *path(int count);
int get_current_node(binary_tree_node_t **current, int *n_path);
int swap(binary_tree_node_t **current);
/**
 * heap_insert - insert a node in a Min Binary Heap
 *
 * @heap: a pointer to the heap in which the node has to be inserted
 * @data: a pointer containing the data to store in the new node
 *
 * Return: inserted node
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *current;
	int i;
	int *n_path;

	if (!heap || !data)
		return (NULL);

	if (!heap->root)
	{
		heap->root = binary_tree_node(NULL, data);
		heap->size += 1;
		return (heap->root);
	}

	current = heap->root;
	n_path = path(heap->size + 1);
	i = get_current_node(&current, n_path);
	if (n_path[i] == 0)
	{
		current->left = binary_tree_node(current, data);
		current->left->parent = current;
		current = current->left;
	}
	else
	{
		current->right = binary_tree_node(current, data);
		current->right->parent = current;
		current = current->right;
	}

	while (current->parent)
	{
		if (heap->data_cmp(current->data, current->parent->data) < 0)
		{
			swap(&current);
		}
		else
			break;
		current = current->parent;
	}

	free(n_path);
	heap->size += 1;



	return (current);
}
/**
 * path - The path to go from the root to the node to insert a newone
 * @count: total nodes
 * Return: array of 1 and 0 representing the path
 */
int *path(int count)
{
	int j;
	int i = 0;
	int *path = NULL;

	int bkcount = count * 2;

	count = count * 2;
	while ((count = count / 2) > 1)
	{
		i++;
	}

	path = malloc(sizeof(int) * (i + 1));

	path[i] = -1;

	for (j = i - 1; (bkcount = bkcount / 2) > 1 ; j--)
	{
		path[j] = bkcount % 2;
	}
	return (path);
}
/**
 * get_current_node - traverse the path to the node to insert a newone
 * @current: Pointer to the root node
 * @n_path: path to traverse 0-left 1-right
 * Return: the position of the node
 */
int get_current_node(binary_tree_node_t **current, int *n_path)
{
	int i = 0;

	while (n_path[i] != -1)
	{
		if ((*current)->left == NULL || (*current)->right == NULL)
			return (i);
		if (n_path[i] == 0)
			*current = (*current)->left;
		else if (n_path[i] == 1)
			*current = (*current)->right;

		i++;
	}
	return (i);
}
/**
 * swap - swap the value of the node with his parent's value
 * @current: Pointer to the root node
 * Return: 0 on success
 */
int swap(binary_tree_node_t **current)
{
	int *data;

	data = (*current)->parent->data;
	{
		(*current)->parent->data = (*current)->data;
		(*current)->data = data;
	}
	return (0);
}
