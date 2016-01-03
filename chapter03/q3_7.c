#include <stdio.h>
int main (void)
{
    float height;

    printf ("Please enter your height in cm: ");
    scanf ("%f", &height);
    printf ("So, you are %.3f hight in inch.\n", height / 2.54);

    return 0;
}
