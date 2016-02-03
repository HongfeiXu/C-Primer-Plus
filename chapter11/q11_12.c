/*
 *  编写一个程序，按照相反的单词顺序显示命令行参数。
 *
 * */
#include <stdio.h>

int main (int argc, char *argv[])
{
	int i;
	for (i = argc - 1; i >= 1; i--)
	{
		printf ("%s ", argv[i]);
	}
	printf ("\n");

	return 0;
}