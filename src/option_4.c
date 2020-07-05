/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** option_4
*/
#include "proto.h"

char *get_kmer(char *src, int i, int j)
{
    char *res = malloc(sizeof (char) * (j + 1));
    int len = 0;

    for (int b = i; len < j; b++, len++)
        res[len] = src[b];
    res[len] = '\0';
    return res;
}

void write_kmer(fast_t *f)
{
    char **tmp = malloc(sizeof (char *) * 2);
    char *temp = NULL;

    clean_sfile(f);
    tmp[0] = my_strdup("");
    tmp[1] = NULL;
    for (int i = 0, k = 1; f->stock[i] != NULL; i++) {
        for (int j = 0; my_strlen(f->stock[i]) >= f-> k &&
        f->stock[i][(j + f->k - 1)] != '\0'; j++, free(temp)) {
            temp = get_kmer(f->stock[i], j, f->k);
            if (check_sim(tmp, temp) == 1) {
                tmp = realloc(tmp, sizeof (char *) * (k + 1));
                tmp[k - 1] = strdup(temp);
                tmp[k] = NULL;
                k++;
            }
        }
    }
    sort_tmp(tmp);
    for (int i = 0; tmp[i] != NULL; free(tmp[i++]));
    free(tmp);
}