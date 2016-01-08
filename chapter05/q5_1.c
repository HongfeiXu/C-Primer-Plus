/* 将用分钟表示的时间转换成以小时和分钟表示的时间 */
#include <stdio.h>
#define MIN_PER_H 60        // 每小时60分钟
int main (void)
{
    int min;
    int h, m;

    printf ("Please enter a number of minutes (<= 0 to quit):\n");
    scanf ("%d", &min);
    while (min > 0)
    {
        h = min / MIN_PER_H;
        m = min % MIN_PER_H;
        printf ("%d minutes has %d hours and %d minutes.\n", min, h, m);
        printf ("Please enter another number of minutes (<= 0 to quit):\n");
        scanf ("%d", &min);
    }


    return 0;
}
