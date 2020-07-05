/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** read_file
*/
#include "proto.h"

char *check_line(void)
{
    char *str = NULL;
    int check = 0;
    size_t buff_size = 0;

    check = getline(&str, &buff_size, stdin);
    if (check == 0)
        return NULL;
    else if (check == -1) {
        free(str);
        return NULL;
    } else
        return str;
}

char **read_file(void)
{
    int i;
    char *temp = NULL;
    char **res = NULL;
    char *tmp = my_strdup("");

    for (i = 0; (temp = check_line()) != NULL; free(temp)) {
        tmp = realloc(tmp, (i + my_strlen(temp) + 1));
        i = i + my_strlen(temp);
        tmp[i] = '\0';
        strcat(tmp, temp);
    }
    res = str_warray(tmp);
    if (res == NULL)
        return NULL;
    free(tmp);
    return res;
}