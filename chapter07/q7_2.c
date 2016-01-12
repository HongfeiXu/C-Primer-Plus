#include <stdio.h>
int main (void)
{
    char ch;
    int count = 0;

    while ((ch = getchar ()) != '#')
    {
        if (ch == '\n')         // 跳过 '\n' 符号
            continue;
        printf ("\'%c\'=%3d ", ch, ch);
        count++;
        if (count % 8 == 0)
            printf ("\n");
    }
    printf ("\n");

    return 0;
}
