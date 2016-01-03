/* 不正确的参数个数 */
#include <stdio.h>
int main (void)
{
    int f = 8;
    int g = 6;
    float h = 5.0f;

    printf ("%d\n", f, g);      // 参数太多
    printf ("%d %d\n", f);      // 参数太少
    printf ("%d %f\n", h, g);  // 值的类型不正确，显示垃圾值。

    return 0;
}
/*
 *
     [alex@EX chapter03]$ ./a.out 
     8
     8 908892064
     6 5.000000
    
 * */
