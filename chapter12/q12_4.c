/*
 *  编写一个函数，它返回函数本身被调用的次数，并在一个循环中测试之。
 *
 * */
#include <stdio.h>
int call_me (void);
int main (void)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf ("I call function call_me () %2d times.\n", call_me ());
	}

	return 0;
}

int call_me (void)
{
	static int times = 0;		// 具有代码块作用域的静态变量

	return ++times;
}

/*

[alex@EX chapter12]$ ./a.out 
I call function call_me ()  1 times.
I call function call_me ()  2 times.
I call function call_me ()  3 times.
I call function call_me ()  4 times.
I call function call_me ()  5 times.
I call function call_me ()  6 times.
I call function call_me ()  7 times.
I call function call_me ()  8 times.
I call function call_me ()  9 times.
I call function call_me () 10 times.

*/
