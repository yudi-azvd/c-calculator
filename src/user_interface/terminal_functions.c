#include "terminal_functions.h"

void ungetstr(const char *str, FILE *stream) {
    int i, len = strlen(str);

    ungetc('\n', stream);
    for(i = len-1; i >= 0; i--) {
        ungetc(str[i], stream);
    }
}


void getstr(char *str, int size, FILE *stream) {
    int i = 0;
    char c;

    while((c = getchar()) != '\n' && c != EOF && i < size) {
        str[i++] = c;
    }

    str[i] = '\0';
}

/*
void getusrinput(char *str, int size) {
    scanf("%[^\n]%*c", str);
}

*/
