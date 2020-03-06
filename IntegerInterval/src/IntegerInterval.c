#include "IntegerInterval.h"
#include <stdio.h>

bool createIntegerInterval(int lowerEndpoint, int upperEndpoint, struct IntegerInterval *integerInterval)
{
    if (lowerEndpoint > upperEndpoint) {
        return false;
    }
    integerInterval->lowerEndpoint = lowerEndpoint;
    integerInterval->upperEndpoint = upperEndpoint;

    return true;
}

bool contains(struct IntegerInterval integerInterval, int n)
{
    //return true;
    return integerInterval.lowerEndpoint <= n && n <= integerInterval.upperEndpoint;
}

void stringify(struct IntegerInterval integerInterval, char str[], int size)
{
    snprintf(str, size, "[%d,%d]", integerInterval.lowerEndpoint, integerInterval.upperEndpoint);
}

bool equal(struct IntegerInterval integerInterval, struct IntegerInterval comparedInterval)
{
    return integerInterval.lowerEndpoint == comparedInterval.lowerEndpoint && 
        integerInterval.upperEndpoint == comparedInterval.upperEndpoint;
}

bool included(struct IntegerInterval integerInterval, struct IntegerInterval comparedInterval)
{
    return integerInterval.lowerEndpoint >= comparedInterval.lowerEndpoint && 
        integerInterval.upperEndpoint <= comparedInterval.upperEndpoint;
}
