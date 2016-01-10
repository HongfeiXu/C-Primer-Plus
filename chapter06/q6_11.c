#include <stdio.h>
int main (void)
{
    int times;
    double sum1, sum2;
    int i;
    
    printf ("Please enter how many times you want (q to quit): ");
    while(scanf ("%d", &times) == 1)
    {
        for (sum1 = 0, i = 1; i <= times; i++)
        {
            sum1 += 1.0 / (double)i; 
        }
        for (sum2 = 0, i = 1; i <= times; i++)
        {
            if (i % 2 == 1)
                sum2 += 1.0 / (double) i;
            else
                sum2 -= 1.0 / (double) i;
        }
        printf ("sum1 = %lf\nsum2 = %lf\n", sum1, sum2);
        printf ("Please enter the next times you want (q to quit): ");
    }
    printf ("May you have a nice time, bye!\n");

    return 0;
}
