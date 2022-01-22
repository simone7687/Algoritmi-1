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

#include "bst_private.h"
#include <stdio.h>
#include <stdlib.h>

/**** EXERCISE #1 - BEGIN of FUNDAMENTAL OPERATIONS 
 * Spiegazione: https://youtu.be/8fcbsu9RVYg?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=2732
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 ****/

/**
 * 
 * Soluzione: https://youtu.be/-2-AgnvImrM?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu
 */
upo_bst_t upo_bst_create(upo_bst_comparator_t key_cmp)
{
    upo_bst_t tree = malloc(sizeof(struct upo_bst_s));
    if (tree == NULL)
    {
        perror("Unable to create a binary search tree");
        abort();
    }

    tree->root = NULL;
    // TODO: questa è la funzione di comparazione per sapere se le due key sono uguali
    // se il risultato è 0 sono uguali
    // se è minore allora sara verso node->left
    // se è minore allora sara verso node->right
    tree->key_cmp = key_cmp;

    return tree;
}

// TODO: Differenza tra destroy e clear???????
void upo_bst_destroy(upo_bst_t tree, int destroy_data)
{
    if (tree != NULL)
    {
        upo_bst_clear(tree, destroy_data);
        free(tree);
    }
}

void upo_bst_clear_impl(upo_bst_node_t *node, int destroy_data)
{
    if (node != NULL)
    {
        upo_bst_clear_impl(node->left, destroy_data);
        upo_bst_clear_impl(node->right, destroy_data);

        if (destroy_data)
        {
            free(node->key);
            free(node->value);
        }

        free(node);
    }
}
void upo_bst_clear(upo_bst_t tree, int destroy_data)
{
    if (tree != NULL)
    {
        upo_bst_clear_impl(tree->root, destroy_data);
        tree->root = NULL;
    }
}

upo_bst_node_t* upo_bst_put_impl (upo_bst_node_t* node , void* key, void* value, void* oldv, upo_bst_comparator_t cmp);

void* upo_bst_put(upo_bst_t tree, void *key, void *value)
{
    if (tree != NULL)
    {
        void *oldv = NULL;

        upo_bst_comparator_t cmp = upo_bst_get_comparator(tree);

        tree->root = upo_bst_put_impl(tree->root, key, value, oldv, cmp);
        return oldv;
    }
    return NULL;
}
upo_bst_node_t* upo_bst_put_impl (upo_bst_node_t* node , void* key, void* value, void* oldv, upo_bst_comparator_t cmp)
{
    oldv = NULL;
    if (node == NULL)
    {
        node = (upo_bst_node_t *)malloc(sizeof(struct upo_bst_node_s));
        node->key = key;
        node->value = value;
        node->value = value;
        node->value = value;
        node->value = value;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else if (cmp(key, node->key) < 0)
        node->left = upo_bst_put_impl(node->left, key, value, oldv, cmp);
    else if (cmp(key, node->key) > 0)
        node->right = upo_bst_put_impl(node->right, key, value, oldv, cmp);
    else
    {
        oldv = node->value;
        node->value = value;
    }
    return node;
}

void *upo_bst_insert_impl(upo_bst_node_t *node, void *key, void *value, upo_bst_comparator_t keycmp);

void upo_bst_insert(upo_bst_t tree, void *key, void *value)
{
    if (tree != NULL)
    {
        tree->root = upo_bst_insert_impl(tree->root, key, value, tree->key_cmp);
    }
}
void *upo_bst_insert_impl(upo_bst_node_t *node, void *key, void *value, upo_bst_comparator_t keycmp)
{
    if (node == NULL)
    {
        //allocate memory for a new node
        node = (upo_bst_node_t *)malloc(sizeof(struct upo_bst_node_s));
        node->key = key;
        node->value = value;
        //childrens are null
        node->left = NULL;
        node->right = NULL;
    }
    //calls itself recursively until it finds a NULL node
    else if (keycmp(key, node->key) < 0) //key is smaller
    {
        node->left = upo_bst_insert_impl(node->left, key, value, keycmp);
    }
    else if (keycmp(key, node->key) > 0) //key is bigger
    {
        node->right = upo_bst_insert_impl(node->right, key, value, keycmp);
    }

    return node;
}

void* upo_bst_get_impl(upo_bst_node_t *node, void *key, upo_bst_comparator_t keycmp);

void* upo_bst_get(const upo_bst_t tree, const void *key)
{
    if (tree != NULL)
    {
        upo_bst_comparator_t cmp = upo_bst_get_comparator(tree);
        upo_bst_node_t *node = upo_bst_get_impl(tree->root, key, cmp);

        if (node != NULL)
            return node->value;
    }
    return NULL;
}
void* upo_bst_get_impl(upo_bst_node_t *node, void *key, upo_bst_comparator_t keycmp)
{
    if (node == NULL)
    {
        return NULL;
    }

    //key is smalled, go to the left
    if (keycmp(key, node->key) < 0)
    {
        return upo_bst_get_impl(node->left, key, keycmp);
    }
    else if (keycmp(key, node->key) > 0)
    {
        //key is bigger, go to the right
        return upo_bst_get_impl(node->right, key, keycmp);
    }
    else
        return node;
}

int upo_bst_contains(const upo_bst_t tree, const void *key)
{
    if (tree != NULL)
    {
        upo_bst_comparator_t cmp = upo_bst_get_comparator(tree);
        if (upo_bst_get_impl(tree->root, key, cmp) != NULL)
            return 1;
    }
    return 0;
}

/**
 * Ritorna il dodo maggiore dopo *node (è semplice prende l'utimo nodo a destra)
 * Soluzione: https://youtu.be/-2-AgnvImrM?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=1398
 */
upo_bst_node_t* upo_bst_max_impl(upo_bst_node_t *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            return upo_bst_max_impl(node->right);
        }
        else
        {
            return node;
        }
    }
}

upo_bst_node_t* upo_bst_delete_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t key_cmp, int destroy_data);

/**
 * elimina un nodo
 * 
 * tree: l'albero
 * key: la chiave da cancellare
 * destroy_data: se eliminare il data
 */
void upo_bst_delete(upo_bst_t tree, const void *key, int destroy_data)
{
    if (tree != NULL)
    {
        tree->root = upo_bst_delete_impl(tree->root, key, tree->key_cmp, destroy_data);
    }
}
/**
 * funzione ricorsica
 * ritorna il nodo dopo che è stato modificato, puo essere anche null
 */
upo_bst_node_t* upo_bst_delete_impl(upo_bst_node_t *node, const void *key, upo_bst_comparator_t key_cmp, int destroy_data)
{
    if (node != NULL)
    {
        if (key_cmp(key, node->key) < 0)
        {
            node->left = upo_bst_delete_impl(node->left, key, key_cmp, destroy_data);
        }
        else if (key_cmp(key, node->key) > 0)
        {
            node->right = upo_bst_delete_impl(node->right, key, key_cmp, destroy_data);
        }
        /**
         * In che modo si cancella:
         * https://youtu.be/-2-AgnvImrM?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=447
         * https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
         */
        else /* cmp == 0 */
        {
            // Se ha due figli
            if (node->left != NULL && node->right != NULL)
            {
                /*
                 * 1. Trova il nodo con la chiave massima nella sottostruttura figlia di sinistra
                 * 2. Modificare la chiave e il valore del nodo corrente con quelli del nodo con la chiave massima
                 * 3. Elimina il nodo con la chiave massima nel sottoalbero figlio di sinistra
                 * 
                 * cancello 8
                 *      8
                 * 7        10
                 *      9       11
                 * 
                 * sposto tutto l'asse left in su
                 *      10
                 * 7        11
                 *      9
                 */
                // cancllo 8
                upo_bst_node_t *max_node = upo_bst_max_impl(node->left);
                if (destroy_data)
                {
                    free(node->key);
                    free(node->value);
                }
                // lo sostituisco con 8
                node->key = max_node->key;
                node->value = max_node->value;
                // sposto tutto l'asse left in su
                node->left = upo_bst_delete_impl(node->left, node->key, key_cmp, 0);
            }
            // se non ha figli o solo uno
            else
            {
                // lo sostituisco con il figlio, se non esiste lo sostituiscop con null
                // non è ricorisivo
                upo_bst_node_t *old_node = node;
                if (node->left == NULL)
                {
                    node = node->right;
                }
                else
                {
                    node = node->left;
                }
                if (destroy_data)
                {
                    free(old_node->key);
                    free(old_node->value);
                }
                free(old_node);
            }
        }
    }
    return node;
}

size_t upo_bst_size_impl(const upo_bst_node_t *node);

/**
 * Restituisce il numero di nodi
 */
size_t upo_bst_size(const upo_bst_t tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return upo_bst_size_impl(tree->root);
}
size_t upo_bst_size_impl(const upo_bst_node_t *node)
{
    if (node == NULL)
    {
        return 0;
    }
    // solo questo è utile vedere
    return 1 + upo_bst_size_impl(node->left) + upo_bst_size_impl(node->right);
}

size_t upo_bst_height_impl (upo_bst_node_t* node);

size_t upo_bst_height(const upo_bst_t tree)
{
    if (tree != NULL)
        return upo_bst_height_impl(tree->root);
    return 0;
}
size_t upo_bst_height_impl (upo_bst_node_t* node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    else if (upo_bst_height_impl(node->right) > upo_bst_height_impl(node->left))
        return 1 + upo_bst_height_impl(node->right);
    return 1 + upo_bst_height_impl(node->left);
}

void upo_bst_traverse_in_order_impl(upo_bst_node_t *node, upo_bst_visitor_t visit, void *visit_arg);

void upo_bst_traverse_in_order(const upo_bst_t tree, upo_bst_visitor_t visit, void *visit_arg)
{
    if (tree != NULL)
        upo_bst_traverse_in_order_impl(tree->root, visit, visit_arg);
}
void upo_bst_traverse_in_order_impl(upo_bst_node_t *node, upo_bst_visitor_t visit, void *visit_arg)
{
    if (node != NULL)
    {
        upo_bst_traverse_in_order_impl(node->left, visit, visit_arg);
        visit(node->key, node->value, visit_arg);
        upo_bst_traverse_in_order_impl(node->right, visit, visit_arg);
    }
}

int upo_bst_is_empty(const upo_bst_t tree)
{
    if ((tree == NULL) || (tree->root == NULL))
        return 1;
    return 0;
}

/**** EXERCISE #1 - END of FUNDAMENTAL OPERATIONS ****/

/**** EXERCISE #2 - BEGIN of EXTRA OPERATIONS 
 * Spiegazione: https://youtu.be/8fcbsu9RVYg?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=3084
 ****/

/**
 * 
 * Soluzione: https://youtu.be/-2-AgnvImrM?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=1749
 */
void* upo_bst_min(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    fprintf(stderr, "To be implemented!\n");
    abort();
}

void* upo_bst_max(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    fprintf(stderr, "To be implemented!\n");
    abort();
}

void upo_bst_delete_min(upo_bst_t tree, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    fprintf(stderr, "To be implemented!\n");
    abort();
}

void upo_bst_delete_max(upo_bst_t tree, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    fprintf(stderr, "To be implemented!\n");
    abort();
}

const upo_bst_node_t* upo_bst_floor_impl(const upo_bst_node_t *node, const void *key, upo_bst_comparator_t key_cmp);

/**
 * Restituisce la piu chiave maggiore, minore uguale alla chiave passata per parametro, se non esiste o l'albero è nullo ritorna null
 * Soluzione: https://youtu.be/-2-AgnvImrM?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=1749
 */
void* upo_bst_floor(const upo_bst_t tree, const void *key)
{
    if (tree != NULL)
    {
        const upo_bst_node_t *node = NULL;
        node = upo_bst_floor_impl(tree->root, key, tree->key_cmp);
        if (node != NULL)
        {
            return node->key;
        }
    }
    return NULL;
}
const upo_bst_node_t* upo_bst_floor_impl(const upo_bst_node_t *node, const void *key, upo_bst_comparator_t key_cmp)
{
    if (node == NULL)
    {
        return NULL;
    }

    int cmp = key_cmp(key, node->key);
    // non lo abbiamo trovato
    // allora verso left
    if (cmp < 0)
    {
        /**
         * The key at current node is greater than the given key.
         * Search in the left subtree if there is a smaller key that is
         * also less than the given key.
         */
        return upo_bst_floor_impl(node->left, key, key_cmp);
    }
    // lo abbiamo trovato, ma prtebbe esserci una soluzione migliore
    else if (cmp > 0)
    {
        /**
         * The key at current node is lower than the given key.
         * Search in the right subtree if there is a larger key that is
         * still smaller than the given key.
         */
        const upo_bst_node_t *floor_node = NULL;
        floor_node = upo_bst_floor_impl(node->right, key, key_cmp);
        return (floor_node != NULL) ? floor_node : node;
    }
    // trovato
    else
    {
        return node;
    }
}

void* upo_bst_ceiling(const upo_bst_t tree, const void *key)
{
    if (tree == NULL)
    {
        return NULL;
    }

    upo_bst_comparator_t cmp = upo_bst_get_comparator(tree);
    upo_bst_node_t *node = tree->root;

    /* se la radice esisite */
    if (node != NULL)
    {
        upo_bst_node_t *prec = NULL;
        /* se la chiave è maggiore del massimo dell'albero*/
        if (cmp(key, upo_bst_max(tree)) > 0)
        {
            return NULL;
        }

        do
        {
            if (prec != NULL && cmp(key, node->key) > 0 && cmp(key, prec->key) < 0)
                return prec->key;
            prec = node;

            if (cmp(key, node->key) > 0)
                node = node->right;
            else if (cmp(key, node->key) < 0)
                node = node->left;
            else
                return node->key;

        } while (node != NULL);

        return prec->key;
    }
}

upo_bst_key_list_t upo_bst_keys_range(const upo_bst_t tree, const void *low_key, const void *high_key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    fprintf(stderr, "To be implemented!\n");
    abort();
}

void upo_bst_keys_impl(const upo_bst_node_t *node, upo_bst_comparator_t key_cmp, upo_bst_key_list_t *list);

/**
 * Ritorna una lista di tutti i nodi dell'albero
 */
upo_bst_key_list_t upo_bst_keys(const upo_bst_t tree)
{
    if (tree != NULL)
    {
        upo_bst_key_list_t list = NULL;
        //TODO: &list è la testa della lista
        upo_bst_keys_impl(tree->root, tree->key_cmp, &list);
        return list;
    }
    return NULL;
}
void upo_bst_keys_impl(const upo_bst_node_t *node, upo_bst_comparator_t key_cmp, upo_bst_key_list_t *list)
{
    if (node != NULL)
    {
        // Add keys to the list in-order so as to produce a sorted list
        // Add keys of the left subtree
        upo_bst_keys_impl(node->left, key_cmp, list);
        // Add key of this node
        upo_bst_key_list_node_t *list_node = NULL;
        list_node = malloc(sizeof(struct upo_bst_key_list_node_s));
        if (list_node == NULL)
        {
            perror("Unable to allocate memory for a new node of the key list");
            abort();
        }
        list_node->key = node->key;
        list_node->next = *list;
        *list = list_node;
        // Add keys of the right subtree
        upo_bst_keys_impl(node->right, key_cmp, list);
    }
}

int upo_bst_is_bst_impl(const upo_bst_node_t *node, const void *min_key, const void *max_key, upo_bst_comparator_t key_cmp);

/**
 * verificare se rispetta la proprietà di bst:
 * 
 * la cosa più semplice è verificare che il nodo attuale e destra e sinistra dono giusti
 * cie solo le tre foglie.
 * 
 * la parte problematica è:
 * https://youtu.be/-2-AgnvImrM?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=3696
 *          8
 *      3
 *  1       9
 * non è un bst, 9 è maggiore di 8
 * 
 * la soluzione è mantenere alcuni elementi precedenti min e un max
 * (non al difuori della ricorsione, verra passata per parametro)
 * 
 * inizio con
 * max = head
 * min = inf (valore inferiore a tutti)
 * 
 * quando vado a destra
 * max = nodo attuale
 * 
 * quando vado a sisistra
 * min = nodo attuale
 * 
 * es
 *          8
 *      3
 *  1       9
 * 
 * quando siamo i 1
 * max: 3
 * min: inf
 * 
 * quando siamo a 9
 * max: 8
 * min: 3
 */
int upo_bst_is_bst(const upo_bst_t tree, const void *min_key, const void *max_key)
{
    if (upo_bst_is_empty(tree))
    {
        return 1;
    }
    return upo_bst_is_bst_impl(tree->root, min_key, max_key, tree->key_cmp);
}
int upo_bst_is_bst_impl(const upo_bst_node_t *node, const void *min_key, const void *max_key, upo_bst_comparator_t key_cmp)
{
    if (node == NULL)
    {
        return 1;
    }
    if (key_cmp(node->key, min_key) < 0 || key_cmp(node->key, max_key) > 0)
    {
        return 0;
    }
    return upo_bst_is_bst_impl(node->left, min_key, node->key, key_cmp) && upo_bst_is_bst_impl(node->right, node->key, max_key, key_cmp);
}

/**** EXERCISE #2 - END of EXTRA OPERATIONS ****/

upo_bst_comparator_t upo_bst_get_comparator(const upo_bst_t tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    return tree->key_cmp;
}
