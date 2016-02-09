/*
 *  编写一个打开两个文件的程序。可以使用命令行参数或者请求用户输入来获得文件名。
 *  a. 让程序打印第一个文件的第一行、第二个文件的第一行、第一个文件的第二行、第二个文件的第二行，依次类推，知道打印完行数较多的文件的最后一行。
 *  这里，我使用命令行来获得文件名
 *	
 * */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int main (int argc, char *argv[])
{
	FILE *f1, *f2;
	char line_1[SIZE];
	char line_2[SIZE];
	char *p1;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s filename filename\n", argv[0]);
		exit (1);
	}
	if ((f1 = fopen (argv[1], "r")) == NULL)
	{
		fprintf (stderr, "Can't open file %s\n", argv[1]);
		exit (2);
	}
	if ((f2 = fopen (argv[2], "r")) == NULL)
	{
		fprintf (stderr, "Can't open file %s\n", argv[2]);
		exit (2);
	}
    // 用 p1 记录fgets 的返回值，以继续对文件剩余部分的输出
	while ((p1 = fgets (line_1, SIZE, f1)) != NULL && fgets (line_2, SIZE, f2) != NULL)
	{
		fputs (line_1, stdout);
		fputs (line_2, stdout);
	}
	if (p1 != NULL) // 说明 f2 读完了，f1 没有读完
	{
		do
		{
			fputs (line_1, stdout);
		}while (fgets (line_1, SIZE, f1));
	}               
	else			// 说明 f1 读完了，f2 的情况不确定，需要再判断
		while(fgets (line_2, SIZE, f2) != NULL)
			fputs (line_2, stdout);
	fclose (f1);
	fclose (f2);

	return 0;
}
