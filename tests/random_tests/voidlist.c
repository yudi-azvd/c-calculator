#include <stdio.h>
#include "list.h"

int main() {

    t_node* node = create_node("hey");

    printf("%s\n", (char *)node->data);

    free(node);

    int a = 5;
    node = create_node(&a);
    printf("%d\n", *(int *)node->data);
    free(node);

    return 0;
}
