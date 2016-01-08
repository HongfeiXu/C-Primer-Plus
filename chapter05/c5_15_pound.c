/* 定义带有一个参数的函数，函数功能：打印指定数目的英镑符号 */
#include <stdio.h>
void pound (int n);     /* ANSI 风格的原型               */
int main (void)
{
    int times = 5;
    char ch = '!';      /* ASCII 码值为33                */
    float f = 6.0;
    pound (times);      /* int 参数                      */
    pound (ch);         /* char 参数自动转换为 int 类型  */
    pound ((int) f);    /* cast 运算符把f强制转换为int   */

    return 0;
}



void pound (int n)
{
    while (n-- > 0)
        printf ("#");
    printf ("\n");
}
