/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** option_3
*/
#include "proto.h"

void completition_alg(char c)
{
    if (c == 'a' || c == 'A')
        my_putchar('T');
    if (c == 't' || c == 'T')
        my_putchar('A');
    if (c == 'c' || c == 'C')
        my_putchar('G');
    if (c == 'g' || c == 'G')
        my_putchar('C');
    if (c == 'n' || c == 'N')
        my_putchar('N');
}

void revcomp_dna(char *dna)
{
    char *rev_dna = my_revstr(dna);

    for (int i = 0; rev_dna[i] != '\0'; i++) {
        if (rev_dna[i] != 'a' && rev_dna[i] != 't' && rev_dna[i] != 'g' &&
        rev_dna[i] != 'c' && rev_dna[i] != 'n' &&
        rev_dna[i] != 'A' && rev_dna[i] != 'T' &&
        rev_dna[i] != 'G' && rev_dna[i] != 'C' && rev_dna[i] != 'N');
        else
            completition_alg(rev_dna[i]);
    }
    my_putchar('\n');
    free(rev_dna);
}

void write_revcomp(fast_t *f)
{
    char *cp = my_strdup("");

    for (int i = 0; f->file[i] != NULL; i++) {
        if (f->file[i][0] == '>') {
            my_putstr(f->file[i]);
            my_putchar('\n');
        } else {
            cp = realloc(cp, (my_strlen(cp) + my_strlen(f->file[i]) + 1));
            cp[my_strlen(cp) + my_strlen(f->file[i])] = '\0';
            cp = strcat(cp, f->file[i]);
        }
        if ((f->file[(i + 1)] != NULL && f->file[(i + 1)][0] == '>')) {
            revcomp_dna(cp);
            free(cp);
            cp = my_strdup("");
        }
    }
    revcomp_dna(cp);
    free(cp);
}