/* 指数增长 */
#include <stdio.h>
#define SQUARES 64      // 棋盘上方格数量
#define CROP 1E15       // 以粒计美国小麦的产量
int main (void)
{
    double current, total;
    int count = 1;

    printf ("square   grains       total        fraction of\n");
    printf ("         added        grain        US total\n");
    total = current = 1.0;      // 开始是一粒
    printf ("%3d %13.2e %12.2e %12.2e\n", count, current,
            total, total/CROP);
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        total = total + current;
        printf ("%3d %13.2e %12.2e %12.2e\n", count, current,
                total, total/CROP);

    }
    printf ("That's all.\n");


    return 0;
}
