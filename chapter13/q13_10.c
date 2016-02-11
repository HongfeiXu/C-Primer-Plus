/*
 *  编写一个程序，打开一个文本文件，文件名通过交互方式获得。
 *  建立一个循环，请求用户输入一个文件位置。（此处位置从 0 开始到 file_legth - 1）
 *  然后程序打印文件从该位置到下一换行符之间的部分。
 *  用户通过输入非数字字符来终止循环。
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
int main (void)
{
	FILE *fp;
	char ch;
	long pos;
	long file_length = 0;
	char file_name[SIZE];

	puts ("Enter the file name: ");
	gets (file_name);

	if ((fp = fopen (file_name, "r")) == NULL)
	{
		fprintf (stderr, "Can't open the file %s\n", file_name);
		exit (1);
	}
	else
	{
		while ((ch = getc (fp)) != EOF) // 统计文件字符数
		{
			file_length++;          
		}
		rewind (fp);                    // 回到文件开始处
		puts ("Enter the postion you want to search (q to quit)");
		while (scanf ("%ld", &pos) == 1)
		{
			if (pos >= file_length)
			{
				printf ("Sorry, there are %ld characters in file %s, you can give a smaller number.\n", 
					file_length, file_name);
				printf ("0 ~ %ld\n", file_length - 1);
				continue;
			}
			else
			{
				fseek (fp, pos, SEEK_SET);
				while ((ch = getc (fp)) != '\n' && ch != EOF)		// 若遇到文件结尾，也要结束输出。这很重要
					putchar (ch);
				putchar ('\n');
				rewind (fp);
			}
		}
	}
	puts ("Bye!");


	return 0;
}


/*

[alex@EX chapter13]$ ./a.out 
Enter the file name: 
c13_1_count.c
Enter the postion you want to search (q to quit)
722
turn 0;
723
urn 0;
733
Sorry, there are 733 characters in file c13_1_count.c, you can give a smaller number.
0 ~ 732
732

731

730
}
q
Bye!



*/
