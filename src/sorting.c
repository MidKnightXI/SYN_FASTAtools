/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** sorting
*/
#include "proto.h"

void sort_tmp(char **tmp)
{
    char *temp = NULL;
    int i, j;

    for (i = 0; tmp[i]; i++) {
        for (j = 0; tmp[j]; j++) {
            if (strcmp(tmp[i], tmp[j]) < 0) {
                temp = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = temp;
            }
        }
    }
    for (i = 0; tmp[i]; i++) {
        my_putstr(tmp[i]);
        my_putchar('\n');
    }
}