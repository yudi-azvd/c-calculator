#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    int i = 0;
    int* ptr_int = (int*) calloc(1, sizeof(int));

    t_list* list = create_list("int");

    while(i < 4) {
        *ptr_int = i;
        insert_head(list, ptr_int);
        ptr_int = (int*) calloc(1, sizeof(int));

        i++;
    }

    print(list);
    clear(list);
    free(list);
    free(ptr_int);

    return 0;
}
