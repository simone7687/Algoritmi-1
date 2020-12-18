/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap1(void *a, void *b, size_t n);
void swap2(void *a, void *b, size_t n);
void test_swap1();
void test_swap2();

typedef struct {
            int ival;
            double dval;
            char str[10];
        } item_t;

int main()
{
    test_swap1();
    test_swap2();

    return 0;
}

void swap1(void *a, void *b, size_t n)
{
    unsigned char *pca = a;
    unsigned char *pcb = b;
    size_t i;
    if (a == b)
    {
        return;
    }
    for (i = 0;  i < n; ++i)
    {
        /* Mini-swap: swap a single byte */
        unsigned char tmp = pca[i];
        pca[i] = pcb[i];
        pcb[i] = tmp;
    }
}

void swap2(void *a, void *b, size_t n)
{
    if (a == b)
    {
        return;
    }
    void *tmp = malloc(n); /* Allocate n bytes */
    if (tmp == NULL)
    {
        perror("ERROR in swap function");
        abort();
    }
    memmove(tmp, a, n);
    memmove(a, b, n);
    memmove(b, tmp, n);
    free(tmp);
}

void test_swap1()
{
    int i1 = 3, i2 = 4;
    char s1[] = "Hello", s2[] = "World";
    double d1[] = {1.0, 2.3, 4.4}, d2[] = {5.5, 6.6, 7.7};
    item_t item1 = {3, 3.14, "pi"}, item2 = {2, 2.71, "e"};
    size_t k;

    printf("Test swap1...\n");

    printf("Before swap -> i1: %d, i2: %d\n", i1, i2);
    swap1(&i1, &i2, sizeof i1);
    printf("After swap -> i1: %d, i2: %d\n", i1, i2);

    printf("Before swap -> s1: %s, s2: %s\n", s1, s2);
    swap1(&s1, &s2, sizeof s1);
    printf("After swap -> s1: %s, s2: %s\n", s1, s2);

    for (k = 0; k < sizeof d1/sizeof d1[0]; ++k)
    {
        printf("Before swap -> d1[%lu]: %f, d2[%lu]: %f\n", k, d1[k], k, d2[k]);
    }
    swap1(&d1, &d2, sizeof d1);
    for (k = 0; k < sizeof d1/sizeof d1[0]; ++k)
    {
        printf("After swap -> d1[%lu]: %f, d2[%lu]: %f\n", k, d1[k], k, d2[k]);
    }

    printf("Before swap -> {%d, %f, %s}, {%d, %f, %s}\n", item1.ival, item1.dval, item1.str, item2.ival, item2.dval, item2.str);
    swap1(&item1, &item2, sizeof item1);
    printf("After swap -> {%d, %f, %s}, {%d, %f, %s}\n", item1.ival, item1.dval, item1.str, item2.ival, item2.dval, item2.str);
}

void test_swap2()
{
    int i1 = 3, i2 = 4;
    char s1[] = "Hello", s2[] = "World";
    double d1[] = {1.0, 2.3, 4.4}, d2[] = {5.5, 6.6, 7.7};
    item_t item1 = {3, 3.14, "pi"}, item2 = {2, 2.71, "e"};
    size_t k;

    printf("Test swap2...\n");

    printf("Before swap -> i1: %d, i2: %d\n", i1, i2);
    swap2(&i1, &i2, sizeof i1);
    printf("After swap -> i1: %d, i2: %d\n", i1, i2);

    printf("Before swap -> s1: %s, s2: %s\n", s1, s2);
    swap2(&s1, &s2, sizeof s1);
    printf("After swap -> s1: %s, s2: %s\n", s1, s2);

    for (k = 0; k < sizeof d1/sizeof d1[0]; ++k)
    {
        printf("Before swap -> d1[%lu]: %f, d2[%lu]: %f\n", k, d1[k], k, d2[k]);
    }
    swap2(&d1, &d2, sizeof d1);
    for (k = 0; k < sizeof d1/sizeof d1[0]; ++k)
    {
        printf("After swap -> d1[%lu]: %f, d2[%lu]: %f\n", k, d1[k], k, d2[k]);
    }

    printf("Before swap -> {%d, %f, %s}, {%d, %f, %s}\n", item1.ival, item1.dval, item1.str, item2.ival, item2.dval, item2.str);
    swap1(&item1, &item2, sizeof item1);
    printf("After swap -> {%d, %f, %s}, {%d, %f, %s}\n", item1.ival, item1.dval, item1.str, item2.ival, item2.dval, item2.str);
}
