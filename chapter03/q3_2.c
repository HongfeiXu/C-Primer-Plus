/* 编写一个程序，要求输入一个ASCII码值，输出对应的字符 */
#include <stdio.h>
int main (void)
{
    unsigned short asc;

    printf ("Enter the code:___\b\b\b");
    scanf("%hu", &asc);
    printf ("\nThe character of %hu is %c.\n", asc, asc);

    return 0;
}
