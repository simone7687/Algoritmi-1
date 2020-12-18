#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *ptr = NULL;

	ptr = malloc(1);
	*ptr = 'a';
	printf("[before free] Ptr: %c\n" ,*ptr);
	free(ptr);
	*ptr += 1; // NO! Dangling pointer
	printf("[after free] Ptr: %c\n", *ptr); // We expect 'b' as output, but probably it's not

	return 0;
}
