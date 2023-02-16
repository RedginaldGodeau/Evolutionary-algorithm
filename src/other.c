#include "main.h"

void get_random_str(char *str, int str_len, int new)
{
    const char letters[] = " abcdefghijklmnopqrstuwxyzvABCDEFGHIJQLMNOPQRSTUWXYZV-!?.,;1234567890:+-/\n";
    size_t i = 0;

    if (new)
        for (; i < (size_t) str_len; i++)
            str[i] = letters[rand() % strlen(letters)];
            
    else
        for (; i <= (size_t) str_len; i++)
            if (str[i] == '_')
                str[i] = letters[rand() % strlen(letters)];
}
