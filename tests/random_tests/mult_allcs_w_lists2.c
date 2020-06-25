#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
    t_list* list = create_list("int");


    int* int_data = (int*) calloc(1, sizeof(int));
    *int_data = 1;
    insert_head(list, int_data);

    int_data = (int*) calloc(1, sizeof(int));
    *int_data = 2;
    insert_head(list, int_data);

    int_data = (int*) calloc(1, sizeof(int));
    *int_data = 3;
    insert_head(list, int_data);

    int_data = (int*) calloc(1, sizeof(int));
    *int_data = 3;
    insert_head(list, int_data);

    print(list);
    clear(list);
    free(list);


    /* essa lista vai ser usada para string a partir de agora */
    list = create_list("char*");

    char* data = (char*) calloc(10, sizeof(char));
    strcpy(data, "string1");
    insert_head(list, data);

    data = (char*) calloc(10, sizeof(char));
    strcpy(data, "string2");
    insert_head(list, data);

    data = (char*) calloc(10, sizeof(char));
    strcpy(data, "tres");
    insert_head(list, data);

    data = (char*) calloc(10, sizeof(char));
    strcpy(data, "quarto");
    insert_head(list, data);

    print(list);
    clear(list);
    free(list);

    return 0;
}
