#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    const int TAM = 5;
    int* ptr_int = (int*) calloc(1, sizeof(int));
    t_list* list = create_list("int");

    int i = 0;
    while(i < TAM) {
        *ptr_int = i;
        insert_head(list, ptr_int);
        /* free(ptr_int); */
        ptr_int = (int*) calloc(1, sizeof(int));
        i++;
    }

    print(list);

    clear(list);
    free(list);
    free(ptr_int);

    return 0;
}
