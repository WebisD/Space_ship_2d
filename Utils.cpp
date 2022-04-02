#include "Utils.h"
#include <time.h>
#include <stdlib.h>

int Utils::RandNumber(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}