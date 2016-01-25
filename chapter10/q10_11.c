/* rain.c -- 针对若干年的降水量数据，计算年降水总量、年降水平均量，以及月降水平均量 */
#include <stdio.h>
#define MONTHS 12
#define YEARS 5
void show_year_rain (int rows, int cols, const double arr[rows][cols]);
void show_average_year_rain (int rows, int cols, const double arr[rows][cols]);
void show_average_month_rain (int rows, int cols, const double arr[rows][cols]);

int main (void)
{
    // 把数组初始化为2000年到2004年的降水数据
    const double rain[YEARS][MONTHS] = {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    double subtot, tot;
    int year, month;

    show_year_rain (YEARS, MONTHS, rain);
    show_average_year_rain (YEARS, MONTHS, rain);
    show_average_month_rain (YEARS, MONTHS, rain);

    return 0;
}

void show_year_rain (int rows, int cols, const double arr[rows][cols])
{
    int year, month;
    double year_rain;

    for (year = 0; year < rows; year++)
    {
        for (month = 0, year_rain = 0; month < cols; month++)
        {
            year_rain += arr[year][month];
        }
        printf("%5d%15.1f\n", 2000 + year, year_rain);
    }
}

void show_average_year_rain (int rows, int cols, const double arr[rows][cols])
{
    int year, month;
    double tot;
    for (year = 0, tot = 0; year < rows; year++)
        for (month = 0; month < cols; month++)
            tot += arr[year][month];
    printf("The yearly average is %.1f inches.\n", tot / rows);
}

void show_average_month_rain (int rows, int cols, const double arr[rows][cols])
{
    double month_rain;
    int year, month;

    printf("Monthly averages:\n");
    printf (" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    for (month = 0, month_rain = 0.0; month < cols; month++)
    {
        for (year = 0; year < rows; year++)
            month_rain += arr[year][month];
        printf ("%4.1f ", month_rain / 5);

    }
    putchar ('\n');
}