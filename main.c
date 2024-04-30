#include <stdio.h>
#include "map.h"

int main(void){
	Map *map = init_map(10);
	char *el = m_el(map, 5, 5);
	*el = *el | 1;
	printf("%d\n", el_stat(map, 5, 5));
	printf("%d\n", el_stat(map, 5, 0));
	free_map(map);
	return 0;
}
