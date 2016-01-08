#include <stdio.h>
int main (void)
{
    int a;
    int count = 11;

    printf ("Please enter a integer number:\n");
    scanf ("%d", &a);
    while (count-- > 0)
    {
        printf ("%d\t", a++);
    }
    printf ("\n");

    return 0;
}
