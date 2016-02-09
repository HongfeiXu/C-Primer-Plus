/*
 *  编写一段程序。它不读取任何命令行参数或者读取一个命令行参数。
 *  如果有一个参数，程序将它作为一个输入文件名。
 *  如果没有参数，使用标准输入最为输入。假设输入完全由浮点数组成。
 *  让程序计算并且报告输入数字的算数平均值。
 *
 *  将读入的 double 值存入一个数组中，之后在对数组中的值求和。不如法2来的简单。
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main (int argc, char *argv[])
{	
	FILE *in;
	double arr[MAX];
	int i = 0;
	int len;
	double sum;

	if (argc == 2)  // 如果有一个参数，则将其作为文件名
	{
		if ((in = fopen (argv[1], "r")) == NULL)
		{
			fprintf (stderr, "Can't open file %s.\n", argv[1]);
			exit (1);
		}
        // 将文件中数据读入数组中
		while (fscanf (in, "%lf", &arr[i]) == 1)    
			i++;
	}
	else if (argc == 1)           // 如果没有参数，使用标准输入作为输入。
	{
		fprintf (stdout, "Enter your double numbers, and enter q to quit:\n");
		while (fscanf (stdin, "%lf", &arr[i]) == 1)
			i++;
	}
	else
	{
		fprintf (stderr, "Usage: %s [filename]\n", argv[0]);
		exit (1);
	}

	len = i;
    // 计算数组的和
	for (i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	if (len > 0)
		fprintf(stdout, "The average of those numbers is %lf\n", sum / len);
	else
		fprintf (stdout, "No valid data.\n");

	return 0;
}
