/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stddef.h>
#include <stdio.h>

void print_array1(int *a, size_t n);
void print_array2(int* const a, size_t n);
void print_array4(const int *a, size_t n);
void print_array5(const int* const a, size_t n);

// TODO: funzioni per stampare un array
void print_array1(int *a, size_t n)
{
    size_t i;

    printf("[");
    for (i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", a[i]);
    }
    printf("]");
}

void print_array2(int* const a, size_t n)
{
    size_t i;

    printf("[");
    for (i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", a[i]);
    }
    printf("]");
}

void print_array3(const int *a, size_t n)
{
    size_t i;

    printf("[");
    for (i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", a[i]);
    }
    printf("]");
}

void print_array4(const int* const a, size_t n)
{
    size_t i;

    printf("[");
    for (i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", a[i]);
    }
    printf("]");
}

int main()
{
    int ary[] = {1,2,3,4,5};
    size_t n = sizeof ary/sizeof ary[0];
    int *ptr1 = ary;
    int *ptr2 = &ary[0];
    int *ptr3 = &ary[2];

    printf("ary: %p\n", (void*) ary);
    printf("&ary: %p\n", (void*) &ary);
    printf("&ary[0]: %p\n", (void*) &ary[0]);
    printf("ptr1: %p\n", (void*) ptr1);
    printf("ptr2: %p\n", (void*) ptr2);
    printf("ary[0]: %d\n", ary[0]);
    printf("*ptr1: %d\n", *ptr1);
    printf("*ptr2: %d\n", *ptr2);
    printf("ptr1[0]: %d\n", ptr1[0]);
    printf("ptr2[0]: %d\n", ptr2[0]);
    printf("ary[3]: %d\n", ary[3]);
    printf("ptr1[3]: %d\n", ptr1[3]);
    printf("ptr2[3]: %d\n", ptr2[3]);
    printf("ary == &ary[0]: %d\n", ary == &ary[0]);
    printf("*ary == ary[0]: %d\n", *ary == ary[0]);
    printf("sizeof ary: %lu\n", sizeof ary);
    printf("sizeof ptr1: %lu\n", sizeof ptr1);
    printf("sizeof ary == sizeof(int)*%lu: %d\n", n, sizeof ary == sizeof(int)*n);
    printf("sizeof ptr1 == sizeof(int*): %d\n", sizeof ptr1 == sizeof(int*));
    printf("ptr3[0] == ary[2]: %d\n", ptr3[0] == ary[2]);
    printf("ptr3[1] == ary[3]: %d\n", ptr3[1] == ary[3]);
    printf("ptr3[-1] == ary[1]: %d\n", ptr3[-1] == ary[1]);

    printf("Print Array v1: "); print_array1(ary, n); printf("\n");
    printf("Print Array v2: "); print_array2(ary, n); printf("\n");
    printf("Print Array v3: "); print_array3(ary, n); printf("\n");
    printf("Print Array v4: "); print_array4(ary, n); printf("\n");

    return 0;
}
