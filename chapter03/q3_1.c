/* 通过实验的方法观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况 */
#include <stdio.h>
int main (void)
{
    int i = 2147483647;     // 最大的 int 值
    
    printf ("i = %d\n", i);
    i++;                    // 上溢
    printf ("i = %d\n", i);
/* 未完成。。。。。。。。。。。。 */

    return 0;
}
