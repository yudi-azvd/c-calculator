#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include "../../lib/list/list.h"

int is_number(char c);

int is_operator(char c);

int is_function(char c);

int copy_to(char dest[], char src[], int start, int end);

int find_number_end(char str[], int start);

t_list* tokenize(char expression[]);

#endif
