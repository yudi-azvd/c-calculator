#ifndef TERMINAL_FUNCTIONS_H_INCLUDED
#define TERMINAL_FUNCTIONS_H_INCLUDED

#include <string.h>
#include <stdio.h>

void ungetstr(const char *str, FILE *stream);

void getstr(char *str, int size, FILE *stream);

/*
void getusrinput(char *str, int size);
*/

/* void get_usr_input(void (*function)(),
                    char *str,
                    int size);
 */

#endif
