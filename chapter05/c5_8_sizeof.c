/* 使用sizeof 运算符 */
// 使用C99的%z修饰符。如果不能使用%zd，请使用%u或%lu
#include <stdio.h>
int main (void)
{
    int n = 0;
    size_t intsize;     // C规定 sizeof 返回 size_t类型的值

    intsize = sizeof(int);
    printf ("n = %d, n has %zd bytes; all ints have %zd bytes.\n",          // %zd 为用来显示 size_t 类型值的 printf() 说明符
            n, sizeof n, intsize);

    return 0;
}
