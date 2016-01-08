#include <stdio.h>
void Temperatures (double fa);
int main (void)
{
    double fa;
    int judge;
    printf ("Enter temperature in Fahrenheit(q to quit): ");
    judge = scanf ("%lf", &fa);      // !!!!!通过scanf的返回值来判断输入的是否为数字p81
    while (judge == 1)
    {
        Temperatures (fa);
        printf ("Enter temperature in Fahrenheit(q to quit): ");
        judge = scanf ("%lf", &fa);     

    }



    return 0;
}

void Temperatures (double fa)
{
    /*
     *  Celsius = 1.8 * Fahrenheit + 32.0
     *  Kelvin = Celsius + 273.16
     *
     * */
    const double MULT = 1.8;
    const double F2C = 32.0;
    const double C2K = 273.16;
    double cel, kel;

    cel = MULT * fa + F2C;
    kel = cel + C2K;
    printf ("Temperature in Fahrenheit is %.2f.\n", fa);
    printf ("Temperature in Celsius is %.2f.\n", cel);
    printf ("Temperature in Kelvin is %.2f.\n", kel);

}
