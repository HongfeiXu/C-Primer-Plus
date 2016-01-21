#include <stdio.h>
#define BLANK ' '
void chline (char ch, int i, int j);

int main (void)
{
    char ch = getchar ();

    chline (ch, 2, 8);
    putchar ('\n');

    return 0;
}

void chline (char ch, int i, int j)
{
    j = j - i;
    while (--i >= 0)
        putchar (BLANK);
    while (--j >= 0)
        putchar (ch);
}
