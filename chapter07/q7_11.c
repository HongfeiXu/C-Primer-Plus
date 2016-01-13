#include <stdio.h>
#define ARTICHOKES 1.25
#define BEETS 0.65
#define CARROTS 0.89
#define DISCOUNT 0.05
int main (void)
{
    float arti_pd, beet_pd, carr_pd;    // 各种蔬菜的重量
    float heavy, total_cost, discount, ship_cost;        // 总重量，订单总金额，折扣，运费
    char choice;
    
    discount = 0.0;                     // 折扣赋值为0，方便后面总消费金额的计算

    printf ("----------------------------\n");
    printf ("Which vegetiable you want to buy?\n");
    printf ("a) artichoke       b) beet\n");
    printf ("c) carrpt          q) quit\n");
    printf ("----------------------------\n");
    while ((choice = getchar ()) != 'q')
    {
        switch (choice)
        {
            case 'a':
                printf ("How much arichoke you want to buy?\n");
                scanf ("%f", &arti_pd);
                getchar ();             // 接收 回车键      不然，while中的getchar()将读到 回车键，不能正确执行
                break;
            case 'b':
                printf ("How much beet you want to buy?\n");
                scanf ("%f", &beet_pd);
                getchar ();
                break;
            case 'c':
                printf ("How much carrpt you want to buy?\n");
                scanf ("%f", &carr_pd);
                getchar ();
                break;
            default:
                printf ("Please make the right choice!\n");
                getchar ();
                break;
        }
        printf ("----------------------------\n");
        printf ("Which vegetiable you want to buy next?\n");
        printf ("a) artichoke       b) beet\n");
        printf ("c) carrpt          q) quit\n");
        printf ("----------------------------\n");
    }
    printf ("\n-----------------------------------------------\n");
    // 单价
    printf ("The price of artichokes is $%.2f per pounds\n", ARTICHOKES);
    printf ("The price of beets is $%.2f per pounds\n", BEETS);
    printf ("The price of carrots is $%.2f per pounds\n", CARROTS);
    // 总磅数
    heavy = arti_pd + beet_pd + carr_pd;
    // 每种蔬菜的磅数，每种蔬菜的费用
    printf ("The pounds ordered is %.2f\n", heavy);
    printf ("%.2f pounds artichokes cost $%.2f\n", arti_pd, arti_pd * ARTICHOKES);
    printf ("%.2f pounds beets cost $%.2f\n", beet_pd, beet_pd * BEETS);
    printf ("%.2f pounds carrots cost $%.2f\n", carr_pd, carr_pd * CARROTS);
    // 订单的总费用
    total_cost = ARTICHOKES * arti_pd + BEETS * beet_pd + CARROTS * carr_pd;
    printf ("total cost of the order is $%.2f\n", total_cost);
    // 折扣（如果有的话）
    if (total_cost >= 100)
    {
        discount = total_cost * DISCOUNT;
        printf ("the discount is %.2f\n", discount);
    }
    // 运输费用
    if (heavy <= 5.0)
        ship_cost = 3.5;
    else if (heavy < 20)
        ship_cost = 10;
    else
        ship_cost = 8 + (heavy - 20) * 0.1;
    printf ("The shipping charge is %.2f\n", ship_cost);
    // 所有费用的总数
    printf ("The grand total of all the charges is %.2f\n", total_cost + ship_cost - discount);
    printf ("-----------------------------------------------\n");

    return 0;
}
