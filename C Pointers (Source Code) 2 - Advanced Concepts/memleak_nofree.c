#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func()
{
	char *ptr = malloc(6);
	strcpy(ptr, "hello");
	printf("Ptr: %s\n", ptr);
}

int main()
{
	func();
	return 0;
}
