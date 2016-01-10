#include <stdio.h>
#define RATE 0.08
#define WITHDRAW 10
int main (void)
{
    float sum = 100;
    int year_count;

    for (year_count = 0; sum > 0; year_count++)
    {
        sum += sum * RATE;
        sum -= WITHDRAW;
    }
    printf ("After %d years, He clear his account.\n", year_count);

    return 0;
}
