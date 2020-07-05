/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_strdup
*/
#include "proto.h"

char *my_strdup(char *str)
{
    int len;
    char *dup = NULL;

    if (str == NULL)
        return "\0";
    len = my_strlen(str);
    dup = malloc(sizeof (char) * (len + 1));
    for (int i = 0; i <= len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return dup;
}

char *my_str_cap_and_clean(char *str)
{
    int i = 0;
    char *dup = NULL;

    if (str == NULL)
        return "\0";
    dup = malloc(sizeof (char) * (my_strlen(str) + 1));
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == 'a' || str[j] == 'c' ||
        str[j] == 'g' || str[j] == 't' || str[j] == 'n') {
            dup[i] = str[j] - 32;
            i++;
        } else if (str[j] == ' ' || str[j] == '\t' ||
        (str[j] != 'A' && str[j] != 'C' &&
        str[j] != 'G' && str[j] != 'T' && str[j] != 'N')) {
        } else {
            dup[i] = str[j];
            i++;
        }
    }
    dup[i] = '\0';
    return dup;
}

char *my_str_cc(char *str)
{
    int i = 0;
    char *dup = NULL;

    if (str == NULL)
        return "\0";
    dup = malloc(sizeof (char) * (my_strlen(str) + 1));
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == 'a' || str[j] == 'c' ||
        str[j] == 'g' || str[j] == 't' || str[j] == 'n') {
            dup[i] = str[j] - 32;
            i++;
        } else if (str[j] != ' ' && (str[j] != 'A' && str[j] != 'C' &&
        str[j] != 'G' && str[j] != 'T' && str[j] != 'N')) {
        } else {
            dup[i] = str[j];
            i++;
        }
    }
    dup[i] = '\0';
    return dup;
}