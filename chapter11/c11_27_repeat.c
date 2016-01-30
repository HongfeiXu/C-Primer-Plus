/* repeat.c -- 带有参数的 main () 函数 */
#include <stdio.h>
int main (int argc, char *argv[])
{
	int count;

	printf ("The command line has %d arguments: \n",
		argc - 1);
	for (count = 1; count < argc; count++)
	{
		printf ("%d: %s\n", count, argv[count]);
	}

	return 0;
}

/*

alex@EX chapter11]$ ./repeat Resistance is futile
The command line has 3 arguments: 
1: Resistance
2: is
3: futile
[alex@EX chapter11]$ ./a.out "hello world"
The command line has 1 arguments: 
1: hello world

*/