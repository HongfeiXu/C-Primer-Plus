/* paint.c -- 使用条件运算符 */
#include <stdio.h>
#define COVERAGE 200            /* 每罐油漆可喷的平方公尺数 */
int main (void)
{
    int sq_feet;
    int cans;

    printf ("Enter number of square feet to painted: \n");
    while (scanf ("%d", &sq_feet) == 1)
    {
        cans = sq_feet / COVERAGE;
        cans += ((sq_feet % COVERAGE == 0) ? 0 : 1 );
        printf ("You need %d %s of paint.\n", cans,
                cans == 1 ? "can" : "cans");
        printf ("Enter next value (q to quit): \n");
    }
    printf ("Bye\n");


    return 0;
}
