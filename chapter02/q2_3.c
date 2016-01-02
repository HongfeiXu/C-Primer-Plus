/* 编写一个程序，把您的年龄转化成天数并显示两者的值。
 * 不考虑平年（fractional year）和闰年（leap year）。*/
#include <stdio.h>
int main (void)
{
    int age = 22;
    printf ("I have lived %d days!\n", age * 365);

    return 0;
}
