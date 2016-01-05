/* 使用可变宽度的输出字段 */
#include <stdio.h>
int main (void)
{
    unsigned width, precision;          // 由变量width制定输出时字符宽度，由precision来指定精度
    int number = 256;
    double weight = 242.5;

    printf ("What field width?\n");
    scanf ("%d", &width);
    printf ("The number is: %*d: \n", width, number);
    printf ("Now enter a width and precision: \n");
    scanf ("%d %d", &width, &precision);
    printf ("Weight = %*.*f\n", width, precision, weight);

    return 0;
}

/*
The Result:

What field width?
6
The number is:    256: 
Now enter a width and precision: 
8 3
Weight =  242.500

*/
