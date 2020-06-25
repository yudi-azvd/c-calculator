#include <stdio.h>
#include "terminal_functions.h"

int main() {
    char str[15];
    ungetstr("hello world!", stdin);

    getusrinput(str, 15);

    printf("[%s]\n", str);

    return 0;
}
