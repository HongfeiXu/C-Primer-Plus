/* 产生前20个整数的平方表 */
#include <stdio.h>
int main (void)
{
    int num = 1;
    while (num < 21)
    {
        printf ("%2d %3d = %d\n", num, num, num * num);
        num = num + 1;
    }

    return 0;
}
