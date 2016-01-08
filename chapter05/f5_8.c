/* 打印从 a 到 g的字母 */
#include <stdio.h>
int main (void)
{
    int count = 'a';

    while (count <= 'g')
    {
        printf ("%c\t", count);
        count++;
    }
    printf ("\n");

    return 0;
}
