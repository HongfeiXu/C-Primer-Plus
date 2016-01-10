// chcount.c -- 使用逻辑与运算符
// 计算在一个输入的句子中除单引号和双引号以外的字符出现了多少次。
#include <stdio.h>
#define PERIOD '.'          // 用'.'来标识一个句子的结束
int main (void)
{
    int ch;
    int charcount = 0;
    
    while ((ch = getchar ()) != PERIOD)
    {
        if (ch != '\'' && ch != '\"')
            charcount++;
    }

    printf ("There are %d non-quote characters.\n", charcount);

    return 0;
}
