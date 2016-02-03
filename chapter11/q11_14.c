/*
 *  使用字符分类函数实现 atoi () 函数
 *
 * */
#include <stdio.h>
#include <ctype.h>
#define SIZE 10
int my_atoi (char *string);

int main (void)
{
	char str[SIZE];
	int ans;

	puts ("Enter your number:");
	gets (str);
	ans = my_atoi (str);
	printf ("Your number:\n%d\n", ans);

	return 0;
}

int my_atoi (char *string)
{
	int number = 0;
	char *ptr = string;

	while (isblank (*ptr))		// 跳过 空格符
		ptr++;
	while (isdigit (*ptr))      // 计算 整型值
	{
		number = number * 10 + *ptr - '0';
		ptr++;
	}

	return number;
}

/*

[alex@EX chapter11]$ ./a.out 
Enter your number:
123
Your number:
123
[alex@EX chapter11]$ ./a.out 
Enter your number:
  123
Your number:
123
[alex@EX chapter11]$ ./a.out 
Enter your number:
123.4
Your number:
123
[alex@EX chapter11]$ ./a.out 
Enter your number:
asdf123
Your number:
0
[alex@EX chapter11]$ ./a.out 
Enter your number:
123sd123
Your number:
123




*/