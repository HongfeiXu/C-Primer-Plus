#include <stdio.h>
int main (void)
{
    int min, max;       // 上限，下限

    printf ("Please enter the max: ");
    scanf ("%d", &max);
    printf ("Please enter the min: ");
    scanf ("%d", &min);
    printf ("    n  n^2     n^3\n");
    for (; min < max; min++)
    {
        printf ("%5d %5d %8d\n", min, min * min, min * min * min);
    }

    return 0;
}
