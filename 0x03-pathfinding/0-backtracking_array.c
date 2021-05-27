#include "pathfinding.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
queue_t *backtrack(int x, int y, char **map, point_t const *target, int cols, int rows, queue_t *path);
/*point_t *backtrack(size_t x, size_t y, char **seen);*/
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
	
	queue_t *path;
	int x = 0;
	int y = 0;
	static char** visited;	
	int i;
	
		path  = queue_create();
        	x = start->x;
        	y = start->y;
		visited = malloc(sizeof(char *) * rows);	
		       for (i = 0; i < rows; i++)
                		visited[i] = strdup(map[i]);

	return (backtrack(x, y, visited,target, cols, rows, path));
/*	
        printf("Checking coordinates [%d, %d]\n", x, y);
        point = malloc(sizeof(point_t));
        point->x = x;
        point->y = y;
        queue_push_front(path, point);

        x += 1;
        y += 1;
	if (x < 0 || y < 0 || x >= cols || y >= rows || visited[y][x] == '2')
		return NULL;
	printf("**%c\n", map[y][x]);	
	visited[y][x] = '2';


	if (target->x == point->x && target->y == point->y)
		return path;
	return backtracking_array(map,rows, cols, start, target);
	
	x += 1;
	return (NULL);
*/
}


queue_t *backtrack(int x, int y, char **map, point_t const *target, int rows, int cols, queue_t *path)
{
	point_t *point;
	(void) path;
	(void) target;
	if (x < 0 || y < 0 || x >= cols  || y >= rows || map[y][x] == '1' || map[y][x] == '2')
		return NULL;
	
	map[y][x] = '2';	
	
	printf("Checking coordinates [%d, %d]\n", x, y);	

	if ((target->x == x && target->y == y) ||
		backtrack(x + 1, y, map, target, cols, rows, path) ||
		backtrack(x , y + 1, map, target, cols, rows, path) ||
		backtrack(x - 1, y, map, target, cols, rows, path) ||
		backtrack(x, y - 1, map, target, cols, rows, path))
	{		
		point = malloc(sizeof(point_t));
        	point->x = x;
        	point->y = y;
        	queue_push_front(path, point);
	
		return (path);
	}
	return (NULL);
}
