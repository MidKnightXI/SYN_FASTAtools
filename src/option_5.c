/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** option_5
*/
#include "proto.h"

int check_end(char *str, int i)
{
    int j = i + 3;

    if (my_strlen(str) < 6)
        return -1;
    while ((j + 2) < my_strlen(str)) {
        if (str[j] == ' ' || str[j] == '\t')
            return 0;
        if ((str[j] == 'T' && str[j + 1] == 'A' && str[j + 2] == 'A') ||
        (str[j] == 'T' && str[j + 1] == 'A' && str[j + 2] == 'G') ||
        (str[j] == 'T' && str[j + 1] == 'G' && str[j + 2] == 'A'))
            return 1;
        j++;
    }
    return 0;
}

char *get_end(char *str, int i)
{
    int j = i + 3;
    char *res = NULL;

    for (; str[j + 2] != '\0'; j++) {
        if ((str[j] == 'T' && str[j + 1] == 'A' && str[j + 2] == 'A') ||
        (str[j] == 'T' && str[j + 1] == 'A' && str[j + 2] == 'G') ||
        (str[j] == 'T' && str[j + 1] == 'G' && str[j + 2] == 'A'))
            break;
    }
    res = malloc(sizeof (char) * ((j - i) + 1));
    for (int n = i, s = 0; n < j; n++, s++)
        res[s] = str[n];
    res[(j - i)] = '\0';
    return res;
}

void sort_sequences(fast_t *f)
{
    char *str = NULL;
    char **tmp = malloc(sizeof (char *) * 2);

    tmp[0] = my_strdup("");
    tmp[1] = NULL;
    for (int i = 0, k = 1; f->stock[i] != NULL; i++) {
        for (int j = 0; f->stock[i][(j + 2)] != '\0'; j++) {
            if (f->stock[i][j] == 'A' && f->stock[i][(j + 1)] == 'T' &&
            f->stock[i][(j + 2)] == 'G' && check_end(f->stock[i], j) == 1) {
                str = get_end(f->stock[i], j);
                if (check_sim(tmp, str) == 1) {
                    tmp = realloc(tmp, sizeof (char *) * (k + 1));
                    tmp[k - 1] = strdup(str);
                    tmp[k] = NULL;
                    k++;
                }
                free(str);
            }
        }
    }
    sort_tmp(tmp);
    for (int i = 0; tmp[i] != NULL; free(tmp[i++]));
}

void write_sequences(fast_t *f)
{
    clean_stock(f);
    sort_sequences(f);
}