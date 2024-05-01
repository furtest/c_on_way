#include <stdlib.h>
#include <stdbool.h>

#include "map.h"

Map *init_map(size_t size){
	if(size <= 0){ return NULL; }
	Map *map = malloc(sizeof(Map));
	if(map == NULL){ return NULL; }
	map->size = size;
	map->map = calloc(size, sizeof(char*)); // contain the other arrays
	if(map->map == NULL){ 
		free(map);
		return NULL;
	};

	// Alloc the subarrays containing the data
	for(size_t i = 0; i < size; ++i){
		map->map[i] = calloc(size, sizeof(char));
		// If an alloc fails free everything that was allocated
		if(map->map[i] == NULL){
			for(;i > 0; --i){
				free(map->map[i]);
			}
			free(map->map);
			free(map);
			return NULL;
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
	return in_map(map, x, y) && ((bool) map->map[x][y] & 1);
}

bool in_map(const Map *map, size_t x, size_t y){
	return (x < (map->size) && y < (map->size));
}

int set_tmp(Map *map, size_t x, size_t y, bool state){
	if(map == NULL){ return 1; }
	if( ! in_map(map, x, y)){ return 2; }
	// set tmp bit to 0 and or with the state (253 = 11111101)
	map->map[x][y] = (map->map[x][y] & (char) 253) | (((char) state) << 1);
	return 0;
}
	
int tmp_to_val(Map * map, size_t x, size_t y){
	if(map == NULL){ return 1; }
	if(! in_map(map, x, y)){ return 2; }
	map->map[x][y] = (map->map[x][y] & (char) 254) | ((map->map[x][y] & 2) >> 1);
	return 0;
}
