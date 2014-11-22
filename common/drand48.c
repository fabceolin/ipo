#include <stdlib.h>

double drand48()
{
    return rand()/(double) RAND_MAX;
}
