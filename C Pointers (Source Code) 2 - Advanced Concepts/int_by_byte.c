/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stddef.h>
#include <stdio.h>

int main()
{
	int v = 31275; // 0x7A2B
	int *pi = &v;
    unsigned char *pc = (unsigned char*) &v;
    size_t k;

	printf("*pi: 0x%X\n", *pi);
    for (k = 0; k < sizeof(int); ++k) // On Intel archs, the output is in little-endian order
    {
	    printf("*(pc+%lu): 0x%X\n", k, (int) *(pc+k));
    }

    return 0;
}
