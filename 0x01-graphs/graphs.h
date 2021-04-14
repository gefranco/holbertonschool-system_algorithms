#ifndef _GRAPH
#define _GRAPH
#include <stdlib.h>

typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

typedef struct vertex_s vertex_t;

typedef struct edge_s
{
	vertex_t *dest;
	struct edge_s *next;
} edge_t;

struct vertex_s
{
	size_t index;
	char *content;
	size_t nb_edges;
	edge_t  *edges;
	struct vertex_s *next;
};

typedef struct graph_s
{
	size_t nb_vertices;
	vertex_t *vertices;
} graph_t;

graph_t *graph_create(void);
vertex_t *graph_add_vertex(graph_t *graph, const char *str);
void graph_display(const graph_t *graph);
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type);
void graph_delete(graph_t *graph);
size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth));
#endif
