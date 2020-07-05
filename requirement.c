/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** requirement
*/
#include <stdlib.h>
#include <stdio.h>

char char_cap(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
}

char *my_strcapitalize_synthesis(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            if ((str[i - 1] < 65 || str[i - 1] > 90) && (str[i - 1] < 97 ||
            str[i] > 122) && (str[i - 1] < 48 || str[i - 1] > 57))
                str[i] = char_cap(str[i]);
    }
    return str;
}