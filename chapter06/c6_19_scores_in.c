// scores_in.c -- 使用循环进行数组处理
#include <stdio.h>
#define SIZE 10
#define PAR 72          // 标准分
int main (void)
{
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf ("Enter %d golf scores: \n", SIZE);
    for (index = 0; index < SIZE; index++)
    {
        scanf ("%d", &score[index]);            // 读入10个分数
    }
    printf ("The scores read in are as follows: \n");
    for (index = 0; index < SIZE; index++)
    {
        printf ("%5d", score[index]);           // 验证输入
    }
    printf ("\n");
    for (index = 0; index < SIZE; index++)
    {
        sum += score[index];                    // 求它们的和
    }
    average = (float) sum / SIZE;
    printf ("Sum of scores = %d, average = %.2f\n", sum, average);
    printf ("That's a handicap of %.0f.\n", average - PAR);     // 差点（平均分与标准分之差）

    return 0;
}
