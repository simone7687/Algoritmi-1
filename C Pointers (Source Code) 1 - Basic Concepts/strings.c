/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stdio.h>
#include <string.h>

int main()
{
    // TODO: queste possono essere tutte considerate delle stringhe nella printf
    char s[] = "Hello";
    char s2[] = {'H','e','l','l','o','\0'};
    const char* s3 = "Hello";
    char *s4 = "Hello";

    printf("%c,%c,%c,%c,%c,%c\n", s[0], s[1], s[2], s[3], s[4], s[5]);
    printf("Length: %lu\n", strlen(s));
    printf("Size: %lu\n", sizeof s);
    printf("s[0] == 'H' && & s[1] == 'e' && s[2] == 'l' && s[3] == 'l' && s[4] == 'o' && s[5] == '\\0': %d\n", s[0] == 'H' && s[1] == 'e' && s[2] == 'l' && s[3] == 'l' && s[4] == 'o' && s[5] == '\0');
    printf("strlen(s)+1 == sizeof s: %d\n", strlen(s)+1 == sizeof s);
    printf("sizeof s == sizeof s2: %d\n", sizeof s == sizeof s2);
    printf("strcmp(s, s2) == 0: %d\n", strcmp(s, s2) == 0);
    printf("strlen(s3)+1 != sizeof s3: %d\n", strlen(s3)+1 != sizeof s3);
    printf("strlen(s4)+1 != sizeof s4: %d\n", strlen(s4)+1 != sizeof s4);
    printf("sizeof s: %lu\n", sizeof s);
    printf("sizeof s2: %lu\n", sizeof s2);
    printf("sizeof s3: %lu\n", sizeof s3);
    printf("sizeof s4: %lu\n", sizeof s4);
    printf("strcmp(s, s3) == 0: %d\n", strcmp(s, s3) == 0);
    printf("strcmp(s, s4) == 0: %d\n", strcmp(s, s4) == 0);

    printf("s: %s\n", s);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);
    printf("s4: %s\n", s4);

    s[0] = 'h';
    s2[0] = 'h';
#if 0
    s3[0] = 'h'; // NO! Compiler error
#endif
#if 0
    s4[0] = 'h'; // NO! Runtime error
#endif

    return 0;
}
