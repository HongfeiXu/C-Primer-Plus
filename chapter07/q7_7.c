#include <stdio.h>
#define FUNDEMENTAL 10.00       // 基本工资
#define ORDINARY 40             // 不加班时间节点
#define EXTRALTIME 1.5          // 加班的时间是平常的多少倍
#define FIRST_300 0.15          // 前300美元的汇率
#define NEXT_150 0.20           // 下一个150美元的汇率
#define REST 0.25               // 余下的汇率
int main (void)
{
 
    float time;
    float total_time;
    float total_money;
    float tax;

    printf ("Please enter your work time per week: ");
    scanf ("%f", &time);
    if (time < ORDINARY)
        total_time = time;
    else
        total_time = 40 + 1.5 * (time - 40);
    total_money = total_time * FUNDEMENTAL;
    if (total_money < 300)
        tax = total_money * FIRST_300;
    else if (total_money < 450)
        tax = 300 * FIRST_300 + (total_money - 300) * NEXT_150;
    else
        tax = 300 * FIRST_300 + 150 * NEXT_150 + (total_money - 450) * REST;
    printf ("total %f\ntax %f\nclean %f\n", total_money, tax, total_money - tax);

    return 0;
}
