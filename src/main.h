#ifndef MAIN_H
#define MAIN_H
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/* Constants */
#define clr() system ("CLS || CLEAR");
#define MAX_POPULATION 100
/* Structures */
struct population
{
    char *str;
    int purcent;
};
typedef struct population pop;
/* Functions */
/* error */
int error_writer(int);
/* populations */
pop *create_pop (char *, int);
pop *combine_pop (pop *, pop *);
int create_list_pop (pop **, int, int);
int get_purcent (char *, char *);
int pop_free (pop **);
/* other */
void get_random_str(char *, int, int);
pop *get_best_pop (pop **);
#endif