#include <stdio.h>
int main (void)
{
    int num;
    int cnt_even, cnt_odd, sum_even, sum_odd;

    cnt_even = cnt_odd = sum_even = sum_odd = 0;

    while (scanf ("%d", &num) == 1 && num != 0)
    {
        switch (num % 2)
        {
            case 0:
                cnt_even++;
                sum_even += num;
                break;
            case 1:
                cnt_odd++;
                sum_odd += num;
                break;
        }
    }
    printf ("cnt_even = %d\nsum_even = %d\ncnt_odd = %d\nsum_odd=%d\n",
            cnt_even, sum_even, cnt_odd, sum_odd);

    return 0;
}
