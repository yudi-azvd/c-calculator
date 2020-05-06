#include "list.h"

/*
    malloc não zera os bytes da espaço de memória alocado.
    Por isso calloc é usado no lugar de malloc.
*/


t_node* create_node(void* data) {
    t_node* node = (t_node*) calloc(1, sizeof(t_node));
    node->data = data;
    node->next = NULL;
    return node;
}


t_list* create_list(const char* data_type) {
    t_list* list = (t_list*) calloc(1, sizeof(t_list));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    if(strcmp("int", data_type) == 0) {
        list->print = &print_int_list;
        /* list->compare = compare; */
    }
    else if(strcmp("char", data_type) == 0) {
        list->print = &print_char_list;
        /* list->compare = compare; */
    }
    else if(strcmp("char*", data_type) == 0) {
        list->print = &print_str_list;
    }
    else if(strcmp("double", data_type) == 0) {
        list->print = &print_double_list;
    }
    else {
        printf("Not accepted argument: %s\n", data_type);
        free(list);
        exit(1);
    }

    return list;
}


void* get_head(t_list* list) {
    if(is_empty(list))
        return NULL;
    else
        return list->head->data;
}


void* get_tail(t_list* list) {
    if(is_empty(list))
        return NULL;
    else
        return list->tail->data;
}

/* get_data_at talvez seja um nome melhor */
void* get_at_index(t_list* list, int index) {
    if(!is_empty(list) && index >= 0) {
        int curr_index = 0;
        t_node* curr_node = list->head;

        while(curr_index < index) {
            curr_node = curr_node->next;
            curr_index++;

            if (curr_node == NULL) {
                return NULL;
            }
        }
        return curr_node->data;
    }
    else {
        return NULL;
    }
}


int is_empty(t_list* list) {
    return ( list == NULL
        || ((list->head == NULL)
         && (list->tail == NULL) ));
}


void print(t_list* list) {
    printf("HEAD:");
    list->print(list);
    printf("\b:TAIL\n");
}


void insert_head(t_list* list, void* data) {
    if (list == NULL || data == NULL)
        return;

    t_node* new_node = create_node(data);

    list->length++;
    if(list->head == NULL && list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = list->head;
        list->head = new_node;
    }
}


void insert_tail(t_list* list, void* data) {
    if (list == NULL || data == NULL)
        return;

    t_node* new_node = create_node(data);

    list->length++;
    if(list->head == NULL && list->tail == NULL)
        list->head = new_node;
    else
        list->tail->next = new_node;

    list->tail = new_node;
}


void* remove_head(t_list* list) {
    if (list == NULL || list->head == NULL)
        return NULL;

    t_node* to_remove = list->head;
    void* data = to_remove->data;
    list->head = list->head->next;
    free(to_remove);

    if (list->head == NULL)
        /* Fiquei um tempão pq a linha seguinte tava assim:
        list->tail == NULL; */
        list->tail = NULL;

    list->length--;
    return data;
}


void delete_head(t_list* list) {
    void* data = remove_head(list);
    free(data);
}


void clear(t_list* list) {
    while(!is_empty(list))
        delete_head(list);
}


void soft_clear(t_list* list) {
    while(!is_empty(list))
        remove_head(list);
}


void print_int_list(t_list* list) {
    t_node* curr_node = list->head;
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("%d ", *(int*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
}


void print_char_list(t_list* list) {
    t_node* curr_node = list->head;
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("'%c' ", *(char*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
}


void print_double_list(t_list* list) {
    t_node* curr_node = list->head;
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("%.2lf ", *(double*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
}


void print_str_list(t_list* list) {
    t_node* curr_node = list->head;
    if (curr_node != NULL) {
        while (curr_node != NULL) {
            printf("\"%s\" ", (char*) curr_node->data);
            curr_node = curr_node->next;
        }
    }
}


/**********************/
/* Funções para Pilha */
/**********************/
t_stack* create_stack(const char* data_type) {
    return create_list(data_type);
}


void push(t_stack* stack, void* data) {
    insert_head(stack, data);
}


void pop(t_stack* stack) {
     delete_head(stack);
}


void* soft_pop(t_stack* stack) {
    return remove_head(stack);
}


void* peek(t_stack* stack) {
    return get_head(stack);
}
