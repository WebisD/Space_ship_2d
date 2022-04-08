#include "Utils.h"
#include <time.h>
#include <stdlib.h>

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_int_distribution<int> distrX(Utils::MIN_X, Utils::MAX_X);
std::uniform_int_distribution<int> distrY(Utils::MIN_Y, Utils::MAX_Y);

int Utils::RandNumberX()
{
    int rand = distrX(eng);
    printf("Min: %d/ Max: %d\ Generated: %d\n", Utils::MIN_X, Utils::MAX_X, rand);
    return rand;
}

int Utils::RandNumberY()
{
    int rand = distrY(eng);
    printf("Min: %d/ Max: %d\ Generated: %d\n", Utils::MIN_Y, Utils::MAX_Y, rand);
    return rand;
}