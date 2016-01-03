#include <stdio.h>
int main (void)
{
    float quart;

    printf ("Please enter quart of the water: ");
    scanf ("%f", &quart);
    printf ("There are %.3e molecules in the water.\n", quart * 950.0 / 3.0e-23);

    return 0;
}
