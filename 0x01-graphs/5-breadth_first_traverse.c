#include "graphs.h"
#include <stdio.h>
int vertex_marked(vertex_t *vertex, size_t indices[], size_t i);
size_t depth(vertex_t *v, size_t marked[], size_t depth, size_t *max,
	void (*action)(const vertex_t *v, size_t depth));
size_t *max_depth(size_t *depth, size_t new_depth);

size_t breadth_first_traverse(
	const graph_t *graph, void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *v;
	size_t *indices;
	size_t i, depth_, *max;

	if (!graph || !action)
		return (0);
	if (!graph->vertices)
		return (0);
	indices = calloc(graph->nb_vertices, sizeof(size_t));
	i = 0;
	depth_ = 0;
	max = malloc(sizeof(size_t));
	max[0] = 0;
	v = graph->vertices;
	if (!v->edges)
		return (0);
	{
		edge_t *e;

		if (!vertex_marked(v, indices, i))
		{
			action(v, i);
			indices[v->index] = v->index;
			i++;
			depth_ += 1;
			/*indices = realloc(indices, sizeof(size_t) * (i + 1));*/
		}
		for (e = v->edges; e; e = e->next)
		{
			depth_ = depth(e->dest, indices, i, max, action);
			depth_ = max_depth(max, depth_)[0];
		}
	}
	return (depth_);
}

int vertex_marked(vertex_t *vertex, size_t indices[], size_t size)
{
	size_t i;
	(void) vertex;
	for (i = 0; i < size; i++)
	{
		if (vertex->index == indices[vertex->index])
		{
			return (1);
		}
	}
	return (0);
}


size_t depth(vertex_t *v, size_t *indices, size_t depth_, size_t *max,
	void (*action)(const vertex_t *v, size_t depth))
{
	edge_t *e;
	size_t i = 0;

	i = sizeof(indices) / sizeof(size_t);

	if (!vertex_marked(v, indices, i))
	{
		action(v, depth_);
		indices[v->index] = v->index;
		max = max_depth(max, depth_);
		depth_++;
		i += 1;
	}
	if (!v->edges)
		return (max[0]);
	for (e = v->edges; e; e = e->next)
	{
		if (e->dest && !vertex_marked(e->dest, indices, depth_))
		{
			depth(e->dest, indices, depth_, max, action);
		}
	}
	return (max[0]);
}

size_t *max_depth(size_t *depth, size_t new_depth)
{

	if (new_depth > depth[0])
		depth[0] = new_depth;
	return (depth);
}
