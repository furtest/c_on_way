#include <stdlib.h>
#include <stdbool.h>

#include "map.h"

Map *init_map(size_t size){
	if(size <= 0){ return NULL; }
	Map *map = malloc(sizeof(Map));
	if(map == NULL){ return NULL; }
	map->size = size;
	map->map = calloc(size+2, sizeof(char*));
	if(map->map == NULL){ 
		free(map);
		return NULL;
	};
	for(size_t i = 0; i < size+2; ++i){
		map->map[i] = calloc(size+2, sizeof(char));	
		if(map->map[i] == NULL){
			for(;i > 0; --i){
				free(map->map[i]);
			}
			free(map->map);
			free(map);
		}
	}
	for(size_t i = 0; i < size+2; i += size+1){
		for(size_t j = 0; j < size+2; ++j){
			map->map[i][j] = 128;
		}
	}
	return map;
}

void free_map(Map *map){
	if(map == NULL){ return; }
	for(size_t i = 0; i < map->size+2; ++i){
		free(map->map[i]);
	}
	free(map->map);
	free(map);
}

char *m_el(const Map *map, size_t x, size_t y){
	return map->map[x+1] + y+1;
}

bool el_stat(const Map *map, size_t x, size_t y){
	return (bool) map->map[x+1][y+1] & 1;
}
