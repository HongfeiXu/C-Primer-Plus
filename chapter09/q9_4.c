#include <stdio.h>
double fun (double x, double y);

int main (void)
{
    double x = 2.1, y = 31.2;

    printf ("fun (%lf, %lf) = %lf\n", x, y, fun (x, y));

    return 0;
}

double fun (double x, double y)
{
    double ans;

    ans = 1 / ((1/x + 1/y) / 2);

    return ans;
}
