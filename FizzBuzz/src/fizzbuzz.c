#include "fizzbuzz.h"
#include <stdio.h>

char* Stringify(int n)
{
    //return "1"; // 仮実装

    static char n_str[128] = {};

    // if (n % 3 == 0) {
    //     return "Fizz";
    // } else if (n % 5 == 0) {
    //     return "Buzz";
    // } else {
    //     sprintf(n_str, "%d", n);
    //     return n_str;
    // }
    if (n % 3 == 0 && n % 5 == 0) {
        return "FizzBuzz";
    }
    else if (n % 3 == 0) {
        return "Fizz";
    } else if (n % 5 == 0) {
        return "Buzz";
    } else {
        sprintf(n_str, "%d", n);
        return n_str;
    }
}
