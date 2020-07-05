/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** option_6
*/
#include "proto.h"

char **get_option_5(fast_t *f)
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
    return tmp;
}

char *get_acid(char *seq)
{
    char *acid = malloc(sizeof (char) * ((my_strlen(seq) / 3) + 1));

    for (int i = 0, n = 0; i + 2 < my_strlen(seq); i += 3, n++)
        acid[n] = get_amino(seq[i], seq[i + 1], seq[i + 2]);
    acid[(my_strlen(seq) / 3)] = '\0';
    return acid;
}

char **option_6(char **tmp)
{
    char *str = NULL;
    char **res = malloc(sizeof (char *) * 2);

    res[0] = my_strdup("");
    res[1] = NULL;
    for (int i = 0, k = 1; tmp[i] != NULL; i++, free(str)) {
        str = get_acid(tmp[i]);
        if (check_sim(res, str) == 1) {
            res = realloc(res, sizeof (char *) * (k + 1));
            res[k - 1] = strdup(str);
            res[k] = NULL;
            k++;
        }
    }
    return res;
}

void write_acids(fast_t *f)
{
    char **tmp = NULL;
    char **res = NULL;

    clean_stock(f);
    tmp = get_option_5(f);
    res = option_6(tmp);
    for (int i = 0; tmp[i] != NULL; free(tmp[i++]));
    sort_tmp(res);
    for (int i = 0; res[i] != NULL; free(res[i++]));
}