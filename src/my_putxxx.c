/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** my_putstr
*/
#include "proto.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int len = 0;

    if (str == NULL)
        return 0;
    for (; str[len]; len++);
    return len;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putnbr(int nb)
{
    int dc = 1;

    if (nb == -2147483648)
        write(1, "-2147483648", 12);
    else {
        if (nb < 0) {
            my_putchar('-');
            nb = nb * -1;
        }
        while ((nb / dc) >= 10) {
            dc = dc * 10;
        }
        while (dc > 0) {
            my_putchar((nb / dc) % 10 + '0');
            dc /= 10;
        }
    }
}