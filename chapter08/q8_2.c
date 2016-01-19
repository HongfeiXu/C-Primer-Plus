/*
 *  打印每个输入字符及其ASCII码的十进制值。
 *
 * */

#include <stdio.h>

int main (void)
{
    int ch;
    int count = 0;

    while ((ch = getchar ()) != EOF)
    {
        if (ch >= 32)
        {
            printf ("%c %d  ", ch, ch);
            count++;
        }
        else if (ch == '\n')
        {
            printf ("\\n %d  ", ch);
            count = 0;
        }
        else if (ch == '\t')
        {
            printf ("\\t %d  ", ch);
        }
        else
        {
            printf ("^%c %d  ", ch + 64, ch);
            count++;
        }
        if (count == 10)
        {
            putchar ('\n');
            count = 0;
        }

    }

    return 0;
}
