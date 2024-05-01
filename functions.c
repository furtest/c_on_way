
#include "functions.h"
#include "map.h"

int evolve_map(Map *map){
	if(map == NULL){ return 1; }
	// Set the temp bit with the next value
	for(size_t i = 0; i < size; ++i){
		for(size_t j = 0; j < size; ++j){
			// Count the number of alive neighbours
			int aliveNeigbours = 0;
			aliveNeighbours  += (int) el_stat(map, i-1, j-1);
			aliveNeighbours  += (int) el_stat(map, i-1, j);
			aliveNeighbours  += (int) el_stat(map, i-1, j+1);
			aliveNeighbours  += (int) el_stat(map, i, j-1);
			aliveNeighbours  += (int) el_stat(map, i, j+1);
			aliveNeighbours  += (int) el_stat(map, i+1, j-1);
			aliveNeighbours  += (int) el_stat(map, i+1, j);
			aliveNeighbours  += (int) el_stat(map, i+1, j+1);
			
			// We apply the rules of the game
			switch(aliveNeighbours){
				case 2:
					break;
				case 3:
					set_tmp(map, i, j, true);
					break;
				default:
					set_tmp(map, i, j, false);
					break;
			}
		}
	}
	// Set the state bit with the temp value (next value)
	for(size_t i = 0; i < size; ++i){
		for(size_t j = 0; j < size; ++j){
			tmp_to_val(map, i, j);
		}
	}
	return 0;
}
