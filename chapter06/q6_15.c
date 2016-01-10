#include <stdio.h>
#define SINGLE_RATE 0.1
#define COMPOUND_RATE 0.05
int main (void)
{
    int year_count;
    double sum_da = 100;        // 单利
    double sum_de = 100;        // 复利
    
    for (year_count = 0; sum_da >= sum_de; year_count++)
    {
        sum_da += 100 * SINGLE_RATE;
        sum_de += sum_de * COMPOUND_RATE;
    }
    printf ("After %d years, Deiredre has $%.2lf, Daphne has $%.2lf.\n", year_count, sum_de, sum_da);

    return 0;
}
