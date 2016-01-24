/* day_mon2.c -- 让编译器计算元素的个数*/
#include <stdio.h>
int main (void)
{
    const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
    int index;

    for (index = 0; index < sizeof days / sizeof days[0]; index++)  // 通过sizeof计算数组长度
    {
        printf ("Month %2d has %d days\n", index + 1, days[index]);
    }


    return 0;
}

