/* 
 * binary.c -- 以二进制形式输出整数
 * 因为计算出的第一个数字恰是需要在最后输出，所以需要使用一个递归函数实现。
 * 第15章给出了不用递归实现这个算法的例子。拭目以待。 
 * */
#include <stdio.h>
void to_binary (unsigned long n);

int main (void)
{
    unsigned long number;
    printf ("Enter an integer (q to quit): \n");
    while (scanf ("%lu", &number) == 1)
    {
        printf ("Binary equivalent: ");
        to_binary (number);
        putchar ('\n');
        printf ("Enter an integer (q to quit): \n");
    }

    printf ("Bye.\n");

    return 0;
}

void to_binary (unsigned long n)
{
    int r;

    r = n % 2;      // 最低位
    if (n >= 2)
        to_binary (n / 2);
    putchar ('0' + r);  // 递归后输出，已达到反序的效果（先计算出的后输出，由高位到低位输出）
    
    return;
}
