#include "main.h"

int error_writer(int err)
{
    switch (err)
    {
    case 0:
        printf("[ERROR %d] : Argument NULL", err);
        break;
    case 1:
        printf("[ERROR %d] : Malloc ERROR", err);
        break;
    case 2:
        printf("[ERROR %d] : List Creator ERROR", err);
        break;
    
    default:
        break;
    }

    return (EXIT_FAILURE);
}