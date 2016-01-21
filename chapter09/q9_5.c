#include <stdio.h>
void larger (double * x, double * y);

int main (void)
{
    double x = 10.2 ,y = -3.9;
    printf ("x = %lf, y = %lf\n", x, y);

    larger (&x, &y);
    printf ("x = %lf, y = %lf\n", x, y);

    return 0;
}


void larger (double * x, double * y)
{
    if (*x > *y)
        *y = *x;
    else 
        *x = *y;
}
