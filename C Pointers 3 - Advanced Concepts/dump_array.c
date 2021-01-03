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
    // unsigned: sigifica che non lo modificherò
    unsigned char *base_char = (unsigned char *)base;

    //..............
    for (size_t i = 0; i < num_elem; i++)
    {
        //.................
        (*dump_element)((void *)base_char, fp);
        //.................
        base_char = base_char+elem_size;

        /*
        void *ptr = &base_char[i * elem_size];
        dump_element(ptr, fp);
        */
    }
}

/**
 * Stampo un numero
 */
void dump_int(const void *p, FILE *fp)
{
    assert( p != NULL );
    assert( fp != NULL );

    // Implementazione

    // Si deve sempre convertire in char *
    unsigned char *b = (unsigned char*)p;
    // converto *b in int
    fprintf(fp, "%d ", (int)*b);

    // Altra possibile implementazione
    /*
    // TODO: Questa è più giusta ma non ho capito il *(int *)(p), perche funziona
    // converto p (senza *) in   int *
    fprintf(fp, "%d ", *(int *)(p));
    */
}

/**
 * Stampo i caratteri di una stringa
 */
void dump_string(const void *p, FILE *fp)
{
    assert( p != NULL );
    assert( fp != NULL );

    // Implementazione
    // Si deve sempre convertire in char *
    unsigned char *p_char = (unsigned char *)p;

    // TODO: Non so perche non funziona
    // TODO: al posto di scrivere e01 scrive un carattere, (non è giusto perche se faccio "-%c " cambia il carattere)
    // aggiungo ogni volta 1 a p_char, per conoscere ogni carattere
    for (size_t k = 0; k < sizeof(char); ++k)
        // converto *(p_char+k) in char
        fprintf(fp, "%c ", (char) *(p_char+k));
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
