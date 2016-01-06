#include <stdio.h>
#include <float.h>
int main (void)
{
    double num1 = 1.0/3.0;
    float num2 = 1.0/3.0;

    printf ("%.4f\n", num1);
    printf ("%.12f\n", num1);
    printf ("%.16f\n", num1);
    printf ("%.4f\n", num2);
    printf ("%.12f\n", num2);
    printf ("%.16f\n", num2);

    printf ("FLT_DIG = %d\n", FLT_DIG);     // float 类型最少有效数字位数
    printf ("DBL_DIG = %d\n", DBL_DIG);     // double 类型最少有效数字位数


    return 0;
}
/*
The Result:

0.3333
0.333333333333
0.3333333333333333
0.3333
0.333333343267
0.3333333432674408
FLT_DIG = 6
DBL_DIG = 15

*/
