#include "graphs.h"
#include <stdio.h>

void delete_edges(vertex_t *vertex);
/**
 * graph_delete - completely deletes a graph
 * @graph: graph's pointer
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertex;
	vertex_t *tmp_vertex;

	if (!graph)
		return;

	vertex = graph->vertices;

	while (vertex && vertex->next)
	{
		tmp_vertex = vertex->next;

		delete_edges(vertex);
		free(vertex->content);
		free(vertex);
		vertex = tmp_vertex;

	}
	delete_edges(vertex);
	free(vertex->content);
	free(vertex);
	free(graph);
	graph = NULL;
}
/**
 * delete_edges - deletes the graph's edges
 * @vertex: vertex's pointer
 */
void delete_edges(vertex_t *vertex)
{
	edge_t *edge = vertex->edges;
	edge_t *tmp_edge;

	if (!edge)
		return;
	while (edge->next)
	{
		tmp_edge = edge->next;
		free(edge);
		edge = tmp_edge;
	}
	free(edge);
}
