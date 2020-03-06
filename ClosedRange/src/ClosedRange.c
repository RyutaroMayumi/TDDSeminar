#include "ClosedRange.h"
#include <stdio.h>

bool createClosedRange(int lowerEndpoint, int upperEndpoint, struct ClosedRange* closedRange)
{
    if (lowerEndpoint > upperEndpoint) {
        return false;
    }
    closedRange->lowerEndpoint = lowerEndpoint;
    closedRange->upperEndpoint = upperEndpoint;
    return true;
}

bool closedRangeContains(struct ClosedRange* closedRange, int n)
{
    return (closedRange->lowerEndpoint <= n && n <= closedRange->upperEndpoint);
}

void stringifyClosedRange(struct ClosedRange* closedRange, char str[], size_t len)
{
    snprintf(str, len, "[%d,%d]", closedRange->lowerEndpoint, closedRange->upperEndpoint);
}

bool closedRangeEquals(struct ClosedRange* closedRange, struct ClosedRange* comparison)
{
    return ((closedRange->lowerEndpoint == comparison->lowerEndpoint) && 
            (closedRange->upperEndpoint == comparison->upperEndpoint));
}

bool closedRangeIsIncludedIn(struct ClosedRange* closedRange, struct ClosedRange* comparison)
{
    return ((closedRange->lowerEndpoint >= comparison->lowerEndpoint) &&
            (closedRange->upperEndpoint <= comparison->upperEndpoint));
}
