/* 一些格式标志的使用示例 */
#include <stdio.h>
int main (void)
{   
    printf ("%x %X %#x\n", 31, 31, 31);
    printf ("**%d**% d**% d**\n", 42, 42, -42);
    printf ("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);


    return 0;
}
/*
 *  The Result:
 *  警告：‘0’标记 与 精度 和‘%d’gnu_printf 格式字符串合用时被忽略
 *  1f 1F 0x1f
 *  **42** 42**-42**
 *  **    6**  006**00006**  006**
 *
 * */
