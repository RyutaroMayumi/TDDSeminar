#include <limits.h>
#include <gtest/gtest.h>
#include <stdbool.h>
extern "C" {
#include "../src/IntegerInterval.h"
}

namespace {

//    TEST(FizzBuzzTest, Anyway) {
//         FAIL(); // 最初はわざと失敗させる　⇒　想定通りに失敗することを確認！
//     }

    TEST(IntegerIntervalTest, CreateBetween3To8) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;

        // 実行
        bool created = createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);

        // 検証
        ASSERT_EQ(true, created);
        ASSERT_EQ(lowerEndpoint, integerInterval.lowerEndpoint);
        ASSERT_EQ(upperEndpoint, integerInterval.upperEndpoint);
    }

    TEST(IntegerIntervalTest, CreateBetween8To3) {
        // 前準備
        int lowerEndpoint = 8;
        int upperEndpoint = 3;
        struct IntegerInterval integerInterval;

        // 実行
        bool created = createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);

        // 検証
        ASSERT_EQ(false, created);
    }

    TEST(IntegerIntervalTest, Contains5) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);

        // 実行
        bool contained = contains(integerInterval, 5);

        // 検証
        ASSERT_EQ(true, contained);
    }

    TEST(IntegerIntervalTest, Contains3) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);

        // 実行
        bool contained = contains(integerInterval, 3);

        // 検証
        ASSERT_EQ(true, contained);
    }

    TEST(IntegerIntervalTest, Contains10) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);

        // 実行
        bool contained = contains(integerInterval, 10);

        // 検証
        ASSERT_EQ(false, contained);
    }

    TEST(IntegerIntervalTest, ReturnString) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);
        char str[32];

        // 実行
        stringify(integerInterval, str, sizeof(str));

        // 検証
        ASSERT_STREQ("[3,8]", str);
    }

    TEST(IntegerIntervalTest, EqualToComparison) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        struct IntegerInterval comparisonInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);
        createIntegerInterval(lowerEndpoint, upperEndpoint, &comparisonInterval);

        // 実行
        bool isEqual = equal(integerInterval, comparisonInterval);

        // 検証
        ASSERT_EQ(true, isEqual);
    }

    TEST(IntegerIntervalTest, NotEqualToComparison) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        struct IntegerInterval comparisonInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);
        createIntegerInterval(2, 10, &comparisonInterval);

        // 実行
        bool isEqual = equal(integerInterval, comparisonInterval);

        // 検証
        ASSERT_EQ(false, isEqual);
    }

    TEST(IntegerIntervalTest, IncludedInComparison) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        struct IntegerInterval comparisonInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);
        createIntegerInterval(1, 10, &comparisonInterval);

        // 実行
        bool isIncluded = included(integerInterval, comparisonInterval);

        // 検証
        ASSERT_EQ(true, isIncluded);
    }

    TEST(IntegerIntervalTest, NotIncludedInComparison) {
        // 前準備
        int lowerEndpoint = 3;
        int upperEndpoint = 8;
        struct IntegerInterval integerInterval;
        struct IntegerInterval comparisonInterval;
        createIntegerInterval(lowerEndpoint, upperEndpoint, &integerInterval);
        createIntegerInterval(5, 7, &comparisonInterval);

        // 実行
        bool isIncluded = included(integerInterval, comparisonInterval);

        // 検証
        ASSERT_EQ(false, isIncluded);
    }

}
