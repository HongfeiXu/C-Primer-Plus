/* r_drive0.c -- 测试 rand () 函数 */
/* 与 rand0.c 一起编译 */
#include <stdio.h>
extern int rand0 (void);

int main (void)
{
    int count;

    for (count = 0; count < 5; count++)
    {
        printf ("%hd\n", rand0 ());
    }

    return 0;
}

/*

[alex@EX chapter12]$ ./a.out 
16838
5758
10113
17515
31051

*/