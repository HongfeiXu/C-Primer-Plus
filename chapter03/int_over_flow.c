// 超出您系统上的最大 int 值 p40
#include <stdio.h>
int main (void)
{
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf ("%d %d %d\n", i, i+1, i+2);     //发生溢出
    printf ("%u %u %u\n", j, j+1, j+2);     //发生溢出
    return 0;
}
