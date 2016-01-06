#include <stdio.h>
#define K1 3.78     // 3.78 升每加仑
#define K2 1.609    // 1.609 公里每英里
int main (void)
{
    double mile, gallon;
    double ans;

    printf ("Please enter mile number: \n");
    scanf ("%lf", &mile);
    printf ("Please enter gallon number: \n");
    scanf ("%lf", &gallon);
    ans = mile / gallon;
    printf ("%lf miles per gallon.\n", ans);
    gallon = gallon * K1;                // 升数
    mile = mile * K2;                    // 公里数
    ans = gallon / mile / 100;
    printf ("%lf liters per 100 kilometer.\n", ans);


    return 0;
}
