/* rain.c -- 针对若干年的降水量数据，计算年降水总量、年降水平均量，以及月降水平均量 */
#include <stdio.h>
#define MONTHS 12
#define YEARS 5

int main (void)
{
    // 把数组初始化为2000年到2004年的降水数据
    const float rain[YEARS][MONTHS] = {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    int year, month;
    float subtot, total;

    printf (" YEAR     RAINFALL(inches) \n");
    for (year = 0, total = 0; year < YEARS; year++)
    {
        // 计算每一年的总降水量 subtot
        for (month = 0, subtot = 0; month < MONTHS; month++)
        {
            subtot += rain[year][month];
        }
        // 输出每年降水总量
        printf ("%5d%15.1f\n", 2000 + year, subtot);
        total += subtot;    // 所有年度的总降水量 total
    }
    // 计算并输出年平均降水量
    printf ("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
    printf ("MONTHLY AVERAGES: \n\n");
    printf (" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

    for (month = 0; month < MONTHS; month++)
    {
        // 计算每一个月的总降水量（在这五年之中）
        for (year = 0, subtot = 0; year < YEARS; year++)
        {
            subtot += rain[year][month];
        }
        // 计算并输出月平均降水量
        printf ("%4.1f ", subtot / 5);
    }
    printf ("\n");

    return 0;
}
