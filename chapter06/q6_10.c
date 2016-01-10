#include <stdio.h>
int main (void)
{
    int num[8];
    int i;
    printf ("Please enter 8 numbers: \n");
    for (i = 0; i < 8; i++)
    {
        printf ("The %dth:", i + 1);
        scanf ("%d", &num[i]);
    }
    printf ("The array you input in reverse is :\n");
    for (i = 0; i < 8; i++)
    {
        printf ("%d\t", num[7-i]);
    }
    printf ("\n");

    return 0;
}
