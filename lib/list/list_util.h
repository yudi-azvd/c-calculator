#ifndef LIST_UTIL_H_INCLUDED
#define LIST_UTIL_H_INCLUDED

#include "list.h"

t_list* create_char_list_from(char* arr);

char* get_char_at(t_list* l, int index);

int get_int_at(t_list* l, int index);

void calloc_set_int(int** data, int value);

// Multiple definition of "char_list_str"
// Explicação bem detalhada:
// https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files
// Remember that you can declare a varible many times but define it only once
// https://stackoverflow.com/questions/17764661/multiple-definition-of-linker-error
// https://stackoverflow.com/questions/9049320/linking-issue-with-multiple-definition-of-compilation-error
extern char char_list_str[200];

void char_list_to_str(t_list* l);

#endif // LIST_UTIL_H_INCLUDED