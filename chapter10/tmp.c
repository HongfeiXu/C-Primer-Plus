#include <stdio.h>
int main (void)
{

    int n = 5;
    double x;

    int * pi = &n;
    double * pd = &x;
    pd = pi;

    printf ("%f\n", *pd);
    return 0;
}

