/*
 *  编写一段程序，将一个字符、零个或多个文件名作为命令行参数。
 *  如果字符后没有参数跟随，程序读取标准输入文件。
 *  否则，程序依次打开每个文件，然后报告每个文件中该字符的出现次数。
 *  文件名和字符本身也与计数值一起报告。程序中包括错误检查，
 *  以确定参数数目是否正确和是否能打开文件。如果不能正确打开文件，
 *  程序要报告这一情况然后继续处理下一文件。
 *
 * */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	FILE *fp;
	char temp;
	int cnt_file;
	int cnt_char;       // 字符计数

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s character [filename]...\n", argv[0]);
		exit (1);
	}
	else if (argc == 2)
	{
		printf("Enter the character you want to search: \n");
		fp = stdin;     // 文件指针指向标准输入文件
		cnt_char = 0;
		while ((temp = getc (fp)) != EOF)   // 用 getc () 在输入流中取字符
		{
			if (temp == argv[1][0])
				cnt_char++;
		}
		printf ("file stdin has %d %c\n", cnt_char, argv[1][0]);
	}
	else 
	{
		cnt_file = argc - 2;        		// 待处理文件的数量
		for (int i = 0, cnt_char = 0; i < cnt_file; ++i)
		{
			if ((fp = fopen (argv[2 + i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open file %s\n", argv[2 + i]);
				exit (2);
			}
			while ((temp = getc (fp)) != EOF)
			{
				if (temp == argv[1][0])
					cnt_char++;
			}
			printf ("file %s has %d %c\n", argv[2 + i], cnt_char, argv[1][0]);
		}
	}

	return 0;
}

/*
[alex@EX chapter13]$ ./a.out 
Usage: ./a.out character [filename]...
[alex@EX chapter13]$ ./a.out c c13_1_count.c c13_2_reducto.c 
file c13_1_count.c has 21 c
file c13_2_reducto.c has 46 c
[alex@EX chapter13]$ ./a.out c
Enter the character you want to search: 
So, come on.
I need you to count how many c i
Just write 
file stdin has 3 c

*/
