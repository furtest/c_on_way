#include <stdio.h>
#include <stdbool.h>
#include "map.h"

int main(void){
	Map *map = init_map(10);
	*m_el(map, 5, 6) = (char) 1;
	set_tmp(map, 5, 5, true);
	set_tmp(map, 5, 6, true);
	tmp_to_val(map, 5, 5);
	printf("%d\n", *m_el(map, 5, 5));
	printf("%d\n", *m_el(map, 5, 6));
	free_map(map);
	return 0;
}
