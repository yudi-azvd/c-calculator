#ifndef LIST_UTIL_H_INCLUDED
#define LIST_UTIL_H_INCLUDED

#include "list.h"

t_list* create_char_list_from(char* arr);

char* get_char_at(t_list* l, int index);

void calloc_set_int(int** data, int value);

static char char_list_str[200];

void char_list_to_str(t_list* l);


#endif // LIST_UTIL_H_INCLUDED