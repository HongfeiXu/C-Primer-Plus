/* hello.c -- 把命令行参数转换为数字 */
#include <stdio.h>
#include <stdlib.h>		// to use ato i

int main (int argc, char *argv[])
{
	int i, times;

	if (argc < 2 || (times = atoi (argv[1])) < 1)
		printf ("Usage: %s positive-number\n", argv[0]);
	else
		for (i = 0; i < times; i++)
			puts ("Hello, good looking!");

	return 0;
}

/*

[alex@EX chapter11]$ ./hello 3
Hello, good looking!
Hello, good looking!
Hello, good looking!
[alex@EX chapter11]$ ./hello a
Usage: ./hello positive-number
[alex@EX chapter11]$ ./hello -1
Usage: ./hello positive-number
[alex@EX chapter11]$ ./hello
Usage: ./hello positive-number
[alex@EX chapter11]$ 

*/