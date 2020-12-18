/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stddef.h>
#include <stdio.h>

int main()
{
    char ary[] = "Hello";
    char *ptr = ary;
    char *ptr2 = NULL;
    ptrdiff_t diff;

    printf("ary: %p\n", (void*) ary);
    printf("ptr: %p\n", (void*) ptr);
    printf("ptr2: %p\n", (void*) ptr2);

    ++ptr;
    printf("++ptr -> ptr == &ary[1]: %d\n", ptr == &ary[1]);
    --ptr;
    printf("--ptr -> ptr == &ary[0]: %d\n", ptr == &ary[0]);
    ptr2 = ptr+4;
    printf("ptr2=ptr+4 -> ptr2 == &ary[4]: %d\n", ptr2 == &ary[4]);
    ptr2 -= 1;
    printf("ptr-=1 -> ptr2 == &ary[3]: %d\n", ptr2 == &ary[3]);
    diff = ptr2 - ptr;
    printf("ptr2 - ptr == %ld\n", diff);
    diff = ptr - ptr2;
    printf("ptr - ptr2 == %ld\n", diff);

    return 0;
}
