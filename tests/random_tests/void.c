#include <stdio.h>
#include <stdlib.h>


int main() {
    int a = 10;
    char str[] = "hello world!";
    void* data = &a;

    printf("%d \n", *(int *)data);

    data = str;
    printf("[%s] \n", (char *)data);

    return 0;
}
