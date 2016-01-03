/* 说明舍入误差 P50*/
#include <stdio.h>
int main(void)
{
    float a, b;

    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf ("a = %f \n", a);
    printf ("b = %f \n", b);

    return 0;
}

