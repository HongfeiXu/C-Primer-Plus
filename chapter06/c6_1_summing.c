/* 对用户输入的整数求和 */
#include <stdio.h>
int main (void)
{
    long num;
    long sum = 0L;      // 将sum初始化为零

    printf ("Please enter ana integer to be summed. ");
    printf ("(q to quit): ");
    while (scanf ("%ld", &num) == 1)     // 同时使用了scanf()的两种不同用法
    {
        sum = sum + num;
        printf ("Please enter next integer (q to quit): ");
    }
    printf ("Those integers sum to %ld.\n", sum);

    return 0;
}
