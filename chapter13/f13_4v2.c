/*
 *  编写一段程序。它不读取任何命令行参数或者读取一个命令行参数。
 *  如果有一个参数，程序将它作为一个输入文件名。
 *  如果没有参数，使用标准输入最为输入。假设输入完全由浮点数组成。
 *  让程序计算并且报告输入数字的算数平均值。
 *
 *  将每次读入的数直接加到 sum 中，而不将其再存入一个数组中。
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main (int argc, char *argv[])
{	
	FILE *in;
    double n;
	int cnt = 0;
	double sum = 0.0;

	// 定 in
	if (argc == 1)
		in = stdin;
	else if (argc == 2)  // 如果有一个参数，则将其作为文件名
	{
		if ((in = fopen (argv[1], "r")) == NULL)
		{
			fprintf (stderr, "Can't open file %s.\n", argv[1]);
			exit (1);
		}
	}
	else
	{
		fprintf (stderr, "Usage: %s [filename]\n", argv[0]);
		exit (2);
	}

	while (fscanf (in, "%lf", &n) == 1)    
    {
        cnt++;
        sum += n;
    }

	if (cnt > 0)
		fprintf(stdout, "The average of those numbers is %lf\n", sum / cnt);
	else
		fprintf (stdout, "No valid data.\n");

	return 0;
}
