#include <stdio.h>
int main (void)
{
    float flo;

    scanf ("%f", &flo);

    printf ("a. The input is %2.1f or %.1e\n", flo, flo);
    printf ("b. The input is %+2.3f or %.3E\n", flo, flo);

    return 0;
}
