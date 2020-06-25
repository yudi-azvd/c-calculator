#include "util.h"

void remove_whitespace(char str[]) {
    int i, j, str_len = strlen(str);
    char* chars_nospcs = (char*) calloc(str_len, sizeof(char));

    for(i = 0, j = 0; i < str_len; i++)
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
            chars_nospcs[j++] = str[i];

    for(i = 0; i < str_len; i++)
        str[i] = chars_nospcs[i];
    str[i] = '\0';

    free(chars_nospcs);
}

void remove_illegalchars(char str[]) {
    int i, j, str_len = strlen(str);
    char* noillegal_chars = (char*) calloc(str_len, sizeof(char));

    for(i = 0, j = 0; i < str_len; i++)
        /* Pode-se acrescentar outros caracteres. */
        if(str[i] != '@'  && str[i] != '#' && str[i] != '$' &&
           str[i] != '\'' && str[i] != '\"')
            noillegal_chars[j++] = str[i];

    for(i = 0; i < str_len; i++)
        str[i] = noillegal_chars[i];
    str[i] = '\0';

    free(noillegal_chars);
}
