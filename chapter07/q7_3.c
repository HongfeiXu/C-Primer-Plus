#include <stdio.h>
int main (void)
{
    int num;
    int cnt_even = 0;           // 出现次数
    int cnt_odd = 0;
    int sum_even = 0;           // 和
    int sum_odd = 0;

    printf ("Please enter some numbers(0 to quit)\n");
    while (scanf ("%d", &num) && num != 0)
    {
        if (num % 2 == 0)   
        {
            cnt_even++;
            sum_even += num;
        }
        else
        {
            cnt_odd++;
            sum_odd += num;
        }
    }
    printf ("There are %d number of even, %d number of odd.\n", cnt_even, cnt_odd);
    printf ("The average of even number is %f\n", (float) sum_even / (float) cnt_even);
    printf ("The average of odd number is %f\n", (float) sum_odd / (float) cnt_odd);

    return 0;
}
