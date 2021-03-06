/* sort_str.c -- 读进一些字符串并对它们排序

程序的技巧在于它并不是重新安排字符串本身，而仅仅重新安排指向字符串的指针。

 */
#include <stdio.h>
#include <string.h>
#define SIZE 81								// 字符串长度限制，包括 '\0'
#define LIM 20                              // 最多读入的行数
void stsrt (char * strings[], int num);     // 字符串排序函数

int main (void)
{
	char input[LIM][SIZE];                  // 存储输入的数组
	char *ptstr[LIM];                       // 指针变量的数组

	int ct = 0;                             // 输入计数
	int k;                                  // 输出计数

	printf ("Input up to %d lines, and I will sort them.\n", LIM);
	printf ("To stop, press the Enter key at a line's start.\n");
	while (ct < LIM && gets (input[ct]) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];	            // 另指针指向字符串
		ct++;
	}
	stsrt (ptstr, ct);                  
	puts ("\nHere's the sorted list: \n");
	for (k = 0; k < ct; k++)
    	puts (ptstr[k]);                    // 排序后的指针

	return 0;
}


/* 字符串-指针-排序函数 （选择排序）*/
void stsrt (char * strings[], int num)
{
	char *temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
	{
		for (seek = top + 1; seek < num; seek++)
		{
			if (strcmp (strings[top], strings[seek]) > 0)
			{
				temp = strings[top];        // 对指针进行交换
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}
