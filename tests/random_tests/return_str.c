#include <stdio.h>
#include <stdlib.h>

char* new_str() {
    return "new string";
}

int main() {
    char* str = new_str();
    printf("%s\n", str);

    char* str2 = "olá mundo";

    /*str[0] = '1';*/
    printf("%s\n", str);
    printf("%s\n", str2);

    return 0;
}
