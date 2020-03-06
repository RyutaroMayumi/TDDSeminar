#include <limits.h>
#include <gtest/gtest.h>
extern "C" {
#include "../src/fizzbuzz.h"
}

namespace {

//    TEST(FizzBuzzTest, Anyway) {
//         FAIL(); // 最初はわざと失敗させる　⇒　想定通りに失敗することを確認！
//     }

    // 1を渡すと文字列1に変換する
    TEST(StringifyTest, One) {
        // 前準備
        // 実行
        //char* str = Stringify(1);      // テストごとに変更する行を減らすため
        // 検証
        //ASSERT_STREQ("1", str);         // 検証のなかで実行する
        ASSERT_STREQ("1", Stringify(1));
    }

    // 2を渡すと文字列2に変換する
    TEST(StringifyTest, Two) {
        // 前準備
        // クラスの生成など　⇒　すべてのテストで共通化できる場合は共有する
        // 実行
        //char* str = Stringify(2);
        // 検証
        //ASSERT_STREQ("2", str);       // 検証のなかで実行する
        ASSERT_STREQ("2", Stringify(2));
    }

    // 3を渡すと数の代わりに「Fizz」に変換する
    TEST(StringifyTest, Three) {
        // 前準備
        // 実行
        //char* str = Stringify(3);
        // 検証
        //ASSERT_STREQ("3", str);
        ASSERT_STREQ("Fizz", Stringify(3));
    }

    // 5を渡すと数の代わりに「Buzz」に変換する
    TEST(StringifyTest, Five) {
        // 前準備
        // 実行
        //char* str = Stringify(3);
        // 検証
        //ASSERT_STREQ("3", str);
        ASSERT_STREQ("Buzz", Stringify(5));
    }

    // 3の倍数を渡すと文字列「Fizz」に変換する
    TEST(StringifyTest, MultOf3) {
        ASSERT_STREQ("Fizz", Stringify(3));
        ASSERT_STREQ("Fizz", Stringify(99));
    }

    // 5の倍数を渡すと文字列「Buzz」に変換する
    TEST(StringifyTest, MultOf5) {
        ASSERT_STREQ("Buzz", Stringify(5));
        ASSERT_STREQ("Buzz", Stringify(100));
    }

    // それ以外の数を渡すと文字列に変換する
    TEST(StringifyTest, Other) {
        ASSERT_STREQ("1", Stringify(1));
        ASSERT_STREQ("2", Stringify(2));
        ASSERT_STREQ("101", Stringify(101));    // 境界値は大事
    }

    // 0を渡すと？？ ⇒ 仕様漏れ
    // 3と5両方の倍数を渡すと文字列「FizzBuzz」に変換する
    TEST(StringifyTest, MultOf3And5) {
        ASSERT_STREQ("FizzBuzz", Stringify(15));
        ASSERT_STREQ("FizzBuzz", Stringify(0));
    }

}
