/*
 *  编写一段程序。它接受两个命令行参数，第一个是一个字符，第二个是文件名。
 *  要求程序只打印文件中包含给定字符的那些行。
 *
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

int main (int argc, char *argv[])
{
	FILE *fp;
	char line[MAX];


	if (argc != 3)
	{
		fprintf (stderr, "Usage: %s character filename\n", argv[0]);
		exit (1);
	}
	if ((fp = fopen (argv[2], "r")) == NULL)
	{
		fprintf (stderr, "Can't open file: %s", argv[2]);
		exit (2);
	}
	while (fgets (line, MAX, fp) != NULL)
	{
		// 用 strchr 在字符串中搜索字符，若存在则返回该字符指针，不存在则返回 NULL
		if (strchr (line, argv[1][0]) != NULL)  
			fputs (line, stdout);               // 输出被选中的行
	}

	return 0;
}

/*

[alex@EX chapter13]$ ./a.out c c13_2_reducto.c 
// reducto.c -- 把您的文件压缩为原来的三分之一
#include <stdio.h>
#include <stdlib.h>     // 为了调用 exit ()
#include <string.h>     // 为 strcpy () 和 strcat () 函数提供原型
int main (int argc, char *argv[])
	int ch;
	char name[LEN];     // 用于存储输入文件名
	int count = 0;
	if (argc != 2)
		fprintf (stderr, "I couldn't open the file \"%s\"\n",
	strcpy (name, argv[1]); // 把文件名复制到数组
	strcat (name, ".red");  // 在文件名后添加 .red
		fprintf (stderr, "Can't create output file.\n");
	while ((ch = getc (in)) != EOF)
		if (count++ % 3 == 0)
			putc (ch, out); // 打印每3个字符中的1个
	if (fclose (in) != 0 || fclose (out) != 0)
		fprintf (stderr, "Error in closing files.\n");

*/
