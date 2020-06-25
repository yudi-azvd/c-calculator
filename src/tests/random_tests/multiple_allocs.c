#include <stdio.h>
#include <stdlib.h>

int main() {
    int* int_ptr1 = (int*) calloc(1, sizeof(int));
    *int_ptr1 = 1;
    int* int_ptr2 = int_ptr1;

    printf("int_ptr1 : %p\n", int_ptr1);
    printf("int_ptr2: %p\n", int_ptr2);

    printf("%d\n", *(int_ptr1));
    printf("%d\n", *(int_ptr2));

    int_ptr1 = (int*) calloc(1, sizeof(int));

    free(int_ptr1);
    free(int_ptr2);
    return 0;
}
