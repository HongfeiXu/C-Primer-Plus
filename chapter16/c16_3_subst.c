// subst.c -- 在字符串中进行替换
#include <stdio.h>
#define PSQR(x) printf ("The square of " #x " is %d.\n", ((x) * (x)));

int main (void)
{
	int y = 5;

	PSQR (y);
	PSQR (2 + 4);

	return 0;
}

/*

[alex@EX chapter16]$ ./a.out 
The square of y is 25.
The square of 2 + 4 is 36.

*/
