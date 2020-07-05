/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** get_amino
*/
#include "proto.h"

char get_amino_5(char a, char b, char c)
{
    if ((a == 'A' && b == 'C' && c == 'T') ||
    (a == 'A' && b == 'C' && c == 'C') ||
    (a == 'A' && b == 'C' && c == 'A') ||
    (a == 'A' && b == 'C' && c == 'G'))
        return 'T';
    if ((a == 'G' && b == 'T' && c == 'T') ||
    (a == 'G' && b == 'T' && c == 'C') ||
    (a == 'G' && b == 'T' && c == 'A') ||
    (a == 'T' && b == 'G' && c == 'G'))
        return 'V';
    if (a == 'G' && b == 'T' && c == 'T')
        return 'W';
    if (a == 'N' || b == 'N' || c == 'N')
        return 'X';
    if ((a == 'T' && b == 'A' && c == 'T') ||
    (a == 'T' && b == 'A' && c == 'C'))
        return 'Y';
}

char get_amino_4(char a, char b, char c)
{
    if ((a == 'C' && b == 'A' && c == 'A') ||
    (a == 'C' && b == 'A' && c == 'G'))
        return 'Q';
    if ((a == 'A' && b == 'G' && c == 'A') ||
    (a == 'A' && b == 'G' && c == 'G') ||
    (a == 'C' && b == 'G' && c == 'T') ||
    (a == 'C' && b == 'G' && c == 'C') ||
    (a == 'C' && b == 'G' && c == 'A') ||
    (a == 'C' && b == 'G' && c == 'G'))
        return 'R';
    if ((a == 'T' && b == 'C' && c == 'T') ||
    (a == 'T' && b == 'C' && c == 'C') ||
    (a == 'T' && b == 'C' && c == 'A') ||
    (a == 'T' && b == 'C' && c == 'G') ||
    (a == 'A' && b == 'G' && c == 'T') ||
    (a == 'A' && b == 'G' && c == 'C'))
        return 'S';
    else
        return (get_amino_5(a, b, c));
}

char get_amino_3(char a, char b, char c)
{
    if ((a == 'T' && b == 'T' && c == 'A') ||
    (a == 'T' && b == 'T' && c == 'G') ||
    (a == 'C' && b == 'T' && c == 'T') ||
    (a == 'C' && b == 'T' && c == 'C') ||
    (a == 'C' && b == 'T' && c == 'A') ||
    (a == 'C' && b == 'T' && c == 'G'))
        return 'L';
    if ((a == 'A' && b == 'T' && c == 'G'))
        return 'M';
    if ((a == 'A' && b == 'A' && c == 'T') ||
    (a == 'A' && b == 'A' && c == 'C'))
        return 'N';
    if ((a == 'C' && b == 'C' && c == 'T') ||
    (a == 'C' && b == 'C' && c == 'C') ||
    (a == 'C' && b == 'C' && c == 'A') ||
    (a == 'C' && b == 'C' && c == 'G'))
        return 'P';
    else
        return (get_amino_4(a, b, c));
}

char get_amino_2(char a, char b, char c)
{
    if ((a == 'G' && b == 'G' && c == 'T') ||
    (a == 'G' && b == 'G' && c == 'C') ||
    (a == 'G' && b == 'G' && c == 'A') ||
    (a == 'G' && b == 'G' && c == 'G'))
        return 'G';
    if ((a == 'C' && b == 'A' && c == 'T') ||
    (a == 'C' && b == 'A' && c == 'C'))
        return 'H';
    if ((a == 'A' && b == 'T' && c == 'T') ||
    (a == 'A' && b == 'T' && c == 'C') ||
    (a == 'A' && b == 'T' && c == 'A'))
        return 'I';
    if ((a == 'A' && b == 'A' && c == 'A') ||
    (a == 'A' && b == 'A' && c == 'G'))
        return 'K';
    else
        return (get_amino_3(a, b, c));
}

char get_amino(char a, char b, char c)
{
    if ((a == 'G' && b == 'C' && c == 'T') ||
    (a == 'G' && b == 'C' && c == 'C') ||
    (a == 'G' && b == 'C' && c == 'A') ||
    (a == 'G' && b == 'C' && c == 'G'))
            return 'A';
    if ((a == 'T' && b == 'G' && c == 'T') ||
    (a == 'T' && b == 'G' && c == 'C'))
        return 'C';
    if ((a == 'G' && b == 'A' && c == 'T') ||
    (a == 'G' && b == 'A' && c == 'C'))
        return 'D';
    if ((a == 'G' && b == 'A' && c == 'A') ||
    (a == 'G' && b == 'A' && c == 'G'))
        return 'E';
    if ((a == 'T' && b == 'T' && c == 'T') ||
    (a == 'T' && b == 'T' && c == 'C'))
        return 'F';
    else
        return (get_amino_2(a, b, c));
}