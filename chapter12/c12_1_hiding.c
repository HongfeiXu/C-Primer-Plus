/* hiding.c -- 代码块内的变量 */
#include <stdio.h>
int main (void)
{
	int x = 30;
	printf ("x in outer block: %d\n", x);
	{
		int x = 77;
		printf ("x in inner block: %d\n", x);
	}
	printf ("x in outer block: %d\n", x);
	while (x++ < 33)
	{
		int x = 100;
		x++;
		printf ("x in while loop: %d\n", x);
	}
	printf ("x in outer block: %d\n", x);

	return 0;
}
/*

[alex@EX chapter12]$ ./a.out 
x in outer block: 30
x in inner block: 77
x in outer block: 30
x in while loop: 101
x in while loop: 101
x in while loop: 101
x in outer block: 34

*/