#include "main.h"

pop *create_pop (char *str, int purcent)
{
    pop *new = malloc(sizeof(pop));
    new->str = str;
    new->purcent = purcent;

    return (new);
}

int create_list_pop (pop **list, int str_len, int new)
{
    char *str;
    size_t i = 0;
    
    for (; i < MAX_POPULATION; i++)
    {
        if (new)
        {
            str = calloc('_', str_len * sizeof(char));
            if (!str)
                return (-1);

            get_random_str(str, str_len, 1);
            list[i] = create_pop(str, 0);
        }
        else
            get_random_str(list[i]->str, str_len, 0);
    }
    return (1);
}

pop *combine_pop (pop *a, pop *b)
{
    (void) a;
    (void) b;

    return (malloc(sizeof(pop)));
}

int get_purcent (char *sentence, char *pop_str)
{
    int purcent = 0, i = 0;
    int str_len = strlen(pop_str);
    float final = 0.0;

    for (i = 0; i < str_len; i++)
        if (sentence[i] == pop_str[i])
            purcent++;
        else
            pop_str[i] = '_';
    
    final = ((float) purcent / (float) str_len) * 100;
    return ((int) final);
}

pop *get_best_pop (pop **list)
{
    pop * max = list[0];
    size_t i = 0;

    for (; i < MAX_POPULATION; i++)
    {
        if (max->purcent < list[i]->purcent)
            max = list[i];
    }
    return (max);
}

int pop_free (pop **list)
{
    int i = 0;

    for (; i < MAX_POPULATION; i++)
    {
        free(list[i]->str);
        free(list[i]);
    }
    free(list);

    return (1);
}