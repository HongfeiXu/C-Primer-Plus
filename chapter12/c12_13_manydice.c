// manydice.c -- 多次投骰子
// 与diceroll.c 一起编译
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "c12_12_diceroll.h"

int main (void)
{   
    int dice, roll;
    int sides;

    srand ((unsigned int) time (0));
    printf ("Enter the number of sides per die, 0 to stop.\n");
    while (scanf ("%d", &sides) == 1 && sides > 0)
    {
        printf ("How many dice?\n");
        scanf ("%d", &dice);
        roll = roll_n_dice (dice, sides);
        printf ("You have rolled a %d using %d %d-sided dice.\n",
            roll, dice, sides);;
        printf ("How many sides? Enter 0 to stop.\n");
    }
    printf ("The rollem() function was called %d times.\n",
        roll_count);
    printf ("GOOD FORTUNE TO YOU!\n");

    return 0;
}
/*

[alex@EX chapter12]$ ./a.out 
Enter the number of sides per die, 0 to stop.
6
How many dice?
2
You have rolled a 8 using 2 6-sided dice.
How many sides? Enter 0 to stop.
6
How many dice?
2
You have rolled a 7 using 2 6-sided dice.
How many sides? Enter 0 to stop.
7
How many dice?
2
You have rolled a 3 using 2 7-sided dice.
How many sides? Enter 0 to stop.
0
The rollem() function was called 6 times.
GOOD FORTUNE TO YOU!

*/
