#ifndef GTEST_CLOSEDRANGE_H_
#define GTEST_CLOSEDRANGE_H_

#include <stdbool.h>
#include <stddef.h>

struct ClosedRange {
    int lowerEndpoint;
    int upperEndpoint;
};

bool createClosedRange(int lowerEndpoint, int upperEndpoint, struct ClosedRange* closedRange);
bool closedRangeContains(struct ClosedRange* closedRange, int n);
void stringifyClosedRange(struct ClosedRange* closedRange, char str[], size_t len);
bool closedRangeEquals(struct ClosedRange* closedRange, struct ClosedRange* comparison);
bool closedRangeIsIncludedIn(struct ClosedRange* closedRange, struct ClosedRange* comparison);

#endif  // GTEST_CLOSEDRANGE_H_
