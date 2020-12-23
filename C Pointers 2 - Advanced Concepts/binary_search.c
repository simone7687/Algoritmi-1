/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void *binary_search(const void *key, const void *base, size_t num_elem, size_t elem_size, int (*compar)(const void *, const void *));

static int int_cmp(const void *key, const void *elem);

static int str_cmp(const void *key, const void *elem);


int main()
{
    int iary[] = {1, 20, 25, 32, 76, 123};
    int ikey = 76;
    int inokey = 77;
    int *ires = NULL;
    int *ires_check = NULL;
    char *sary[] = {"e01","e02","e03","e04","e05","e06"};
    //char *skey = "e01";
    char *skey = "e01";
    char *snokey = "e07";
    char **sres = NULL;
    char **sres_check = NULL;

    // Case: integer array - key found
    ires = binary_search(&ikey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    ires_check = bsearch(&ikey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    assert( ires == ires_check );
    if (ires != NULL)
    {
        printf("Key %d -> found (element: %d)\n", ikey, *ires); 
    }
    else
    {
        printf("Key %d -> not found\n", ikey); 
    }

    // Case: integer array - key not found
    ires = binary_search(&inokey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    ires_check = bsearch(&inokey, iary, sizeof iary/sizeof iary[0], sizeof iary[0], int_cmp);
    assert( ires == ires_check );
    if (ires != NULL)
    {
        printf("Key %d -> found (element: %d)\n", inokey, *ires); 
    }
    else
    {
        printf("Key %d -> not found\n", inokey); 
    }

    // Case: string array - key found
    sres = binary_search(&skey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    sres_check = bsearch(&skey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    assert( sres == sres_check );
    if (sres != NULL)
    {
        printf("Key '%s' -> found (element: '%s')\n", skey, *sres); 
    }
    else
    {
        printf("Key '%s' -> not found\n", skey); 
    }

    // Case: string array - key not found
    sres = binary_search(&snokey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    sres_check = bsearch(&snokey, sary, sizeof sary/sizeof sary[0], sizeof sary[0], str_cmp);
    assert( sres == sres_check );
    if (sres != NULL)
    {
        printf("Key '%s' -> found (element: '%s')\n", snokey, *sres); 
    }
    else
    {
        printf("Key '%s' -> not found\n", snokey); 
    }

    return 0;
}

/**
 * https://youtu.be/g4PMtXow5Lo?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=3608
 * 
 * TODO TEORIA: è simele a bsearch()
 * 
 * *key: punta al valore da cercare
 * *base: punta alla prima cella del array in cui cercare
 * num_elem: numero alementi del elemento puntato da base
 * elem_size: è l'occumpazione di ogni elemento dell array
 * *compar: è la funzione di comparazione ritorna >0 se true
 * Ritorna l'elemento da cercare nella array
 *
 * TODO TEORIA: Cosa fa? prende un array lo divide in due perti controlla l'elementi dentrale di questa array,
 * se l'elemento è minore alloca continua nell lato minore (destra) altrimenti nella parte maggiore (sinistra).
 *
 * https://youtu.be/g4PMtXow5Lo?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=
 */
void *binary_search(const void *key, const void *base, size_t num_elem, size_t elem_size, int (*compar)(const void *, const void *))
{
    assert( key != NULL );
    assert( base != NULL );
    assert( compar != NULL );

    // soluzione: https://youtu.be/cgYIOriI_Ck?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=9

    // converto in puntatore a bit (in char) come di solito
    // const: l'elemento non verra modificato
    const unsigned char *pcb = base;
    // 
    size_t lo;
    size_t hi;

    void *ret = NULL;


    // Assicurati che il numero di elementi sia> 0 per evitare problemi di underflow durante l'inizializzazione della variabile "hi"
    if (num_elem == 0)
        return NULL;

    // inizio dell'array
    lo = 0;
    // fine dell'array
    hi = num_elem-1;
    // mi fermo sole se lo e hi si "intrecciano" o se ho trovato ret
    while (lo <= hi && ret == NULL)
    {
        // mi metto nel mezzo a lo hi (nel primo caso in mezzo all'array)
        size_t mid = (lo+hi)/2;

        // mi sposto di mid (numero elementi) elementi di elem_size
        const void *pmid = pcb + mid*elem_size; // -> &base[mid]
        
        // comparo l'elemento attuale e la chiave
        int cmp;
        cmp = compar(key, pmid);
        if (cmp == 0)   // trovato
        {
            ret = (void*) pmid; // È necessario un cast perché stiamo trasmettendo da un puntatore const a un puntatore non const.
        }
        else if (cmp < 0)   // la key è minore
        {
            hi = mid-1; // TODO: perchè +-1? dopo viene diveso per 2 quindi cerca 2 volte lo stesso elemento
        }
        else if (cmp > 0)   // la key è minore
        {
            lo = mid+1;
        }
        /*
         * All'inizio di ogni iterazione, può accadere che sia "lo" che
         * 'hi' è 0, quindi risulta mid == 0.
         * Ciò significa che quando 'hi' viene aggiornato (cioè hi = mid-1), incorriamo in un
         * overflow e la funzione può essere ripetuta all'infinito.
         * Per evitare ciò, controlliamo la condizione mid == 0 e quando vero we
         * rompere il ciclo.
         */
        if (mid == 0)
        {
            break;
        }
    }
    return ret;
}

int int_cmp(const void *pkey, const void *pelem)
{
    const int *pk = pkey;
    const int *pe = pelem;

    assert( pk != NULL );
    assert( pe != NULL );

    return (*pk > *pe) ? 1 : ((*pk < *pe) ? -1 : 0);
}

int str_cmp(const void *pkey, const void *pelem)
{
    const char **pk = (const char**) pkey;
    const char **pe = (const char**) pelem;

    assert( pk != NULL );
    assert( pe != NULL );

    //fprintf(stderr, "key: '%s', candidate: '%s' -> cmp: %d\n", *pk, *pe, strcmp(*pk, *pe));

    return strcmp(*pk, *pe);
}

