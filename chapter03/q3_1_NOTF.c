/* 通过实验的方法观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况 */
#include <stdio.h>
#include <float.h>
int main (void)
{
    int i = 2147483647;     // 最大的 int 值
    
    printf ("i = %d\n", i);
    i++;                    // 上溢
    printf ("i = %d\n", i);
// NOT FINISH

    float f_max = FLT_MAX;  // 最大的 float 值
    printf ("f_max = %e\n", f_max);
    f_max *= 10;                // 上溢
    printf ("f_max = %e\n", f_max);

    float f_min = FLT_MIN;  // 最小的 float 值
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    f_min /= 10;
    printf ("f_min = %e\n", f_min);
    

    return 0;
}
