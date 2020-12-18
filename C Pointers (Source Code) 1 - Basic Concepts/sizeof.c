/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stdio.h>
 
int main(void)
{
    float fa[6];

    // type argument:
    printf("sizeof(char)                    = %lu\n", sizeof(char)); // Always == 1
    printf("sizeof(float)                   = %lu\n", sizeof(float));
    printf("sizeof(void(*)(void))           = %lu\n", sizeof(void(*)(void)));
    printf("sizeof(char[10])                = %lu\n", sizeof(char[10]));
    printf("sizeof(float[10])               = %lu\n", sizeof(float[10]));
    printf("sizeof(float[10])/sizeof(float) = %lu\n", sizeof(float[10])/sizeof(float));
#if 0
    printf("sizeof(void(void))              = %lu\n", sizeof(void(void))); // Error: function type
    printf("sizeof(char[])                  = %lu\n", sizeof(char[])); // Error: incomplete type
#endif

    // expression argument:
    printf("sizeof 'a'                      = %lu\n", sizeof 'a'); // type of 'a' is int
#if 0
    printf("sizeof main                     = %lu\n", sizeof main); // Error: Function type
#endif
    printf("sizeof &main                    = %lu\n", sizeof &main);
    printf("sizeof \"hello\"                  = %lu\n", sizeof "hello"); // type is char[6]
    printf("sizeof fa                       = %lu\n", sizeof fa); // type of la is 6*sizeof(float)
    printf("sizeof fa / sizeof fa[0]        = %lu\n", sizeof fa/sizeof fa[0]); // type of la is 6

    return 0;
}
