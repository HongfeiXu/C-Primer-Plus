#include <stdio.h>
int main (void)
{
    double a[8], b[8];
    int i;
    double temp;

    for (i = 0; i < 8; i++)
    {
        printf ("Please the %dth number in the a array: ", i + 1);
        scanf ("%lf", &a[i]);
    }
    for (temp = 0, i = 0; i < 8; i++)
    {
        temp += a[i];           // 保存a[0...i]的和
        b[i] = temp;
    }
    printf ("The array a[]: ");
    for (i = 0; i < 8; i++)
    {
        printf ("%8.3lf ", a[i]);
    }
    printf ("\n");
    printf ("The array b[]: ");
    for (i = 0; i < 8; i++)
    {
        printf ("%8.3lf ", b[i]);
    }
    printf ("\n");

    return 0;
}
