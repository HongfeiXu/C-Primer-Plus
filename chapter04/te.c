#include <stdio.h>
int main (void)
{
    char a[10] = "hello, wo";
    float f = 12.0;
    long double d = 123124.9213;
    double dd = 1231.1231;


    printf ("dd = %f\n", dd);
    printf ("d = %Lf\n", d);
    printf ("%.3s\n", a);
    printf ("%4.0f\n", f);
    printf ("%.4d\n", 114);
    return 0;
}
