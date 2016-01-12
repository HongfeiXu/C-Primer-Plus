#include <stdio.h>
int main (void)
{
    char ch;
    int cnt = 0;          // 记录替代次数

    while ((ch = getchar ()) != '#')
    {
        if (ch == '.')
        {
            cnt++;
            printf ("%c", '!');
        }
        else if (ch == '!')
        {
            cnt++;
            printf ("%c%c", '!', '!');
        }
        else
            printf ("%c", ch);
    }
    printf ("\n");
    printf ("There are %d times change!\n", cnt);

    return 0;
}
