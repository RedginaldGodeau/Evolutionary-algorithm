#include "main.h"

int main(int argc, char const *argv[])
{   
    srand(time(NULL));

    pop **population_list, *best_element;
    char *sentence;
    int sentence_len;

    size_t i = 0, counter = 1;

    if (argc <= 1)
        return (error_writer(0));

    sentence_len = strlen(argv[1]);
    sentence = strdup(argv[1]);   

    population_list = malloc(sizeof(pop *) * MAX_POPULATION);
    if (!population_list)
        return (error_writer(1));

    if(create_list_pop(population_list, sentence_len, 1) != 1)
        return (error_writer(2));

    do
    {
        clr();
        printf("Population Gen : %d\n", counter++);
        if(create_list_pop(population_list, sentence_len, 0) != 1)
            return (error_writer(2));

        for (i = 0; i < MAX_POPULATION; i++)
            population_list[i]->purcent = get_purcent (sentence, population_list[i]->str);

        best_element = get_best_pop (population_list);

        printf("BEST ELEMENT : %s\n ( %d )\n", best_element->str, best_element->purcent);
        for (i = 0; i < MAX_POPULATION; i++)
        {
            strcpy(population_list[i]->str, best_element->str);
            population_list[i]->purcent = 0;
        }
    } while (strstr(best_element->str, sentence) == NULL);
    
    printf("La phrase etait : %s\n", best_element->str);

    pop_free(population_list);
    free(sentence);

    return (EXIT_SUCCESS);
}