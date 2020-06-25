#include <stdio.h>
#include "list.h"

int main() {

    t_node* node = create_node("hey");
    /* t_node* curr_node = node; */



    free(node);

    return 0;
}
