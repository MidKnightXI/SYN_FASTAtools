/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** fill_stock
*/
#include "proto.h"

void fill_stock(fast_t *f, char *str)
{
    static int i = 1;

    f->stock = realloc(f->stock, sizeof (char *) * (i + 1));
    f->stock[i - 1] = my_str_cap_and_clean(str);
    f->stock[i] = NULL;
    i++;
}

void fill_stock_5(fast_t *f, char *str)
{
    static int i = 1;

    f->stock = realloc(f->stock, sizeof (char *) * (i + 1));
    f->stock[i - 1] = my_str_cc(str);
    f->stock[i] = NULL;
    i++;
}

void clean_sfile(fast_t *f)
{
    char *cp = my_strdup("");

    f->stock = malloc(sizeof (char *) * 2);
    f->stock[0] = my_strdup("");
    f->stock[1] = NULL;
    for (int i = 0; f->file[i] != NULL; i++) {
        if (f->file[i][0] == '>');
        else {
            cp = realloc(cp, (my_strlen(cp) + my_strlen(f->file[i]) + 1));
            cp[my_strlen(cp) + my_strlen(f->file[i])] = '\0';
            cp = strcat(cp, f->file[i]);
        }
        if ((f->file[(i + 1)] != NULL && f->file[(i + 1)][0] == '>')) {
            fill_stock(f, cp);
            free(cp);
            cp = my_strdup("");
        }
    }
    fill_stock(f, cp);
    free(cp);
}

void clean_stock(fast_t *f)
{
    char *cp = my_strdup("");

    f->stock = malloc(sizeof (char *) * 2);
    f->stock[0] = my_strdup("");
    f->stock[1] = NULL;
    for (int i = 0; f->file[i] != NULL; i++) {
        if (f->file[i][0] == '>');
        else {
            cp = realloc(cp, (my_strlen(cp) + my_strlen(f->file[i]) + 1));
            cp[my_strlen(cp) + my_strlen(f->file[i])] = '\0';
            cp = strcat(cp, f->file[i]);
        }
        if ((f->file[(i + 1)] != NULL && f->file[(i + 1)][0] == '>')) {
            fill_stock_5(f, cp);
            free(cp);
            cp = my_strdup("");
        }
    }
    fill_stock_5(f, cp);
    free(cp);
}