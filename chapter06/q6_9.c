#include <stdio.h>
int main (void)
{
    int lower, upper;
    int sum;
    int i;

    printf ("Enter lower and upper integer limits: ");
    scanf ("%d %d", &lower, &upper);
    
    while (lower < upper)
    {
        for (sum = 0, i = lower; i <= upper; i++)
            sum += i * i;
        printf ("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf ("Enter next set of limits: ");
        scanf ("%d %d", &lower, &upper);
    }
    printf ("Done\n");

    return 0;
}
