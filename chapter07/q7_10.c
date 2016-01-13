#include <stdio.h>
#define FIRST_RATE 0.15
#define NEXT_RATE 0.28
#define BACHELOR 17850
#define OWNER 23900
#define MARRIED 29750
#define DIVORCED 14875
int main (void)
{
    float income, tax, first;           // first 第一部分税率的界限值
    int type;

    printf ("Please enter your income(q to quit): $");
    while (scanf ("%f", &income) == 1)
    {
        first = 0;                      // first 赋值为0，用于下面的判断
        printf ("------------------------------------------\n");
        printf ("Which tax type ?\n");
        printf ("1) BACHELOR        2) OWNER\n");
        printf ("3) MARRIED         4) DIVORCED\n");
        printf ("5) quit\nType: ");
        scanf ("%d", &type);
        printf ("------------------------------------------\n");
        switch (type)
        {
            case 1:
                first = BACHELOR;
                break;
            case 2:
                first = OWNER;
                break;
            case 3:
                first = MARRIED;
                break;
            case 4:
                first = DIVORCED;
                break;
            case 5:
                printf ("\nBye!\n");
                return 0;
            default:
                printf ("You do not enter the right number!\n");
                break;
        }
        if (first != 0)         // first 被正确赋值，否则说明 switch 到了 deault，故不需要计算 tax
        {
             if (income < first)
                tax = income * FIRST_RATE;
            else
                tax = first * FIRST_RATE + (income - first);
            printf ("The tax you need to pay is $%.2f\n\n", tax);
            printf ("Please enter your income(q to quit): $");
        }
    }
    printf ("\nBye!\n");
    
    return 0;
}
