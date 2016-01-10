/* electric.c -- 计算用电帐目 */
#include <stdio.h>
#define RATE1 0.12589       // 第一个 360kWh 的费率
#define RATE2 0.17901       // 下一个 320kWh 的费率
#define RATE3 0.20971       // 超过 680 kWh 的费率
#define BREAK1 360.0        // 费率的第一个分界点
#define BREAK2 680.0        // 费率的第二个分界点
#define BASE1 (RATE1 * BREAK1)                      // 用电 360kWh 的费用
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1))) // 用电 680kWh 的费用

int main (void)
{
    double kwh;         // 用电的 kwh 数
    double bill;        // 费用

    printf ("Please enter the kwh used.\n");
    scanf ("%lf", &kwh);
    if (kwh <= BREAK1)                          // 用电量低于 360
        bill = kwh * RATE1; 
    else if (kwh <= BREAK2)                     // 用电量在 360 到 680 之间
        bill = BASE1 + (kwh - BREAK1) * RATE2;       
    else                                        // 用电量高于 680
        bill = BASE2 + (kwh - BREAK2) * RATE3;
    printf ("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);

    return 0;
}
