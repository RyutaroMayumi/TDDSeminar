#include "ClosedRange.h"
#include <stdio.h>

/***
 * 問題：
 * 整数閉区間を示すクラス（あるいは構造体）をつくりたい。
 * 整数閉区間オブジェクトは下端点と上端点を持ち、
 * 文字列表現も返せる（例: 下端点 3, 上端点 8 の整数閉区間の文字列表記は "[3,8]"）。
 * ただし、上端点より下端点が大きい閉区間を作ることはできない。
 * 整数の閉区間は指定した整数を含むかどうかを判定できる。
 * また、別の閉区間と等価かどうかや、完全に含まれるかどうかも判定できる。
 * 
 * ToDoリスト
 *  - [ ] 下端点と上端点を指定して、整数閉区間構造体が作れること
 *      - [ ] 下端点3, 上端点8を指定して、整数閉区間構造体が作れること　⇒　仮実装
 *      - [ ] 下端点1, 上端点10を指定して、整数閉区間構造体が作れること　⇒　三角測量
 *  - [ ] 上端点より下端点が多きときは、整数閉区間が作れないこと
 *      - [ ] 下端点8, 上端点3を指定したときは、整数閉区間が作れないこと
 *      - ※C99のboolを使用して作れたかどうかを返す
 *  - [ ] 指定した整数を含むかどうかを判定できること
 *      - [ ] 下端点3, 上端点8の整数閉区間が、5を含むと判定できること
 *      - [ ] 下端点3, 上端点8の整数閉区間が、10を含まないと判定できること
 *      - [ ] 下端点3, 上端点8の整数閉区間が、境界値(3,8)を含むと判定できること　⇒　境界値
 *  - [ ] 整数閉区間の文字列表現を取得できること
 *      - [ ] 下端点3, 上端点8の整数閉区間の文字列表現"[3,8]"を取得できること
 *      - ※char[32]（int型の最小/最大値が-2147483648/2147483647のため）に文字列を格納する
 *  - [ ] 整数閉区間が別の整数閉区間と等価であるかどうかを判定できること
 *      - [ ] （下端点,上端点）=(3,8)の整数閉区間が、(3,8)の整数閉区間と等価であると判定できること
 *      - [ ] （下端点,上端点）=(3,8)の整数閉区間が、(2,10)の整数閉区間と等価でないと判定できること
 *  - [ ] 整数閉区間が別の整数閉区間に完全に含まれるかどうかを判定できること
 *      - [ ] （下端点,上端点）=(3,8)の整数閉区間が、(1,10)の整数閉区間に完全に含まれると判定できること
 *      - [ ] （下端点,上端点）=(3,8)の整数閉区間が、(5,7)の整数閉区間に完全に含まれないと判定できること
 *      - ※比較対象が等価(3,8)の場合は含まれることが明白であるためテストから除外する
 */

int main(int argc, char** argv)
{
    return 0;
}