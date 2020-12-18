/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stdio.h>

int main()
{
    int *p1 = NULL;
    const int *p2 = NULL;
    int const *p3 = NULL;
    int * const p4 = NULL;
    const int * const p5 = NULL;
    int const * const p6 = NULL;
    int v = 10;
    int *ptr = &v;

    printf("%p\n", (void*) p1);
    printf("%p\n", (void*) p2);
    printf("%p\n", (void*) p3);
    printf("%p\n", (void*) p4);
    printf("%p\n", (void*) p5);
    printf("%p\n", (void*) p6);
    printf("%p\n", (void*) NULL);
    printf("%p\n", (void*) ptr);
    printf("%p\n", (void*) &ptr);

    return 0;
}
