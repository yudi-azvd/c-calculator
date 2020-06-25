#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    t_list* list = create_list("int");

    soft_clear(list);
    free(list);

    return 0;
}
