#include "heap.h"
#include <stdio.h>


void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *current;
	int *n_path, *data;
	if (!heap)
		return NULL;

	current = heap->root;
        n_path = path(heap->size);
        get_current_node(&current, n_path);	


	if (current->left)
		current = current->left;
	/*printf("current%d %d\n ",
                 *((int *)current->data), i);*/

	
	data = heap->root->data; 
	heap->root->data = current->data;

	if(current->parent->right == current)
		current->parent->right = NULL;
	else
		current->parent->left = NULL;
	free(current);

	heap->size -=1;

	current = heap->root;

	while(current->left || current->right)
	{
		int data_left;
		int data_right;
		data_left = 0;
		data_right = 0;
		if (current->left)
			data_left = *((int *)current->left->data);
		if (current->right)
			data_right = *((int *)current->right->data);
		if(!current->right || data_left < data_right)
                	current = current->left;
        	else
                	current = current->right;

		if(heap->data_cmp(current->parent->data, current->data) > 0)
			swap(&current);

	}
/*printf("****current%d %d\n ",
                 *((int *)current->data), i);
*/
	return data;		
/*
	extracted = heap->root;
	if(heap->data_cmp(extracted->left->data, extracted->right->data) > 0)
		heap->root = extracted->right;
	else
		heap->root = extracted->left;
	return extracted->data; 
*/
}



/*
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
int *path(int count)
{
        int j;
        int i = 0;
        int *path;

        int bkcount = count * 2;

        count = count * 2;
        while ((count = count / 2) > 1)
        {
                i++;
        }

        path = malloc(sizeof(int) * i + 1);

        path[i] = -1;
        for (j = i - 1; (bkcount = bkcount / 2) > 1 ; j--)
        {
                path[j] = bkcount % 2;
        }
        return (path);
}*/
