/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


static void any_copy(void *dest, const void *src, size_t n);

/**
 * Copia i primi <n> bit di <*src> in <*dest>
 * https://youtu.be/g4PMtXow5Lo?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=3231
 */
void any_copy(void *dest, const void *src, size_t n)
{
    assert( dest != NULL );
    assert( src != NULL );

    // Implementazione

    // soluzione breve:
    // memcpy(dest, src, n)

    assert( n > 0 );

    char *pszDest = (char *)dest;
    const char *pszSource =( const char*)src;

    for (size_t i = 0; i<n; i++)
    {
        // Copia byte per byte
        *(pszDest++) = *(pszSource++);
        // oppure
        // pszDest[i] = pszSource[i];
    }
}

int main()
{
    char cary[] = "Hello, World";
    int iary[] = {1,2,3,4,5,-4,-3,-2,-1};
    float fary[] = {1.1,2.2,3.3,4.4,5.5,-4.6,-3.7,-2.8,-1.9};
    char cary_cpy[13]; /* strlen("...") + 1 (for the '\0' character) */
    int iary_cpy[9];
    float fary_cpy[9];
    size_t cary_size = sizeof cary/sizeof cary[0];
    size_t iary_size = sizeof iary/sizeof iary[0];
    size_t fary_size = sizeof fary/sizeof fary[0];
    size_t i;

    any_copy(cary_cpy, cary, cary_size);
    printf("[");
    for (i = 0; i < cary_size; ++i)
    {
        assert( cary_cpy[i] == cary[i] );

        printf("'%c' ", cary_cpy[i]);
    }
    printf("]\n");

    printf("[");
    any_copy(iary_cpy, iary, iary_size*sizeof(int));
    for (i = 0; i < iary_size; ++i)
    {
        assert( iary_cpy[i] == iary[i] );

        printf("%d ", iary_cpy[i]);
    }
    printf("]\n");

    printf("[");
    any_copy(fary_cpy, fary, fary_size*sizeof(float));
    for (i = 0; i < fary_size; ++i)
    {
        assert( fary_cpy[i] == fary[i] );

        printf("%f ", fary_cpy[i]);
    }
    printf("]\n");

    return 0;
}
