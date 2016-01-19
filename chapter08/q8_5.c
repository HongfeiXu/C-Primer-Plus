/* 折半猜数 */
#include <stdio.h>
int main (void)
{
    int guess;
    char response;
    char response2;
    int low, high;

    low = 1, high = 100;
    guess = (low + high) / 2;

    printf ("Pick an integer from to 100. I will try to guess ");
    printf ("it.\nRespond with a y if my guess is right and with");
    printf ("\nan n if it is wrong.\n");
    printf ("Uh...is your number %d?\n", guess);
    while ((response = getchar ()) != 'y')
    {
        while (getchar () != '\n')
            continue;           // 跳过输入的剩余部分
        if (response == 'n')
        {
            printf ("Well, then, is this number less or more than yours?"
                    "\nRespond with a l if my guess is less a m if it is"
                    "\nmore.\n");
            if ((response2 = getchar ()) == 'l')    // 如果输入的既不是 l 也不是 m 则再一次大的 while 循环。 guess 的值不变
            {
                low = guess;
                guess = (low + high) / 2;
            }
            else if (response2 == 'm')
            {
                high = guess;
                guess = (low + high) / 2;
            }
            else
                printf ("Sorry, I understand only l or m.\n");
            while (getchar () != '\n')
                continue;           // 跳过输入的剩余部分
            printf ("Well, then, is it %d?\n", guess);
        }
        else
            printf ("Sorry, I understand only y or n.\n");
    }
    printf ("I knew I could do it!\n");

    return 0;
}
