#include "main.h"

int main(int argc, char const *argv[])
{   
    srand(time(NULL));

    pop **population_list, *best_element;
    char *sentence;
    int sentence_len;

    size_t i = 0, counter = 1, i3 = 0;

    (void) population_list,(void) best_element,(void) sentence,(void) i,(void) i3,(void) counter;

    if (argc <= 1)
        return (error_writer(0));

    sentence_len = strlen(argv[1]);
    sentence = malloc(sizeof(char) * sentence_len);

    if (!sentence)
        return (error_writer(1));    

    population_list = malloc(sizeof(pop *) * MAX_POPULATION);
    if (!population_list)
        return (error_writer(1));

    if(create_list_pop(population_list, sentence_len, 1) != 1)
        return (error_writer(2));

    for (; i3 < MAX_POPULATION; i3++)
        printf("POP %d, %s\n", i3, population_list[i3]->str);


    /*while (strstr(sentence, (*population_list)[0].str) == NULL)
    {
        clr();
        printf("Population Gen : %d", counter++);
        create_list_pop(population_list, sentence_len);



    }*/
    


    return (EXIT_SUCCESS);
}