/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void func(int i, double d);
void take_func_ptr(int i, void (*func_ptr)(int, double));
void (*return_func_ptr())(int, double) ;
double radd(double v1, double v2);
double rsub(double v1, double v2);
double rprod(double v1, double v2);
double rdiv(double v1, double v2);
void string_apply(char *s, int (*func)(int c));
int int_cmp(const void *a, const void *b);


void func(int i, double d)
{
    printf("In func -> i: %d, d: %f\n", i, d);
}

void take_func_ptr(int i, void (*func_ptr)(int, double))
{
    func_ptr(i, 1.0);
}

void (*return_func_ptr())(int, double)
{
    return func;
}

double radd(double v1, double v2)
{
    return v1+v2;
}

double rsub(double v1, double v2)
{
    return v1-v2;
}

double rprod(double v1, double v2)
{
    return v1*v2;
}

double rdiv(double v1, double v2)
{
    return v1/v2;
}

void string_apply(char* s, int (*func)(int c))
{
    while (*s != '\0')
    {
        *s = func(*s);
        ++s;
    }
}

int int_cmp(const void *pkey, const void*pelem)
{
    const int *pk = pkey;
    const int *pe = pelem;

    assert( pk != NULL );
    assert( pe != NULL );

    return (*pk > *pe) ? 1 : ((*pk < *pe) ? -1 : 0);
}

int str_cmp(const void *pkey, const void *pelem)
{
    const char **pk = (const char**) pkey;
    const char **pe = (const char**) pelem;

    assert( pk != NULL );
    assert( pe != NULL );

    return strcmp(*pk, *pe);
}

int main()
{
    void (*func_ptr1)(int, double) = func;
    void (*func_ptr2)(int, double) = &func;
    int (*main_ptr)(int, char*[]) = main;
    int (*main_ptr2)(int, char*[]) = main_ptr;
    double (*operations[])(double, double) = {radd, rsub, rprod, rdiv};
    int iary[] = {1, 20, 25, 32, 76, 123};
    int search_ikey;
    int *search_ires = NULL;
    char *sary[] = {"e01","e02","e03","e04","e05","e06","e07","e08","e09","e10","e11","e12"};
    char *search_skey = NULL;
    char **search_sres = NULL;


/* NO! There is no standard way to print function pointers
    printf("func: %p\n", (void*) func);
    printf("&func: %p\n", (void*) &func);
*/
    printf("func == &func: %d\n", func == &func);
    printf("func_ptr1 == func: %d\n", func_ptr1 == func);
    printf("func_ptr2 == func: %d\n", func_ptr2 == func);
    printf("&func_ptr1: %p\n", (void*) &func_ptr1);
    printf("&func_ptr2: %p\n", (void*) &func_ptr2);

    // Different ways to call func...
    printf("Calling func(2,0)...\n");
    func(2, 0.0); // Calls func(3, 10.0)
    printf("Calling func_ptr(3,10)...\n");
    func_ptr1(3, 10.0); // Calls func(3, 10.0)
    printf("Calling (*func_ptr)(3,10)...\n");
    (*func_ptr1)(4, 20.0); // Calls func(4, 20.0)
    printf("Calling (*func)(5,30)...\n");
    (*func)(5, 30.0); // Calls func(4, 20.0)

    printf("main_ptr2 == main: %d\n", main_ptr2 == main);

    printf("Calling take_func_ptr(10)...\n");
    take_func_ptr(10, func);

    printf("Calling return_func_ptr())(100, 3)...\n");
    return_func_ptr()(100, 3.0);
    printf("Calling (*return_func_ptr())(200, 5)...\n");
    (*return_func_ptr())(200, 5.0);

    printf("operations[2](3.0, 2.0): %f\n", operations[2](3.0, 2.0));
    printf("(*operations[2])(4.0, 3.0): %f\n", (*operations[2])(4.0, 3.0));

    {
        typedef int (*char_func_t)(int);

        char_func_t ops[] = {tolower, toupper};
        char str[] = "Hello";

        printf("A string -> '%s'\n", str);

        string_apply(str, ops[0]); // -> hello
        printf("To lower case -> '%s'\n", str);

        string_apply(str, ops[1]); // -> HELLO
        printf("To upper case -> '%s'\n", str);
    }

    {
        search_ikey = 76;
        search_ires = bsearch(&search_ikey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
        printf("Key '%d' -> %s\n", search_ikey, (search_ires != NULL) ? "found" : "not found"); 
    }

    {
        search_skey = "e02";
        search_sres = bsearch(&search_skey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
        printf("Key '%s' -> %s\n", search_skey, (search_sres != NULL) ? "found" : "not found"); 
    }

    /*
     * Conversion between function pointer and data pointer (and back) are not allowed by the current ISO C standard (C11).
     * You may only cast a function pointer to another function pointer type (see 6.3.2.3 §8):
     *   "A pointer to a function of one type may be converted to a pointer to a function of another type and back again"
     * The key reason is that some architecture used to have different size for code addresses (i.e., addresses to which function pointers point to) and data addresses (i.e., addresses to which data pointers point to).
     * In practice, on most common architecture today, code and data addresses are of the same size and in the same address space.
     * However, the C standard does not define the rules for this conversion and so you should be prepared to an undefined behavior if you use this conversion.
     *
     * Implementations supporting the X/Open System Interface Extension (XSI) extension, however, do allow that an object of type void* can hold a pointer to a function.
     * The result of converting a pointer to a function into a pointer to another data type (except void*) is still undefined, however.
     * Note that compilers conforming to the ISO C standard are required to generate a warning if a conversion from a void* pointer to a function pointer is attempted.
     *
     * POSIX systems actually support this conversion as they provide functions like dlsym (https://linux.die.net/man/3/dlsym) that use this type of conversion.
     */
    {
        void *vptr = NULL;
        vptr = func;
        func_ptr1 = vptr;
    }

    return 0;
}
