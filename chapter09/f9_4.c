/*
 * 设计一个实现两整数相加并返回结果的函数
 * */
#include <stdio.h>
int add (int a, int b);

int main (void)
{
    printf ("%d + %d = %d\n", 2, 3, add (2, 3));

    return 0;
}

int add (int a, int b)
{
    return a + b;
}
