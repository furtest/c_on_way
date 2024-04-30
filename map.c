#include <stdlib.h>
#include <stdbool.h>

#include "map.h"

Map *init_map(size_t size){
	Map *map = malloc(sizeof(Map));
	if(map == NULL){ return NULL; }
	map->size = size;
	map->map = calloc(size, sizeof(char*));
	if(map->map == NULL){ 
		free(map);
		return NULL;
	};
	for(size_t i = 0; i < size; ++i){
		map->map[i] = calloc(size, sizeof(char));	
		if(map->map[i] == NULL){
			for(;i > 0; --i){
				free(map->map[i]);
			}
			free(map->map);
			free(map);
		}
	}
	return map;
}

void free_map(Map *map){
	if(map == NULL){ return; }
	for(size_t i = 0; i < map->size; ++i){
		free(map->map[i]);
	}
	free(map->map);
	free(map);
}

char *m_el(const Map *map, size_t x, size_t y){
	return map->map[x] + y;
}

bool el_stat(const Map *map, size_t x, size_t y){
	return (bool) map->map[x][y] & 1;
}
