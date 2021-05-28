#include "pathfinding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
queue_t *backtracking(queue_t *path, vertex_t const *start,
			const vertex_t *target, char *);
queue_t *backtracking_graph(graph_t *graph,
				vertex_t const *start, vertex_t const *target)
{
	char *visited;
	queue_t *path = queue_create();


	visited = calloc(graph->nb_vertices, sizeof(char));
	path = backtracking(path, start, target, visited);
	queue_push_front(path, strdup(start->content));
	free(visited);
	return (path);

}

queue_t *backtracking(queue_t *path, vertex_t const *start,
			const vertex_t *target, char *visited)
{
	edge_t *edges;
	(void) path;
	(void) start;
	(void) target;

	if (!start || visited[start->index])
		return (NULL);

	visited[start->index] = 1;
	printf("Checking %s\n", start->content);

	if (start == target)
	{
		return (path);
	}
	for (edges = start->edges; edges; edges = edges->next)
	{
		if (backtracking(path, edges->dest, target, visited))
		{
			queue_push_front(path, strdup(edges->dest->content));
			return (path);
		}
	}
	return (NULL);
}
