/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stddef.h>
#include <stdio.h>

struct my_struct
{
    int ival;
    double dval;
};

int main()
{
    int v = 1;
    int *iptr = NULL;
//    int *iptr2;

    printf("v: %d\n", v);
    printf("iptr: %p\n", (void*) iptr);
    iptr = &v;
    printf("iptr: %p\n", (void*) iptr);
    *iptr = 2;
    printf("*iptr: %d\n", *iptr);
    printf("v: %d\n", v);

#if 0
    *iptr2 = 3; // NO! Dangling pointer
    printf("*iptr2: %d\n", *iptr2);
#endif

    return 0;
}
