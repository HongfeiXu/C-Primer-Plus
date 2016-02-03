/*
 *  编写一个程序，读取输入，直到读入了10个字符串或遇到EOF，由二者中最先被满足的那个终止读取过程。
 *  这个程序可以为用户提供一个有5个选项的菜单：
 *		1. 输出字符串列表           2. 按ASCII顺序输出字符串
 *	    3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串
 *	    5. 退出
 *  菜单可以循环，直到用户输入退出请求。
 *
 * */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 5
#define SIZE 81

void show_choice (void);
int get_int ();

void sort_by_ASCII (char *strings[], int num);
void sort_by_length (char *strings[], int num);
void sort_by_first (char *strings[], int num);

int main (void)
{
	char str[LIM][SIZE];
	char *ptstr[LIM];
	int choose;
	int ct = 0;
	int i;

	printf ("Enter %d lines:\n", LIM);	
	while (ct < LIM && gets (str[ct]) != NULL)
	{
		ptstr[ct] = str[ct];		// to protect str[]
		ct++;
	}
	show_choice ();	
	choose = get_int();	
	while (choose != 5)
	{
		switch (choose)
		{
			case 1:
			{
				puts ("输出字符串列表:");
				for (i = 0; i < ct; i++)
					puts (str[i]);
				break;
			}
			case 2:
			{
				sort_by_ASCII (ptstr, ct);
				puts ("ASCII顺序输出字符串:");
				for (i = 0; i < ct; i++)
					puts (ptstr[i]);
				break; 
			}
			case 3:
			{
				sort_by_length (ptstr, ct);
				puts ("按长度递增顺序输出字符串:");
				for (i = 0; i < ct; i++)
					puts (ptstr[i]);
				break;
			}
			case 4:
			{
				sort_by_first (ptstr, ct);
				puts ("按字符串中第一个单词的长度输出字符串:");
				for (i = 0; i < ct; i++)
					puts (ptstr[i]);
				break;
			}
			default:
			{
				puts ("Please enter a number which is bigger than 1 and smaller than 5.");
				break;
			}
		}
		show_choice ();
		choose = get_int ();
	}
	puts ("Bye!");

	return 0;
}

void sort_by_ASCII (char *strings[], int num)
{
	char *temp;
	int top, seek;
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strcmp (strings[top], strings[seek]) > 0)
			{
				temp = strings[seek];
				strings[seek] = strings[top];
				strings[top] = temp;
			}
}

void sort_by_length (char *strings[], int num)
{
	char *temp;
	int top, seek;
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
		{
			if (strlen (strings[top])> strlen (strings[seek]))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
}

void sort_by_first (char *strings[], int num)
{
	int first_len[num];
	char *temp;
	int count;
	int i;
	int top, seek;

	for (i = 0; i < num; i++)		// 计算每个字符串第一个单词的长度
	{
		count = 0;
		temp = strings[i];
		while (isblank (*temp) || ispunct (*temp))
		{
			temp++;
		}
		while (isalpha (*temp) || isdigit (*temp))
		{
			temp++;
			count++;
		}
		first_len[i] = count;
	}
	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (first_len[top] > first_len[seek])
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}

}

void show_choice (void)
{
		printf ("Make your choice:\n");
		printf ("*****************************************************\n");
		printf ("1. 输出字符串列表           2. 按ASCII顺序输出字符串\n");
	    printf ("3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串\n");
	    printf ("5. 退出\n");
		printf ("*****************************************************\n");
}

int get_int ()
{
	int input;
	char ch;

	while (scanf ("%d", &input) != 1)
	{
		while ((ch = getchar ()) != '\n')
			putchar (ch);
		printf (" is not an integer.\nPlease enter an integer value.\n");
	}
	return input;
}


/*

[alex@EX chapter11]$ ./a.out 
Enter 5 lines:
Hello world
What are you doing
I like it 
Make your choice:
*****************************************************
1. 输出字符串列表           2. 按ASCII顺序输出字符串
3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串
5. 退出
*****************************************************
1
输出字符串列表:
Hello world
What are you doing
I like it
Make your choice:
*****************************************************
1. 输出字符串列表           2. 按ASCII顺序输出字符串
3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串
5. 退出
*****************************************************
2
ASCII顺序输出字符串:
Hello world
I like it
What are you doing
Make your choice:
*****************************************************
1. 输出字符串列表           2. 按ASCII顺序输出字符串
3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串
5. 退出
*****************************************************
3
按长度递增顺序输出字符串:
I like it
Hello world
What are you doing
Make your choice:
*****************************************************
1. 输出字符串列表           2. 按ASCII顺序输出字符串
3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串
5. 退出
*****************************************************
4
按字符串中第一个单词的长度输出字符串:
I like it
What are you doing
Hello world
Make your choice:
*****************************************************
1. 输出字符串列表           2. 按ASCII顺序输出字符串
3. 按长度递增顺序输出字符串   4. 按字符串中第一个单词的长度输出字符串
5. 退出
*****************************************************
5
Bye!

*/
