/*
 *  编写一个程序，接受两个命令行参数。第一个参数为一个字符串;
 *  第二个为文件名。程序打印文件中包含字符串的所有行。
 *  使用标准C库函数 strstr () 在每一行搜索这些字符串。
 *
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256
int main (int argc, char *argv[])
{
	FILE *fp;
	char line[SIZE];

	if (argc != 3)
	{
		fprintf (stderr,"Usage: %s string filename\n", argv[0]);
		exit (1);
	}
	else
	{
		if ((fp = fopen (argv[2], "r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n", argv[2]);
			exit (1);
		}
		while (fgets (line, SIZE, fp) != NULL)
		{
			if (strstr (line, argv[1]) != NULL)
				fputs (line, stdout);
		}
	}

	return 0;
}

/*

[alex@EX chapter13]$ ./a.out include c13_2_reducto.c 
#include <stdio.h>
#include <stdlib.h>     // 为了调用 exit ()
#include <string.h>     // 为 strcpy () 和 strcat () 函数提供原型

*/