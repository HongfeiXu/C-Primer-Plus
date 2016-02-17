// mac_arg.c -- 带有参数的宏
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf ("The result is %d.\n", X);

int main (void)
{
	int x = 4;
	int z;

	printf ("x = %d\n", x);
	z = SQUARE(x);
	printf ("Evaluating SQUARE(x): ");
	PR(z);
	z = SQUARE(2);
	printf ("Evaluating SQUARE(2): ");
	PR(z);
	printf("Evaluating SQUARE(x + 2): ");
	PR(SQUARE(x+2));
	printf ("Evaluating 100/SQUARE(2): ");
	PR(100/SQUARE(2));
	printf ("x is %d.\n", x);
	printf ("Evaluating SQUARE(++x): ");
	PR(SQUARE(++x));
	printf ("After incrementing, x is %x.\n", x);

	return 0;
}

/*

[alex@EX chapter16]$ ./a.out 
x = 4
Evaluating SQUARE(x): The result is 16.
Evaluating SQUARE(2): The result is 4.
Evaluating SQUARE(x + 2): The result is 14.
Evaluating 100/SQUARE(2): The result is 100.
x is 4.
Evaluating SQUARE(++x): The result is 36.
After incrementing, x is 6.

*/
