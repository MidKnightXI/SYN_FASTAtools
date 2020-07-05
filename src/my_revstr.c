/*
** EPITECH PROJECT, 2020
** SYN_palindrome_2019
** File description:
** my_revstr
*/
#include "proto.h"

char *my_revstr(char *string)
{
    char *str = my_strdup(string);
    char c;
    int i = 0;
    int j = my_strlen(str) - 1;

    for (; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return str;
}