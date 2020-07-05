/*
** EPITECH PROJECT, 2020
** SYN_FASTAtools_2019
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

// includes:

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// prototypes:

void my_putchar(char c);
int my_strlen(char *str);
int tab_len(char **str);
void my_putstr(char *str);
void my_putnbr(int nb);
int my_strcmp(char *s, char *str);
int check_sim(char **src, char *samp);
char *my_strdup(char *str);
char *my_str_cap_and_clean(char *str);
char *my_str_cc(char *str);
int my_atoi(char *str);
char *my_revstr(char *string);
char **str_warray(char const *str);
char **read_file(void);
void sort_tmp(char **tmp);
int check_end(char *str, int i);
char *get_end(char *str, int i);
char get_amino(char a, char b, char c);
void clean_sfile(fast_t *f);
void clean_stock(fast_t *f);
void fill_stock(fast_t *f, char *str);

// main functions:

void write_dna(fast_t * f);
void write_rna(fast_t * f);
void write_revcomp(fast_t *f);
void write_kmer(fast_t *f);
void write_sequences(fast_t *f);
void write_acids(fast_t *f);
void write_alignement(fast_t *f);

#endif /* !PROTO_H_ */