#include <stdio.h>
#include <stdbool.h>
bool is_prime (int num);      // 判断 num 是否为prime
int main (void)
{
    int num;
    int i;

    printf ("Please enter a integer(q to quit): ");
    while (scanf ("%d", &num))
    {
        printf ("analysis your number %d\n", num);
        for (i = 2; i <= num; i++)
        {
            if (is_prime (i))
            {
                printf ("%d\t", i);
            }
        }
        printf ("\nThe next number(q to quit): ");
    }
    printf ("\nBye!\n");

    return 0;
}

bool is_prime (int num)
{
    int i;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}
