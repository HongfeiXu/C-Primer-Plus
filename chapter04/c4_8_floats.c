/* 一些浮点数的组合 */
#include <stdio.h>
int main (void)
{
    const double RENT = 3582.99;        // 以 const 方法定义一个常量
    
    printf ("*%f*\n", RENT);
    printf ("*%e*\n", RENT);
    printf ("*%4.2f*\n", RENT);
    printf ("*%3.1f*\n", RENT);
    printf ("*%10.3f*\n", RENT);
    printf ("*%10.3e*\n", RENT);
    printf ("*%+4.2f*\n", RENT);
    printf ("*%010.2f*\n", RENT);

    return 0;
}


/*
 * The Result:
 *
 *      *3582.990000*
 *      *3.582990e+03*
 *      *3582.99*
 *      *3583.0*
 *      *  3582.990*
 *      * 3.583e+03*
 *      *+3582.99*
 *      *0003582.99*
 *
 * */
