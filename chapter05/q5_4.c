#include <stdio.h>
#define CM_PER_INCH 2.54        // 每英寸2.54厘米
#define INCH_PER_FEET 12        // 每英尺12英寸
int main (void)
{
    float cm, inch;
    int feet;

    printf ("Enter a height in centimeters: ");
    scanf ("%f", &cm);
    while (cm > 0)
    {
        
        inch = cm / CM_PER_INCH;                 // total inch
        feet = (int)inch /  INCH_PER_FEET;       // feet
        inch = inch - INCH_PER_FEET * feet;      // left inch 
        printf ("%.1f cm = %d feet, %.1f inches\n", cm, feet, inch);
        printf ("Enter a height in centimeters: ");
        scanf ("%f", &cm);

    }
    printf ("bye\n");
    return 0;
}
