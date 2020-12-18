#include <stdio.h>
int *callme() {
    int v = 20;
    return &v;
}
int main() {
    int *ptr = NULL;
    ptr = callme();
    // Now ptr is a dangling pointer
    printf("*ptr: %d\n", *ptr);
    return 0;
}
