#include <stdio.h>

static int *func();

int *func()
{
	int a = 1;
	return &a;
} // The scope of 'a' ends here

int main()
{
	int *ptr1 = NULL;
	int *ptr2 = NULL;

	ptr1 = func();
	*ptr1 += 1; // NO! Dangling pointer
	printf("Ptr1: %d\n", *ptr1);

	{
		int b = 2;
		ptr2 = &b;
	} // The scope of 'b' ends here
	*ptr2 += 1;
	printf("Ptr2: %d\n", *ptr2);

	return 0;
}
