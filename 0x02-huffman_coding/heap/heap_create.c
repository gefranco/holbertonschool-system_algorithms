#include "heap.h"
/**
 * heap_create - create a Heap data structure
 *
 * @data_cmp: pointer to a compare function
 *
 * Return: Pointer to the heap data structure
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap;

	heap = malloc(sizeof(heap_t));
	if (!heap)
		return (NULL);
	heap->size = 0;
	heap->data_cmp = data_cmp;
	heap->root = NULL;


	return (heap);
}
