/* lethead1.c
 *
 * 编写一个在一行输出40个星号的函数，然后在一个程序中使用该函数打印一个简单的信头
 *
 *
 *
 */
#include <stdio.h>
#define NAME "GIGATHINK, INC"
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40

void starbar (void);    /* 声明函数原型 */

int main (void)
{
    starbar ();
    printf ("%s\n", NAME);
    printf ("%s\n", ADDRESS);
    printf ("%s\n", PLACE);
    starbar ();

    return 0;
}

void starbar (void)
{
    int count;

    for (count = 1; count <= 40; count++)
        putchar ('*');
    putchar ('\n');
}
