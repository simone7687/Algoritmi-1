/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/**
 * \file apps/postfix_eval.c
 *
 * \brief An application to evaluate postfix mathematical expressions.
 *
 * \author Your Name
 *
 * \copyright 2015 University of Piemonte Orientale, Computer Science Institute
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
#include <ctype.h>
#include <math.h>
#include "postfix_eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <upo/stack.h>


#define MAX_LINE_LEN 256


// TODO: .....................
int isoperator(char op) 
{
    return (op == '+' ||
            op == '-' ||
            op == '*' ||
            op == '/' ||
            op == '%' ||
            op == '^');
}

// TODO: .....................
long int* eval(char op, long int op1, long int op2) 
{
    long int* tmpRes = (long int*)malloc(sizeof(long int));
    assert(isoperator(op));
    if (op == '+')  
        *tmpRes = op1 + op2;
    if (op == '-')
        *tmpRes = op1 - op2;
    if (op == '*')
        *tmpRes = op1 * op2;
    if (op == '/')
        *tmpRes = op1 / op2;
    if (op == '%')
        *tmpRes = op1 % op2;
    if (op == '^')
        *tmpRes = pow(op1, op2);
    return tmpRes;
}

/**
 * https://youtu.be/8f764sOcA5c?list=PL6EeG-tt2Es75K50cuoPYjXdNbJR4yduu&t=2870
 * 
 * convertire una espressine infisso inpost fisso:
 * 
 * 34-5+
 * 3-4+5
 * 
 * 12+3*
 * (1+2)*3
 * 
 * 1234-*+
 * 1+2*(3-4)
 * 
 * ritorna il risultato dell'espressione
 */
int eval_postfix(const char *expr, long *res)
{
    /**
     * while (l'espressione di input contiene simboli da leggere) {
     *  Leggere il simbolo successivo dall'espressione di input
     *  if (il simbolo è un numero)
     *      Spinge il simbolo sulla pila
     *  else if (il simbolo è un operatore) {
     *      Sia n il numero di argomenti che l'operatore accetta (IO: penso che n sia perforza uguale a 2)
     *      Estrae dalla pila gli n numeri
     *      Valuta l'operatore con gli n numeri come argomenti
     *      Spinge il risultato in pila
     *  } else { Errore: espressione errata }
     * }
     * if (lo stack contiene un solo valore) {
     *  Visualizza il valore
     *  return il valore come risultato dell'espressione
     * } else { Errore: espressione errata }
     */

    // Implementazione

    if (expr == NULL)
        return 0;

    // copia di espr, solito stringa che viene ciclata
    const char* data = expr;

    // risultato 
    void* tmpRes;

    // itme numerico, TODO: cosa è long int*
    long int* value;

    // sono gli ultimi 2 umeri
    long int op1, op2;

    // inizializzo lo stack
    upo_stack_t stack = upo_stack_create();

    while (*data != '\0')   // l'espressione di input contiene simboli da leggere
    {
        if (isdigit(*data)) // if (il simbolo è un numero)
        {
            value = (long int*)malloc(sizeof(long int));    // TODO: forse si può evitare
            sscanf(data, "%ld", value); // TODO: ???????????????

            upo_stack_push(stack, value);   // Spinge il risultato in pila
        }
        else if (isoperator(*data))  // il simbolo è un operatore
        {
            // Sia n il numero di argomenti che l'operatore accetta (TODO: penso che n sia perforza uguale a 2)
            // Estrae dalla pila gli n numeri
            // TODO: *((long int*): .....
            op2 = *((long int*)upo_stack_top(stack));
            upo_stack_pop(stack, 1);
            op1 = *((long int*)upo_stack_top(stack));
            upo_stack_pop(stack, 1);
            // Valuta l'operatore con gli n numeri come argomenti
            // TODO: eval: .....
            tmpRes = eval(*data, op1, op2);
            // Spinge il risultato in pila
            upo_stack_push(stack, tmpRes);
        }
        // salta gli spazzi
        else if (*data == ' ')
        {}
        else    // Errore: espressione errata
        {
            // TODO: segnersi il fprintf(stderr ...
            fprintf(stderr, "Malformed expression: %c\n", *data);
            return 0;
        }
        // passa al carattere successivo
        data++;
    }

    if (upo_stack_size(stack) == 1) // lo stack contiene un solo valore
    {
        // TODO: Visualizza il valore


        // TODO: return il valore come risultato dell'espressione
        *res = *((long int*)upo_stack_top(stack));
        upo_stack_destroy(stack, 1);
        // TODO: ritorna uno non va bene
        return 1;
    }
    else    // Errore: espressione errata
    {
        fprintf(stderr, "Malformed expression\n");
        return 0;
    }
}

void eval_lines(FILE *fp)
{
    char line[MAX_LINE_LEN];

    while (fgets(line, sizeof(line), fp))
    {
        size_t slen = strlen(line);
        int ok = 0;
        long res = 0;
        char *res_str = NULL;
        long expect_res = 0;

        /* Strips the terminating newline (if any) */
        if (slen > 0 && line[slen-1] == '\n')
        {
            line[slen-1] = '\0';
            --slen;
        }

        /* Checks if we have the expected result. In this case the input line should be: <expr>, <result> */
        res_str = strstr(line, "=>");
        if (res_str != NULL)
        {
            line[res_str-line] = '\0';
            res_str += 2;
            expect_res = atol(res_str);
        }

        ok = eval_postfix(line, &res);
        if (ok)
        {
            if (res_str != NULL)
            {
                printf("Expression '%s' -> %ld (expected: %ld -> %s)\n", line, res, expect_res, (res == expect_res) ? "OK" : "KO");
            }
            else
            {
                printf("Expression '%s' -> %ld\n", line, res);
            }
        }
        else
        {
            printf("Expression '%s' -> Malformed\n", line);
        }
    }
}

void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s -f [<filename>]\n", progname);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "-f <filename>: The full path name to the file containing strings (one for each line).\n"
                    "               If not given, strings are read from standard input.\n"
                    "               [default: standard input]\n");
    fprintf(stderr, "-h: Displays this message\n");
    fprintf(stderr, "-v: Enables output verbosity\n");
}


int main(int argc, char *argv[])
{
    char *opt_filename = NULL;
    int opt_help = 0;
    int opt_verbose = 0;
    int arg = 0;
    FILE *fp = NULL;

    for (arg = 1; arg < argc; ++arg)
    {
        if (!strcmp("-f", argv[arg]))
        {
            ++arg;
            if (arg >= argc)
            {
                fprintf(stderr, "ERROR: expected file name.\n");
                usage(argv[0]);
                return EXIT_FAILURE;
            }
            opt_filename = argv[arg];
        }
        else if (!strcmp("-h", argv[arg]))
        {
            opt_help = 1;
        }
        else if (!strcmp("-v", argv[arg]))
        {
            opt_verbose = 1;
        }
    }

    if (opt_help)
    {
        usage(argv[0]);
        return EXIT_SUCCESS;
    }

    if (opt_verbose)
    {
        printf("-- Options:\n");
        printf("* File name: %s\n", opt_filename ? opt_filename : "<not given>");
    }

 
    if (opt_filename != NULL)
    {
        fp = fopen(opt_filename, "r");
        if (fp == NULL)
        {
            perror("ERROR: cannot open input file");
            return EXIT_FAILURE;
        }
    }
    else
    {
        fp = stdin;
    }

    if (opt_verbose)
    {
        printf("-- Evaluating...\n");
    }

    eval_lines(fp);

    if (opt_filename != NULL)
    {
        fclose(fp);
    }

    return EXIT_SUCCESS;
}
