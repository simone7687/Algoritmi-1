/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void dump_array(const void *base, size_t num_elem, size_t elem_size, void (*dump_element)(const void *, FILE *), FILE *fp);
static void dump_int(const void *p, FILE *fp);
static void dump_string(const void *p, FILE *fp);

/**
 * https://youtu.be/g4PMtXow5Lo?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=3917
 * stampo il contenuto di un array
 * *base, num_elem, elem_size: come prima
 * elem_size : sizeof(int)
 * dump_elementi: una funzione che stampa un singolo elemento dell'array cioè const void*, e lo stampa in File
 */
void dump_array(const void *base, size_t num_elem, size_t elem_size, void (*dump_element)(const void *, FILE *), FILE *fp)
{
    assert( base != NULL );
    assert( fp != NULL );

    // Implementazione
    // TODO: unsigned???? lo usato perchè lo fa anche il prof ma non so cosa sia
    unsigned char *base_char = (unsigned char *)base;

    while(num_elem) // fin quando n è diverso da 0
    {
        // ..............
        (*dump_element)((void *)base_char, fp);
        // .................
        base_char = base_char+elem_size;

        --num_elem;
    }
}

void dump_int(const void *p, FILE *fp)
{
    assert( p != NULL );
    assert( fp != NULL );

    // Implementazione
    // ......
    printf("%d ", *(int *)(p));
}

void dump_string(const void *p, FILE *fp)
{
    assert( p != NULL );
    assert( fp != NULL );

    // Implementazione
    // .......
    unsigned char *p_char = (unsigned char *)p;
    // .............
    // sizeof(char) non va bene
    for (size_t k = 0; k < sizeof(char); ++k)
        printf("%c -", (char) *(p_char+k));
}

int main()
{
    int iary[] = {1, 20, 25, 32, 76, 123};
    const char *sary[] = {"e01","e02","e03","e04","e05","e06"};
    FILE *fp = stdout;

    dump_array(iary, sizeof iary/sizeof iary[0], sizeof iary[0], dump_int, fp);
    fputc('\n', fp);
    dump_array(sary, sizeof sary/sizeof sary[0], sizeof sary[0], dump_string, fp);
    fputc('\n', fp);

    return 0;
}
