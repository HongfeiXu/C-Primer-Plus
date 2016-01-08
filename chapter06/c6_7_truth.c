/* truth.c -- 哪些值为真？ */
#include <stdio.h>
int main (void)
{
    int n = 3;
    while (n)
        printf ("%2d is true\n", n--);
    printf ("%2d is false\n", n);
    n = -3;
    while (n)
        printf ("%2d is true\n", n++);
    printf ("%2d is false\n", n);

    return 0;
}

/*
 *  结论：
 *  只要while循环的判断条件的值非零，
 *  它就可以执行
 *
 * */
