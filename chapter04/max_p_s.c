#include <stdio.h>
int main (void)
{
    char c[10];
    scanf ("%6s", c);       // 最大字段宽度，在达到最大字段宽度或者遇到第一个空白字符时，停止读取
    printf ("%s\n", c);     
    printf ("%.3s\n", c);   // 要打印的字符的最大宽度。

    return 0;
}
/*
The Result:

abcdefg
abcdef
abc

*/
