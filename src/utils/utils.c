#include <stdlib.h>
#include "utils.h"

float generateRandomFloat(float min, float max){
    float number = rand() / (float) RAND_MAX;
    return min + number * ( max - min );
}

int generateRandomInt(int min, int max){
    int number = rand();
    return min + (number % ( max+1 - min ));
}


