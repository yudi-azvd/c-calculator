#include <stdio.h>
#include "terminal_functions.h"


int main() {
    ungetc('u', stdin);
    char c = getchar();
    printf("c: %c\n", c);

    char str[10];
    ungetc('\n', stdin);
    ungetc('1', stdin);
    ungetc('2', stdin);
    ungetc('3', stdin);

    getstr(str, 10, stdin);
    printf("str1: %s\n", str);

    char str2[10];
    ungetstr(str, stdin);
    getstr(str2, 10, stdin);
    printf("str2: %s\n", str2);

    char str3[10];
    ungetstr(str, stdin);
    scanf("%s", str3);
    printf("str3: %s\n", str3);

    char str4[] = "olha soh";
    ungetstr(str, stdin);
    scanf("%[^\n]%*c", str4);

    printf("%d\n", strlen(str) == strlen(str4));
    int i;
    for (i = 0; i < strlen(str); i++) {
        printf("[%c] [%c]\n", str4[i], str[i]);
    }


    return 0;
}
