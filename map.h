#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct _map {
	size_t size;
	char **map; //pointer to char array
} Map;

Map *init_map(size_t size);
void free_map(Map *map);
char *m_el(const Map *map, size_t x, size_t y);
bool el_stat(const Map *map, size_t x, size_t y);
bool in_map(const Map *map, size_t x, size_t y);

#endif
