#include <stdio.h>
int main (void)
{
    float f1, f2;

    printf ("Please enter 2 float numbers (q to quit):\n");
    while (scanf ("%f %f", &f1, &f2) == 2)          
    {
        printf ("(%f - %f) / (%f * %f) = %f\n", f1, f2, f1, f2, (f1 - f2) / (f1 * f2));
    }
    printf ("May you have a good time. Bye!\n");

    return 0;
}
