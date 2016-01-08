#include <stdio.h>
#define DAY_PER_WEEK 7
int main (void)
{
    int day;
    int we, da;

    printf ("Please enter a number of days.(<= 0 to quit)\n");
    scanf ("%d", &day);
    while (day > 0)
    {
        we = day / DAY_PER_WEEK;
        da = day % DAY_PER_WEEK;
        printf ("%d days has %d weeks and %d days.\n", day, we, da);
        printf ("Please enter another number of days.(<= 0 to quit)\n");
        scanf ("%d", &day);
    }

    return 0;
}
