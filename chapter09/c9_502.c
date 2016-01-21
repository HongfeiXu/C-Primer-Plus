/* proto.c -- 使用函数原型 */
#include <stdio.h>

/* 在首次调用前进行完整的函数定义，通常对较小的函数会这样 */
int imax (int a, int b) { return a > b ? a : b; }  

int main (void)
{
    printf ("The maximum of %d and %d is %d.\n",
            3, 5, imax (3, 5));
    printf ("The maximum of %d and %d is %d.\n",
            3, 5, imax (3.0, 5.0));

    return 0;
}
