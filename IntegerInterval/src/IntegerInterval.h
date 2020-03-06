#ifndef GTEST_INTEGERINTERVAL_H_
#define GTEST_INTEGERINTERVAL_H_

#include <stdbool.h>

struct IntegerInterval {
    int lowerEndpoint;
    int upperEndpoint;
};

bool createIntegerInterval(int lowerEndpoint, int upperEndpoint, struct IntegerInterval *integerInterval);
bool contains(struct IntegerInterval intergerInterval, int n);
void stringify(struct IntegerInterval integerInterval, char str[], int size);
bool equal(struct IntegerInterval integerInterval, struct IntegerInterval comparedInterval);
bool included(struct IntegerInterval integerInterval, struct IntegerInterval comparedInterval);

#endif  // GTEST_INTEGERINTERVAL_H_
