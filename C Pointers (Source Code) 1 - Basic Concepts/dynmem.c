/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

//static int *sptr;

int main()
{
    int *ptr;
    int *tmp_ptr;

#if 0
    *ptr = 1; // NO!
    *sptr = 2; // NO!
#endif

    ptr = malloc(N*sizeof(int));
    if (ptr == NULL)
    {
        perror("ERROR while allocating memory");
        exit(EXIT_SUCCESS);
    }

    printf("malloc - ptr: %p\n", (void*) ptr);

    tmp_ptr = realloc(ptr, 2*N*sizeof(int));
    printf("realloc - tmp: %p\n", (void*) tmp_ptr);
    if (tmp_ptr == NULL)
    {
        perror("ERROR while reallocating memory");
        exit(EXIT_SUCCESS);
    }
    ptr = tmp_ptr;
    memset(ptr, 0, 2*N*sizeof(int));
    printf("realloc - ptr: %p\n", (void*) ptr);

    printf("[");
    for (size_t i = 0; i < 2*N; ++i)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", *(ptr+i));
    }
    printf("]\n");

    free(ptr);

    // Dynamic matrix

    size_t nrows = 2;
    size_t ncols = 5;
    // Allocates memory and initiliazes the matrix to the identity matrix
    int **mat2x5 = malloc(nrows*sizeof(int*));
    for (size_t i = 0; i < nrows; ++i)
    {
        mat2x5[i] = malloc(ncols*sizeof(int));
        for (size_t j = 0; j < ncols; ++j)
        {
            mat2x5[i][j] = (i == j) ? 1 : 0;
        }
    }
    // Uses the matrix: performs scalar-matrix product and prints the result
    int scalar = 10;
    for (size_t i = 0; i < nrows; ++i)
    {
        for (size_t j = 0; j < ncols; ++j)
        {
            mat2x5[i][j] *= scalar;
        }
    }
    printf("(%lu,,%lu)[", nrows, ncols);
    for (size_t i = 0; i < nrows; ++i)
    {
        if (i > 0)
        {
            printf("; ");
        }
        for (size_t j = 0; j < ncols; ++j)
        {
            if (j > 0)
            {
                printf(", ");
            }
            printf("%d", mat2x5[i][j]);
        }
    }
    printf("]\n");
    // Deallocates memory
    for (size_t i = 0; i < nrows; ++i)
    {
        free(mat2x5[i]);
    }
    free(mat2x5);

    return 0;
}
