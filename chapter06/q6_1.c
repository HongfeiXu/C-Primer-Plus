#include <stdio.h>
int main (void)
{
    char a[26];
    char i;
    int j;

    for (i = 'a', j = 0; i <= 'z' ; i++, j++)
        a[j] = i;
    for (j = 0; j < 26; j++)
        printf ("a[%d] = %c\n", j, a[j]);

    return 0;
}
