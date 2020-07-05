/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** main
*/
#include "proto.h"

int isanum(char *str)
{
    int check = 0;

    if (str == NULL)
        return 84;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' && str[i] > '9')
            check++;
    }
    if (check == 0)
        return 1;
    else
        return 84;
}

int helper(void)
{
    my_putstr("USAGE\n\t./FASTAtools option [k]\n\nDESCRIPTION\n\t");
    my_putstr("option 1: read FASTA from the standard input, ");
    my_putstr("\n\t\twrite the DNA sequences to the standard output\n\t");
    my_putstr("option 2: read FASTA from the standard input, ");
    my_putstr("\n\t\twrite the RNA sequences from the standard output\n\t");
    my_putstr("option 3: read FASTA from the standard input, ");
    my_putstr("\n\t\twrite the reverse complement to the standard output\n\t");
    my_putstr("option 4: read FASTA from the standard input, ");
    my_putstr("\n\t\twrite the k-mer list to the standard output\n\t");
    my_putstr("option 5: read FASTA from the standard input, \n\t\t");
    my_putstr("write the coding sequenceslist to the standard output\n\t");
    my_putstr("option 6: read FASTA from the standard input, ");
    my_putstr("\n\t\twrite the amino acids list to the standard output\n\t");
    my_putstr("option 7: read FASTA from the standard input containing ");
    my_putstr("exactly 2 sequences,\n\t\talign them and write the result to");
    my_putstr(" the standard output\n\t");
    my_putstr("k: size of the k-mers for option 4\n");
    return 0;
}

void choose_opt(char **av, fast_t *f)
{
    if (my_atoi(av[1]) == 1)
        write_dna(f);
    if (my_atoi(av[1]) == 2)
        write_rna(f);
    if (my_atoi(av[1]) == 3)
        write_revcomp(f);
    if (my_atoi(av[1]) == 4)
        write_kmer(f);
    if (my_atoi(av[1]) == 5)
        write_sequences(f);
    if (my_atoi(av[1]) == 6)
        write_acids(f);
    if (my_atoi(av[1]) == 7)
        write_alignement(f);
}

int error_handling(int ac, char **av, fast_t *f)
{
    if (ac < 2 || ac > 3)
        return 84;
    if (my_strlen(av[1]) != 1)
        return 84;
    if (my_atoi(av[1]) < 1 || my_atoi(av[1]) > 7)
        return 84;
    if (my_atoi(av[1]) != 4 && ac > 2)
        return 84;
    if ((my_atoi(av[1]) == 4 && ac <= 2) ||
    (my_atoi(av[1]) == 4 && isanum(av[2]) == 84))
        return 84;
    if (my_atoi(av[1]) == 4 && isanum(av[2]) == 1)
        f->k = my_atoi(av[2]);
    f->file = read_file();
    if (f->file == NULL)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    fast_t *f = malloc(sizeof (fast_t));

    if (ac == 2 && my_strcmp(av[1], "-h") == 1)
        return (helper());
    else if (error_handling(ac, av, f) == 84) {
        free(f);
        return 84;
    } else
        choose_opt(av, f);
    for (int i = 0; f->file[i] != NULL; i++)
        free(f->file[i]);
    free(f);
    return 0;
}