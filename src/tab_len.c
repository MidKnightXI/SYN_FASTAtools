/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** tab_len
*/
#include "proto.h"

int tab_len(char **stock)
{
    int i;

    if (stock == NULL)
        return 0;
    for (i = 0; stock[i] != NULL; i++);
    return i;
}