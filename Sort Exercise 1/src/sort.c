/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/*
 * Copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 * This file is part of UPOalglib.
 *
 * UPOalglib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * UPOalglib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with UPOalglib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include "sort_private.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// per lo swap
#include <upo/utility.h>

/**
 * https://youtu.be/Qj48bXW7zd4?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=2483
 * 
 * Il merge sort è un algoritmo di ordinamento basato su confronti che utilizza un processo di risoluzione ricorsivo, sfruttando la tecnica del Divide et Impera, che consiste nella suddivisione del problema in sottoproblemi della stessa natura di dimensione via via più piccola. Fu inventato da John von Neumann nel 1945. Una descrizione dettagliata e un'analisi della versione bottom-up dell'algoritmo apparve in un articolo di Goldstine e Neumann già nel 1948.
 * Concettualmente, l'algoritmo funziona nel seguente modo:
 * 1-   Se la sequenza da ordinare ha lunghezza 0 oppure 1 -> è già ordinata.
 *      Altrimenti:
 * 2-   La sequenza viene divisa (divide) in due metà
 *      - se la sequenza contiene un numero dispari di elementi, viene divisa in due sottosequenze di cui la prima ha un elemento in più della seconda
 * 3-   Ognuna di queste sottosequenze viene ordinata, applicando ricorsivamente l'algoritmo (impera)
 * 4-   Le due sottosequenze ordinate vengono fuse (combina). Per fare questo, si estrae ripetutamente il minimo delle due sottosequenze e lo si pone nella sequenza in uscita, che risulterà ordinata
 * 
 * 
 * Soluzione
 * https://youtu.be/aM6ZzJJ0u3o?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=537
 */

void upo_insertion_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    // Implementazione
    // TODO: ancora da implementare
}

/**
 * https://www.geeksforgeeks.org/merge-sort/
 * 
 * Il merge sort è un algoritmo di ordinamento basato su confronti che utilizza un processo di risoluzione ricorsivo, sfruttando la tecnica del Divide et Impera, che consiste nella suddivisione del problema in sottoproblemi della stessa natura di dimensione via via più piccola. Fu inventato da John von Neumann nel 1945. Una descrizione dettagliata e un'analisi della versione bottom-up dell'algoritmo apparve in un articolo di Goldstine e Neumann già nel 1948.
 * Concettualmente, l'algoritmo funziona nel seguente modo:
 * 1-   Se la sequenza da ordinare ha lunghezza 0 oppure 1 -> è già ordinata.
 *      Altrimenti:
 * 2-   La sequenza viene divisa (divide) in due metà
 *      - se la sequenza contiene un numero dispari di elementi, viene divisa in due sottosequenze di cui la prima ha un elemento in più della seconda
 * 3-   Ognuna di queste sottosequenze viene ordinata, applicando ricorsivamente l'algoritmo (impera)
 * 4-   Le due sottosequenze ordinate vengono fuse (combina). Per fare questo, si estrae ripetutamente il minimo delle due sottosequenze e lo si pone nella sequenza in uscita, che risulterà ordinata
 */
void upo_merge(void *base, size_t lo, size_t mid, size_t hi, size_t size, upo_sort_comparator_t cmp);
void upo_merge_sort_driver_topdown(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp);
void upo_merge_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    // Implementazione
    assert( base != NULL );
    // merge sort su l'intero array
    upo_merge_sort_driver_topdown(base, 0, n-1, size, cmp);
}

/**
 * è la funzione ricorsiva di merge sort
 * base: punta alla prima cella del array da ordinare
 * lo & hi: estremi del 'array
 * size: grandezza di ogni elemento del'array
 * cmp: funzione si coparazione
 */
void upo_merge_sort_driver_topdown(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    size_t mid;
    // se non si sono incrociati
    // serve a bloccare il ciclo di "Ricorsione"(Ricorsiva)
    if (lo >= hi)
    {
        return;
    }

    // l'indice centrale
    //mid = (hi+lo)/2; //WARN: do not use this assignment as it may overflow
    mid = lo+(hi-lo)/2;

    // https://www.geeksforgeeks.org/merge-sort/
    // Ordina la metà sinistra (Ricorsiva)
    upo_merge_sort_driver_topdown(base, lo, mid, size, cmp);
    // Ordina la metà destra (Ricorsiva)
    upo_merge_sort_driver_topdown(base, mid+1, hi, size, cmp);

    // fa il merge 
    upo_merge(base, lo, mid, hi, size, cmp);
}

/**
 * https://youtu.be/aM6ZzJJ0u3o?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=1102
 * è l'estensione di upo_merge_sort_driver_topdown
 * non è ricorsiva di perse ma viene fatta in modo ricorsivo perche upo_merge_sort_driver_topdown è ricorsiva
 * 
 * e per parametroo riceve sempre una stringa divisa in due metà, oglio meta è ordinata
 * esempio:
 * base[]: 1 4 7   2 6 8
 */
void upo_merge(void *base, size_t lo, size_t mid, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    // è l'array mase, noi lo utilizeremo solo da ptr[lo] a ptr[hi]
    // inseriremo i "risultati" qui dentro (cioè dentro a base)
    unsigned char *ptr = base;
    // l'array base da lo a hi
    // verra preso un consideracome per modificare l'arrray base
    unsigned char *aux = NULL;

    // aux[n]:  è ultimo elemento di aux[]
    size_t n = hi-lo+1;

    // aux[i]: iniziera da zero(ptr[lo]) fino arrivare a j
    size_t i = 0;
    // aux[j]: iniziera dalla metà+1 fino ad arriavare alla fine(ptr[hi])
    size_t j = mid+1-lo;

    //
    size_t k;
    aux = malloc(n*size);
    if (aux == NULL)
    {
        perror("Unable to allocate memory for auxiliary vector");
        abort();
    }
    // Copia base [lo], ..., base [hi] nell'array ausiliario
    // aux: destinazione
    // ptr+lo*size: sposta la posizione di ptr su lo
        // ptr: l'array di sorgete
        // lo*size: dimensione totale dei elementi da 0 a lo
    // n*size: dimensione dei elementi da lo a hi
    memcpy(aux, ptr+lo*size, n*size);


    // adesso fa il merge, cioè
    // condidera aux in due metà(ordinate) cioè aux[i]-aux[j] e aux[j]-aux[n]
    // i verra usato per la prima meta, j per la seconda

    // considera aux[i] e aux[j], il più piccolo valore viene inserito in ptr[k], poi fa k++ e 
        // aux[i] è il più piccolo i++
        // altrimenti j++
    for (k = lo; k <= hi; ++k)
    {
        if (i > (mid-lo))
        {
            memcpy(ptr+k*size, aux+j*size, size);
            ++j;
        }
        else if (j > (hi-lo))
        {
            memcpy(ptr+k*size, aux+i*size, size);
            ++i;
        }
        else if (cmp(aux+j*size, aux+i*size) < 0)
        {
            memcpy(ptr+k*size, aux+j*size, size);
            ++j;
        }
        else
        {
            memcpy(ptr+k*size, aux+i*size, size);
            ++i;
        }
    }
    // IMPORTANTE: da scrivere
    free(aux);
}


//TODO: devo ancora testarla
int upo_quick_sort_partion(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp);
void upo_quick_sort_driver_topdown(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp);
void upo_quick_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    // Implementazione
    assert( base != NULL );
    // quick sort su l'intero array
    upo_quick_sort_driver_topdown(base, 0, n-1, size, cmp);
}

void upo_quick_sort_driver_topdown(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    int pi;
    // 
    if (lo >= hi)
    {
        return;
    }

    // 
    pi = upo_quick_sort_partion(base, lo, hi, size, cmp);

    // 
    upo_quick_sort_driver_topdown(base, lo, pi-1, size, cmp);
    // 
    upo_quick_sort_driver_topdown(base, pi+1, hi, size, cmp);
}

int upo_quick_sort_partion(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    // è l'array base, noi lo utilizeremo solo da ptr[lo] a ptr[hi]
    // inseriremo i "risultati" qui dentro (cioè dentro a base)
    unsigned char *ptr = base;
    // l'array base da lo a hi
    // verra preso un consideracome per modificare l'arrray base
    // unsigned char *aux = NULL;

    // aux[n]:  è ultimo elemento di aux[]
    // size_t n = hi-lo+1;

    // aux[i]: iniziera da zero(ptr[lo]) fino arrivare a j
    size_t i = lo;
    // 
    size_t p = hi;
    // 
    size_t k;

    // aux = malloc(n*size);
    // if (aux == NULL)
    // {
    //     perror("Unable to allocate memory for auxiliary vector");
    //     abort();
    // }
    // Copia base [lo], ..., base [hi] nell'array ausiliario
    // aux: destinazione
    // ptr+lo*size: sposta la posizione di ptr su lo
        // ptr: l'array di sorgete
        // lo*size: dimensione totale dei elementi da 0 a lo
    // n*size: dimensione dei elementi da lo a hi
    // memcpy(aux, ptr+lo*size, n*size);


    // adesso fa il merge, cioè
    // condidera aux in due metà(ordinate) cioè aux[i]-aux[j] e aux[j]-aux[n]
    // i verra usato per la prima meta, j per la seconda

    // considera aux[i] e aux[j], il più piccolo valore viene inserito in ptr[k], poi fa k++ e 
        // aux[i] è il più piccolo i++
        // altrimenti j++
    for (k = lo; k <= hi; ++k)
    {
        if (cmp(ptr+k*size, ptr+p*size) < 0)
        {
            upo_swap(ptr+i*size, ptr+k*size, size);
            i++;
        }
    }
    upo_swap(ptr+i*size, ptr+hi*size, size);
    // IMPORTANTE: da scrivere
    return i;
}
