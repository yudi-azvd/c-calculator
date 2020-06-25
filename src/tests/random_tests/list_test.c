#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    t_list* list = create_list("int");

    printf("empty: %d\n", is_empty(list));
    int a = 5;

    insert_head(list, &a);
    int b = 2;
    insert_head(list, &b);
    printf("empty: %d\n", is_empty(list));

    print(list);

    printf("&list->head %p\n", &(list->head));
    printf("list->head %p\n", (list->head));
    printf("&(list->tail) %p\n", &(list->tail));

    remove_head(list);
    remove_head(list);
    remove_head(list);
    remove_head(list);

    printf("empty: %d\n", is_empty(list));
    printf("length: %d\n", list->length);
    printf("l->tail: %p\n", list->tail);

    b = 10;
    insert_head(list, &b);
    print(list);
    remove_head(list);

    if (!is_empty(list)) {
        exit(1);
    }

    insert_head(list, &b);
    b= 20;
    insert_head(list, &b);
    b= 8;
    insert_head(list, &b);
    b= 8;
    insert_head(list, &b);
    print(list);

    soft_clear(list);
    free(list);

    return 0;
}
