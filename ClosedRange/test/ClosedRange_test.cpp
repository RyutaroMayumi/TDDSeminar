#include <limits.h>
#include <gtest/gtest.h>
extern "C" {
#include "../src/ClosedRange.h"
}

namespace {

    TEST(ClosedRangeTest, CreateClosedRange3To8) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        // 実行
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        // 検証
        ASSERT_EQ(true, created);
        ASSERT_EQ(lowerEndpoint, closedRange.lowerEndpoint);
        ASSERT_EQ(upperEndpoint, closedRange.upperEndpoint);
    }

    TEST(ClosedRangeTest, CreateClosedRange1To10) {
        // 前準備
        int lowerEndpoint = 1;
        int upperEndpoint = 10;
        struct ClosedRange closedRange;
        // 実行
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        // 検証
        ASSERT_EQ(true, created);
        ASSERT_EQ(lowerEndpoint, closedRange.lowerEndpoint);
        ASSERT_EQ(upperEndpoint, closedRange.upperEndpoint);
    }

    TEST(ClosedRangeTest, CreateClosedRange8To3Failure) {
        // 前準備
        int lowerEndpoint = 8;
        int upperEndpoint = 3;
        struct ClosedRange closedRange;
        // 実行
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        // 検証
        ASSERT_EQ(false, created);
    }

    TEST(ClosedRangeTest, ClosedRange3To8Contains5) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        int n = 5;
        // 実行
        bool contained = closedRangeContains(&closedRange, n);
        // 検証
        ASSERT_EQ(true, contained);
    }

    TEST(ClosedRangeTest, ClosedRange3To8NotContains10) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        int n = 10;
        // 実行
        bool contained = closedRangeContains(&closedRange, n);
        // 検証
        ASSERT_EQ(false, contained);
    }

    TEST(ClosedRangeTest, ClosedRange3To8ContainsEndpoints) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        // 実行
        bool containedlowerEndpoint = closedRangeContains(&closedRange, lowerEndpoint);
        bool containedupperEndpoint = closedRangeContains(&closedRange, upperEndpoint);
        // 検証
        ASSERT_EQ(true, containedlowerEndpoint);
        ASSERT_EQ(true, containedupperEndpoint);
    }

    TEST(ClosedRangeTest, StringifyClosedRange3To8) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        char str[32];
        // 実行
        stringifyClosedRange(&closedRange, str, sizeof(str));
        // 検証
        ASSERT_STREQ("[3,8]", str);
    }

    TEST(ClosedRangeTest, ClosedRange3To8EqualsClosedRange3To8) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        struct ClosedRange comparison;
        createClosedRange(3, 8, &comparison);
        // 実行
        bool equal = closedRangeEquals(&closedRange, &comparison);
        // 検証
        ASSERT_EQ(true, equal);
    }

    TEST(ClosedRangeTest, ClosedRange3To8NotEqualsClosedRange2To10) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        struct ClosedRange comparison;
        createClosedRange(2, 10, &comparison);
        // 実行
        bool equal = closedRangeEquals(&closedRange, &comparison);
        // 検証
        ASSERT_EQ(false, equal);
    }

    TEST(ClosedRangeTest, ClosedRange3To8IsIncludedInClosedRange1To10) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        struct ClosedRange comparison;
        createClosedRange(1, 10, &comparison);
        // 実行
        bool isIncluded = closedRangeIsIncludedIn(&closedRange, &comparison);
        // 検証
        ASSERT_EQ(true, isIncluded);
    }

    TEST(ClosedRangeTest, ClosedRange3To8IsNotIncludedInClosedRange5To7) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct ClosedRange closedRange;
        bool created = createClosedRange(lowerEndpoint, upperEndpoint, &closedRange);
        struct ClosedRange comparison;
        createClosedRange(5, 7, &comparison);
        // 実行
        bool isIncluded = closedRangeIsIncludedIn(&closedRange, &comparison);
        // 検証
        ASSERT_EQ(false, isIncluded);
    }

}
