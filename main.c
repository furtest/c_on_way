#include <stdio.h>
#include "map.h"
#include "functions.h"

int main(void){
	Map *map = init_map(10);
	print_map(map);
	puts("");
	*m_el(map, 3, 5) = 1;
	*m_el(map, 4, 5) = 1;
	*m_el(map, 5, 5) = 1;
	print_map(map);
	puts("");
	evolve_map(map);	
	print_map(map);
	puts("");
	free_map(map);
	return 0;
}
