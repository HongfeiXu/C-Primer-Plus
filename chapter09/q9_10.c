// 用循环实现 Fibonacci ()
#include <stdio.h>
long fibonacci (int n);

int main (void)
{
    int number;
    printf ("Enter a integer number ( >= 0)(q to quit): ");
    while (scanf ("%d", &number) == 1)
    {
        printf ("fibonacci (%d) = %ld\n", number, fibonacci (number));
        printf ("Enter a integer number ( >= 0)(q to quit): ");
    }
    printf ("Bye.\n");

    return 0;
}

long fibonacci (int n)
{
    int i;
    long fib, pre, temp;        // 用 pre 保存 fib(k - 1)
    
    if (n == 1 || n == 2)
        fib = 1;
    else if (n > 2)
    {
        pre = fib = 1;
        for (i = 3; i <= n; i++)
        {
            temp = fib;         // 暂存fib的值，之后赋给pre
            fib = fib + pre;    // 1 + 1 = 2， 1 + 2 = 3， 2 + 3 = 5 ...
            pre = temp;
        }
    }
    else
        fib = -1;               // 表示不正常
    
    return fib;
}
