// divisors.c -- 使用嵌套 if 显示一个数的约数
#include <stdio.h>
#include <stdbool.h>
int main (void)
{
    unsigned long num;
    unsigned long div;
    bool isPrime;

    printf ("Please enter an integer for analysis: ");
    printf ("Enter q to quit.\n");
    while (scanf ("%ld", &num) == 1)
    {
        for (div = 2, isPrime = true; div * div < num; div++)       // isPrime 开始赋值为 true
        {
            if (num % div == 0)
            {
                if (num * num != div)
                    printf ("%lu is divisible by %lu and %lu.\n", 
                            num, div, num / div);
                else
                    printf ("%lu is divisible by %lu.\n", num, div);
                isPrime = false;
            }

        }
        if (isPrime)
            printf ("%lu is a prime.\n", num);
        printf ("Please enter another integer for analysis: ");
        printf ("Enter q to quit.\n");
    }
    printf ("Bye.\n");

    return 0;
}
