#include "graphs.h"
#include <string.h>
#include <stdio.h>
vertex_t *get_vertex(graph_t *grap, const char *str);
int add_edge(vertex_t *vertex, edge_t *edge);

/**
 * graph_add_edge - Entry point
 * @graph: graph's pointer
 * @src: source vertex
 * @dest: destination vertex
 * @type: bidirectional or unidirectional
 * Return: 1 if SUCCESS or 0 otherwise
 */
int graph_add_edge(graph_t *graph, const char *src,
		const char *dest, edge_type_t type)
{
	vertex_t *src_vertex = NULL;
	vertex_t *dest_vertex = NULL;
	edge_t *edge = NULL;

	if (!src || !dest)
		return (0);
	src_vertex = get_vertex(graph, src);
	dest_vertex = get_vertex(graph, dest);
	if (!src_vertex || !dest_vertex)
		return (0);

	edge = malloc(sizeof(edge_t));

	if (!edge)
		return (0);
	edge->dest = dest_vertex;
	edge->next = NULL;

	src_vertex->nb_edges += 1;
	add_edge(src_vertex, edge);

	if (type == BIDIRECTIONAL)
	{
		edge_t *edge2;

		edge2 = malloc(sizeof(edge_t));
		edge2->dest = src_vertex;
		edge2->next = NULL;

		dest_vertex->nb_edges += 1;
		add_edge(dest_vertex, edge2);
	}

	return (1);
}

/**
 * get_vertex - get a vertex with str content
 * @graph: the praph to fin the vertex
 * @str: the content to find the vertex
 * Return: 1 if SUCCESS or 0 otherwise
 */
vertex_t *get_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex = graph->vertices;

	while (vertex)
	{
		if (strcmp(vertex->content, str) == 0)
		{
			return (vertex);
		}
		vertex = vertex->next;
	}
	return (NULL);
}

/**
 * add_edge - add a new edge
 * @vertex: destination vertex
 * @edge: new edge to add to the vertex
 * Return: 1 if SUCCESS or 0 otherwise
 */
int add_edge(vertex_t *vertex, edge_t *edge)
{
	edge_t *last_edge = NULL;

	if (!vertex->edges)
	{
		vertex->edges = edge;
		return (1);
	}

	last_edge = vertex->edges;


	while (last_edge->next)
	{
		last_edge = last_edge->next;
	}
	last_edge->next = edge;
	return (1);
}
