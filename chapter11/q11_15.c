/*  
 *  编写一个程序，其功能是读取输入，知道遇见文件结尾，并把文件现实出来。
 *  要求程序可以识别并执行下面的命令参数：
 *  -p      按照原样现实输入
 *  -u      把输入全部转换为大写
 *  -l      把输入全部转换为小写
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
	int ch;
	FILE * fp;

	fp = fopen (argv[2], "r");
	if (fp == NULL)
	{
		printf ("Failed to open file. Bye\n");
		exit (1);
	}
	if (strcmp (argv[1], "-p") == 0)
	{
		while ((ch = getc (fp)) != EOF)
			putchar (ch);
	}
	else if (strcmp (argv[1], "-u") == 0)
	{
		while ((ch = getc (fp)) != EOF)
			putchar (toupper (ch));
	}
	else if (strcmp (argv[1], "-l") == 0)
	{
		while ((ch = getc (fp)) != EOF)
			putchar (tolower (ch));
	}
	else
		printf ("The argument you give is not right. Bye\n");

	return 0;
}

/*

[alex@EX chapter11]$ ./a.out -p tmp.c 
Hello World!
Yep!
I like coding![alex@EX chapter11]$ ./a.out -u tmp.c 
HELLO WORLD!
YEP!
I LIKE CODING![alex@EX chapter11]$ ./a.out -l tmp.c 
hello world!
yep!

*/