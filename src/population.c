#include "main.h"

pop *create_pop (char *str, int purcent)
{
    pop *new = malloc(sizeof(pop));
    new->str = str;
    new->purcent = purcent;

    return (new);
}

pop *combine_pop (pop *a, pop *b)
{
    (void) a;
    (void) b;

    return (malloc(sizeof(pop)));
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
        {
            get_random_str(list[i]->str, str_len, 0);
            list[i]->purcent = 0;
        }
    }
    return (1);
}