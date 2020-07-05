/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** my_strcmp.c
*/
#include "proto.h"

int my_strcmp(char *s, char *str)
{
    int letter = 0;

    if (my_strlen(s) != my_strlen(str) || str == NULL || s == NULL)
        return -1;
    for (int i = 0; str[i]; i++) {
        if (s[i] != str[i])
            letter++;
    }
    if (letter != 0) {
        return -1;
    } else {
        return 1;
    }
}

int check_sim(char **src, char *samp)
{
    int error = 0;

    if (src == NULL || samp == NULL)
        return -1;
    for (int i = 0; src[i]; i++) {
        if (my_strcmp(src[i], samp) == 1)
            error++;
    }
    if (error >= 1)
        return 0;
    else
        return 1;
}