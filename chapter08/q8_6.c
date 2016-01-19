/* get_first () 函数，返回所遇到的第一个非空白字符 */

#include <stdio.h>
#include <ctype.h>
char get_first (void);

int main (void)
{
    char fir;

    fir = get_first ();

    printf ("fir = %c\n", fir);

    return 0;
}

char get_first (void)
{
    char ch;

    while (isspace (ch = getchar ()))
        continue;       // 跳过所有空白符，知道第一个非空白符
    while (getchar () != '\n')
        continue;       // 跳过此行剩余的字符

    return ch;

}
