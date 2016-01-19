#include <stdio.h>
#include <ctype.h>

int main (void)
{
    int ch;
    int cnt_lower, cnt_upper;

    cnt_lower = cnt_upper = 0;

    while ((ch = getchar()) != EOF)
    {
        if (islower (ch))
            cnt_lower++;
        else if (isupper (ch))
            cnt_upper++;
    }
    printf ("There are %d lower characters and %d upper characters in the input.\n", cnt_lower, cnt_upper);

    return 0;
}
