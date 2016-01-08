#include <stdio.h>
void cubic (float f);
int main (void)
{
    float fl;

    printf ("Enter a number: ");
    scanf ("%f", &fl);
    cubic(fl);

    return 0;
}

void cubic (float f)
{
    printf ("cubic of %f is %f.\n", f, f*f*f);
}

