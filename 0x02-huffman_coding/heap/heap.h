#ifndef _HEAP_
#define _HEAP_
#include <stdlib.h>
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;
heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));

int *path(int count);
int get_current_node(binary_tree_node_t **current, int *n_path);
int swap(binary_tree_node_t **current);
#endif
