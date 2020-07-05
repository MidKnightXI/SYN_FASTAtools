/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** opt_1_2
*/
#include "proto.h"

void dna_normfixer(fast_t *f, int i, int j)
{
    if (f->file[i][j] == 'a' || f->file[i][j] == 't' ||
    f->file[i][j] == 'g' || f->file[i][j] == 'c' ||
    f->file[i][j] == 'n')
        my_putchar((f->file[i][j] - 32));
    else if (f->file[i][j] == ' ' && f->file[i][j] != 'a' &&
    f->file[i][j] != 't' && f->file[i][j] != 'g' &&
    f->file[i][j] != 'c' && f->file[i][j] != 'n' &&
    f->file[i][j] != 'A' && f->file[i][j] != 'T' &&
    f->file[i][j] != 'G' && f->file[i][j] != 'C' &&
    f->file[i][j] != 'N');
    else {
        if (f->file[i][j] == 'A' || f->file[i][j] == 'G' ||
        f->file[i][j] == 'C' || f->file[i][j] == 'N' || f->file[i][j] == 'T')
            my_putchar(f->file[i][j]);
    }
}

void write_dna(fast_t * f)
{
    for (int i = 0; f->file[i] != NULL; i++) {
        if (f->file[i][0] == '>') {
            my_putstr(f->file[i]);
            my_putchar('\n');
            i++;
        }
        for (int j = 0;f->file[i][j] != '\0'; j++)
            dna_normfixer(f, i, j);
        if (f->file[(i + 1)] != NULL && f->file[(i + 1)][0] == '>')
            my_putchar('\n');
    }
    my_putchar('\n');
}

void rna_normfixer(fast_t *f, int i, int j)
{
    if (f->file[i][j] == 'a' || f->file[i][j] == 't' ||
    f->file[i][j] == 'g' || f->file[i][j] == 'c' || f->file[i][j] == 'n') {
        if (f->file[i][j] >= 't')
            my_putchar('U');
        else
            my_putchar((f->file[i][j] - 32));
    } else if (f->file[i][j] == ' ' && f->file[i][j] != 'a' &&
    f->file[i][j] != 't' && f->file[i][j] != 'g' && f->file[i][j] != 'c' &&
    f->file[i][j] != 'n' && f->file[i][j] != 'A' && f->file[i][j] != 'T' &&
    f->file[i][j] != 'G' && f->file[i][j] != 'C' && f->file[i][j] != 'N');
    else {
        if (f->file[i][j] >= 'T')
            my_putchar('U');
        else if (f->file[i][j] == 'A' || f->file[i][j] == 'G' ||
        f->file[i][j] == 'C' || f->file[i][j] == 'N')
            my_putchar(f->file[i][j]);
    }
}

void write_rna(fast_t * f)
{
    for (int i = 0; f->file[i] != NULL; i++) {
        if (f->file[i][0] == '>') {
            my_putstr(f->file[i]);
            my_putchar('\n');
            i++;
        }
        for (int j = 0;f->file[i][j] != '\0'; j++)
            rna_normfixer(f, i, j);
        if (f->file[(i + 1)] != NULL && f->file[(i + 1)][0] == '>')
            my_putchar('\n');
    }
    my_putchar('\n');
}