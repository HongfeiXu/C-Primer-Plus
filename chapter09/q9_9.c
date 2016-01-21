#include <stdio.h>
void to_base_n (unsigned long num, int base);

int main (void)
{   
    unsigned long number;
    int base;
    printf ("Enter an integer and the base you wannt (q to quit):\n");
    printf ("The range of base number is 2 ~ 10\n");
    while (scanf ("%lu %d", &number, &base) == 2)
    {
        to_base_n (number, base);
        putchar ('\n');
        printf ("Enter an integer and the base you wannt (q to quit):\n");
        printf ("The range of base number is 2 ~ 10\n");
    }
    printf ("Bye.\n");

    return 0;
}


// 将10进制转化为base进制
void to_base_n (unsigned long num, int base)
{
    int r;

    r = num % base;
    if (num >= base)
        to_base_n (num / base, base);
    putchar ('0' + r);
}
