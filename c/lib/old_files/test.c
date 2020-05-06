#include <stdio.h>
#include "charlist.h"

int main() {
	t_char_list* l = create_char_list();

	add_char_head('a', l);
	add_char_head('b', l);
	add_char_head('c', l);
	add_char_head('d', l);

	print_char_list(l);
	
	// succesfully free all allocated memory
	// acording to valgrind
	clear_char_list(l);
	free(l);

	return 0;
}