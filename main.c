#include <stdio.h>
#include <unistd.h>
#include "map.h"
#include "functions.h"

int main(void){
	Map *map = init_map(20);
	*m_el(map, 0, 1) = 1;
	*m_el(map, 1, 2) = 1;
	*m_el(map, 2, 0) = 1;
	*m_el(map, 2, 1) = 1;
	*m_el(map, 2, 2) = 1;
	for(int i = 0; i < 50; ++i){
		printf("\x1B[2J\x1B[H");
		print_map(map);
		evolve_map(map);	
		usleep(250000);
	}
	free_map(map);
	return 0;
}
