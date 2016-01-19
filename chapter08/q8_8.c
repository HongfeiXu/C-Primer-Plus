#include <stdio.h>
int main (void)
{
    char operation, ch;
    float first, second;

    printf ("Enter the operation of your choice:\n");
    printf ("a. add             s. subtract\n");
    printf ("m. multiply        d. divide\nq. quit\n");
    while ((operation = getchar ()) != 'q')
    {
        switch (operation)
        {
            case 'a':
            case 's':
            case 'm':
            case 'd':
                printf ("Enter first number: ");
                while (scanf ("%f", &first) != 1)   // 输入的不是浮点数，给予提示再输的机会    当输入 123asf 是有偏差
                {
                    while ((ch = getchar ()) != '\n')
                        putchar (ch);               // 剔除错误的输入
                    printf (" is not a number.");
                    printf ("Please enter a number, such as 2.5, -1.78E8, or 3: ");
                }
                printf ("Enter second number: ");
                while (scanf ("%f", &second) != 1)
                {   
                    while ((ch = getchar ()) != '\n')
                        putchar (ch);              
                    printf (" is not a number.");
                    printf ("Please enter a number, such as 2.5, -1.78E8, or 3: ");
                }
                break;
            default:
                printf ("Please enter the operation of your choice!\n");
                printf ("a. add             s. subtract\n");
                printf ("m. multiply        d. divide\nq. quit\n");
                continue;
        }
        if (operation == 'a')
            printf ("%.1f + %.1f = %.1f\n", first, second, first + second);
        else if (operation == 's')
            printf ("%.1f - %.1f = %.1f\n", first, second, first - second);
        else if (operation == 'm')
            printf ("%.1f * %.1f = %.1f\n", first, second, first * second);
        else
        {
            while (second == 0)         // 当被除数为0时，特殊处理，重新读入第二个数字
            {
                printf ("Enter a number other than 0: ");
                while (scanf ("%f", &second) != 1)  
                { 
                    while ((ch = getchar ()) != '\n')
                        putchar (ch);              
                    printf (" is not a number.");
                    printf ("Please enter a number, such as 2.5, -1.78E8, or 3: ");
                }
            }
            printf ("%.1f / %.1f = %.1f\n", first, second, first / second);
        }

    }


    return 0;
}
