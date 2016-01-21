/* hotel.c -- 旅馆管理函数 */
#include <stdio.h>
#include "hotel.h"

// 提供菜单，并提示用户输入选择，知道用户输入的符合要求（1-5数字）为止，返回用户的选择。
int menu (void)
{
    int code, status;

    printf ("\n%s%s\n", STARS, STARS);
    printf ("Enter the number of the desired hotel: \n");
    printf ("1) Fairfield Arms   2) Hotel olympic\n");
    printf ("3) Certworthy Plaza 4) The Stocktkon\n");
    printf ("5) quit\n");
    printf ("\n%s%s\n", STARS, STARS);
    while ((status = scanf ("%d", &code)) != 1 ||
            (code < 1 || code > 5))
    {
        if (status != 1)    // 说明输入的整型数字
            scanf ("%*s");  // 跳至下一个空白字符
        printf ("Enter an integer from 1 to 5, please.\n");
    }
    return code;
}

// 交互获取用户居住天数
int getnights (void)
{
    int nights;

    printf ("How many nights are needed?\n");
    while (scanf ("%d", &nights) != 1)
    {
        scanf ("%*s");
        printf ("Please enter an integer, such as 2.\n");
    }

    return nights;
}

// 计算并打印应付金额数
void showprice (double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;
/*
    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
        total += rate * factor;
*/
    for (n = 1; n <= nights; n++)
    {
        total += rate * factor;
        factor *= DISCOUNT;
    }
    printf ("The total cost will be $%0.2f.\n", total);

}
