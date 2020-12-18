#include <stdio.h>
int main() {
    int v = 1;
    int *ptr1 = &v;
    int *ptr2;
    *ptr2 = 2; // Use of unitialized pointer -> wild pointer
    printf("*ptr1: %d\n", *ptr1);
    printf("*ptr2: %d\n", *ptr2);
    int *ptr3;
    printf("*ptr3: %d\n", *ptr3); // Use of unitialized pointer -> wild pointer
    return 0;
}
