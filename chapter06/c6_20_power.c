// power.c -- 计算数值的整数次幂
#include <stdio.h>
double power (double n, int p);     // ANSI 原型
int main (void)
{   
    double x, xpow;     // 数，和数的幂
    int exp;            // 幂

    printf ("Enter a number and the positive integer power");
    printf (" to which\nthe number will be raised. Enter q");
    printf (" to quit.\n");
    while (scanf ("%lf%d", &x, &exp) == 2)
    {
        xpow = power (x, exp);
        printf ("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf ("Enter the next pair of number or q to quit.\n");
    }
    printf ("Hope you enjoyed this power trip -- bye!\n");
    
    return 0;
}

double power (double n, int p)
{
    int i;
    double pow = 1.0;
    for (i = 1; i <= p; i++)
    {
        pow *= n;
    }

    return pow;
}
