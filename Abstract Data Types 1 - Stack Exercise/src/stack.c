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

#include "stack_private.h"
#include <stdio.h>
#include <stdlib.h>


upo_stack_t upo_stack_create()
{
    upo_stack_t stack = malloc(sizeof(struct upo_stack_s));
    if (stack == NULL)
    {
        perror("Unable to create a stack");
        abort();
    }

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void upo_stack_destroy(upo_stack_t stack, int destroy_data)
{
    if (stack != NULL)
    {
        upo_stack_clear(stack, destroy_data);
        free(stack);
    }
}

/**
 * https://youtu.be/8f764sOcA5c?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=2600
 * 
 * 
 * Soluzione:
 * https://youtu.be/aM6ZzJJ0u3o?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=13
 */

// aggiungere un nodo alla testa
void upo_stack_push(upo_stack_t stack, void *data)
{
    if (stack != NULL)
    {
        // si alloca dello spazio per il nuovo nodo
        // TODO upo_stack_node_t: cosa è?
        upo_stack_node_t *node = malloc(sizeof(upo_stack_node_t));
        if (node == NULL)
        {
            perror("Unable to create a stack node");
            abort();
        }
        // si inseriscono i dati
        node->data = data;
        // si aggancia alla testa
        node->next = stack->top;
        stack->top = node;
        // TODO IMPORTANTE: aggiornare la dimensione dello stack
        stack->size += 1;
    }
}

// rimuovera un nodo dalla lista
void upo_stack_pop(upo_stack_t stack, int destroy_data)
{
    if (!upo_stack_is_empty(stack))
    {
        // node è l'elemento da eliminare
        upo_stack_node_t *node = stack->top;
        // cambio top
        stack->top = stack->top->next;
        // TODO IMPORTANTE: aggiornare la dimensione dello stack
        stack->size -= 1;
        // TODO: destroy_data ????
        if (destroy_data)
        {
            // libero lo spazio in data
            free(node->data);
        }
        // libero il collegamento al nodo
        free(node);
    }
}

// Ritorna la data dal top se non è NULL
void* upo_stack_top(const upo_stack_t stack)
{
    if (upo_stack_is_empty(stack))
    {
        return NULL;
    }
    return stack->top->data;
}

// controlla se è vuota
int upo_stack_is_empty(const upo_stack_t stack)
{
    if (stack == NULL)
    {
        return 1;
    }
    if (stack->size == 0)
    {
        return 1;
    }
    return 0;
}

// ritorna la dimensione dello stack
size_t upo_stack_size(const upo_stack_t stack)
{
    if (upo_stack_is_empty(stack))
    {
        return NULL;
    }
    return stack->size;
}

void upo_stack_clear(upo_stack_t stack, int destroy_data)
{
    /* TODO: HINT:
     * 1. Per ogni nodo dell'elenco memorizzato in "stack":
     * 1.1 Salva il nodo puntato da "top" in una variabile temporanea "node"
     * 1.2 Avanza il puntatore "in alto" di un nodo
     * 1.3 Se "destroy_data"! = 0, distruggi i dati utente memorizzati in "node" invocando "free (node-> data)"
     * 1.4 Distruggi "node" invocando "free (node)"
     * 2. Aggiorna la dimensione dello stack.
     */

    while(!upo_stack_is_empty(stack))
    {
        upo_stack_pop(stack, destroy_data);
    }
}
