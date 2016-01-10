#include <stdio.h>
int main (void)
{
    int a[8];
    int i;
    int temp;

    for (i = 0, temp = 1; i < 8; i++)
    {
        temp *= 2;
        a[i] = temp;
    }
    i = 0;
    do
    {
        printf ("a[%d] = %d\n", i, a[i]);
    }while (++i < 8);

    return 0;
}
