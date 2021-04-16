#include "graphs.h"
#include <string.h>
#include <stdio.h>
int vertex_exist(graph_t *graph, const char *str);
/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph: pointer's graph
 * @str: vertex's content
 * Return: vertex's created
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex = NULL;
	vertex_t *last = NULL;

	if (!graph || !str)
		return (NULL);

	if (vertex_exist(graph, str))
		return (NULL);

	vertex = malloc(sizeof(vertex_t));
	if (!vertex)
		return (NULL);
	vertex->content = strdup(str);
	vertex->index = graph->nb_vertices;

	vertex->nb_edges = 0;
	vertex->edges = NULL;

	vertex->next = NULL;
	graph->nb_vertices += 1;

	if (!graph->vertices)
	{
		graph->vertices = vertex;

		return (vertex);
	}
	last = graph->vertices;
	while (last->next)
		last = last->next;
	last->next = vertex;


	return (vertex);
}
/**
 * vertex_exist - check wheter vertex exists or not
 * @graph: pointer's graph
 * @str: vertex's content
 * Return: 1 if exits 0 otherwise
 */
int vertex_exist(graph_t *graph, const char *str)
{
	vertex_t *vertex;

	if (!graph->vertices)
		return (0);
	vertex = graph->vertices;
	while (vertex)
	{
		if (strcmp(vertex->content, str) == 0)
			return (1);
		vertex = vertex->next;
	}
	return (0);
}
